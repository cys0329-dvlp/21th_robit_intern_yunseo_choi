import numpy as np
from copy import deepcopy

import torch 
import torch.nn as nn
import torch.optim as optim
import torch.nn.functional as F #ReLU 함수 가져오기 위함 
from torch.utils.data import DataLoader
from torch.utils.data import random_split # 학습 데이터에서 검증 세트 분리하기 위함 
from torchvision import datasets, transforms
import matplotlib.pyplot as plt 
from tqdm import tqdm

torch.manual_seed(0)
device = torch.device('cuda' if torch.cuda.is_available() else "cpu")

#--------------Load MNIST Dataset-------------------

print("Loading MNIST dataset...")
#처음엔 절대 경로로 하나씩 넣어줬다가 상대 경로로 쓰기 위해 data에 
transform = transforms.ToTensor() # 0~255 => 0~1 사이 값으로 정규화 
full_train_dataset = datasets.MNIST("data", train=True, download=True, transform=transform)
test_dataset = datasets.MNIST("data", train=False, download=True, transform=transform)

# 학습 데이터 => 55000개 학습, 5000개 검증 
validation_size = 5000
if len(full_train_dataset) <= validation_size:
    raise ValueError(f"Need more than {validation_size} training samples, got {len(full_train_dataset)}")

split_generator = torch.Generator().manual_seed(0)
train_subset, val_subset = random_split(
    full_train_dataset,
    [len(full_train_dataset) - validation_size, validation_size],
    generator=split_generator,
)

# Create data loaders
batch_size = 128 #한번에 처리하는 이미지 양
train_loader = DataLoader(train_subset, batch_size=batch_size, shuffle=True) #학습할 때만 suffle 쓰고 검증이나 테스트할 때는 굳이 할 필요 없음(가중치를 학습시키지않기 때문)
val_loader = DataLoader(val_subset, batch_size=batch_size, shuffle=False)
test_loader = DataLoader(test_dataset, batch_size=batch_size, shuffle=False)
print(f"Data split: {len(train_subset)} training, {len(val_subset)} validation, "f"{len(test_dataset)} test samples")

class MLP(nn.Module):
    def __init__(self, input_size=784, hidden_size1=256, hidden_size2=128, num_classes=10):
        super(MLP, self).__init__()
        
        #Layer 1: 784 × 256 + 256 = 200,960 parameters
        #Layer 2: 256 × 128 + 128 = 32,896 parameters
        #Layer 3: 128 × 10 + 10 = 1,290 parameters
        #Total: 235,146 parameters
        
        self.fc1 = nn.Linear(input_size, hidden_size1) #input = 784개, hidden1 = 256개 
        self.fc2 = nn.Linear(hidden_size1, hidden_size2) #input = 256개, hidden2 = 128개
        self.fc3 = nn.Linear(hidden_size2, num_classes) #input = 128개, num = 10개
        
        # Dropout: traing 과정에서 20% 확률로 출력을 0으로 만듦 
        # =>  특정 뉴런에 모델의 과적합(과도하게 의존)현상을 방지하기 위함
        self.dropout = nn.Dropout(0.2)
        
    def forward(self, x):
        
        #flatten 기능 
        x = x.view(x.size(0), -1)
        
        # Layer 1
        x = self.fc1(x)
        x = F.relu(x)
        x = self.dropout(x)
        
        # Layer 2
        x = self.fc2(x)
        x = F.relu(x)
        x = self.dropout(x) 
        
        # output Layer
        x = self.fc3(x)
        
        return x

#모델 생성
model = MLP().to(device)

# Print model summary
total_params = sum(p.numel() for p in model.parameters())
trainable_params = sum(p.numel() for p in model.parameters() if p.requires_grad)

print("Model Architecture:")
print(model)
print(f"\nTotal parameters: {total_params:,}")
print(f"Trainable parameters: {trainable_params:,}")

#비용 함수
criterion = nn.CrossEntropyLoss()

#optmizer
optimizer = optim.Adam(model.parameters(), lr=0.001)

# Learning rate scheduler
scheduler = optim.lr_scheduler.StepLR(optimizer, step_size=5, gamma=0.5)

# Training parameters
num_epochs = 5

# Storage for metrics
train_losses = []
train_accuracies = []
val_losses = []
val_accuracies = []

# Print configuration
print("Training Configuration:")
print(f"  Loss Function: CrossEntropyLoss")
print(f"  Optimizer: Adam (lr={0.001})")
print(f"  Scheduler: StepLR (step_size=5, gamma=0.5)")
print(f"  Number of epochs: {num_epochs}")
print(f"  Batch size: {batch_size}")
print("\nTraining setup complete!")

def train_epoch(model, device, train_loader, optimizer, criterion, epoch):
    
    model.train()
    train_loss = 0
    correct = 0
    total = 0
    
    pbar = tqdm(train_loader, desc=f'Epoch {epoch}')
    for batch_idx, (data, target) in enumerate(pbar):
        data, target = data.to(device), target.to(device)
        
        # Forward pass
        output = model(data)
        loss = criterion(output, target)
        
        # Backward pass
        optimizer.zero_grad()
        loss.backward()
        
        #step 실행 
        optimizer.step()
        
        # Calculate metrics
        train_loss += loss.item() * target.size(0)
        _, predicted = output.max(1)
        total += target.size(0)
        correct += predicted.eq(target).sum().item()
        
        # Update progress bar
        if batch_idx % 10 == 0:
            pbar.set_postfix({
                'Loss': f'{loss.item():.4f}',
                'Acc': f'{100.*correct/total:.2f}%'
            })
    
    avg_loss = train_loss / total
    accuracy = 100. * correct / total
    
    return avg_loss, accuracy

def evaluate(model, device, data_loader, criterion):
    
    model.eval()
    total_loss = 0
    correct = 0
    total = 0
    
    all_predictions = []
    all_targets = []
    
    with torch.no_grad():
        for data, target in data_loader:
            data, target = data.to(device), target.to(device)
            
            output = model(data)
            total_loss += criterion(output, target).item() * target.size(0)
            
            _, predicted = output.max(1)
            total += target.size(0)
            correct += predicted.eq(target).sum().item()
            
            all_predictions.extend(predicted.cpu().numpy())
            all_targets.extend(target.cpu().numpy())
    
    avg_loss = total_loss / total
    accuracy = 100. * correct / total
    
    return avg_loss, accuracy, np.array(all_predictions), np.array(all_targets)

print("Training and evaluation functions defined.")

print("Starting training...\n")

best_val_loss = float("inf")
best_val_epoch = 0
best_model_state = None

for epoch in range(1, num_epochs + 1):
    # Train for one epoch
    train_loss, train_acc = train_epoch(
        model, device, train_loader, optimizer, criterion, epoch
    )
    
    # Evaluate on the validation set; keep the test set untouched until training ends.
    val_loss, val_acc, _, _ = evaluate(model, device, val_loader, criterion)
    
    # Store metrics
    train_losses.append(train_loss)
    train_accuracies.append(train_acc)
    val_losses.append(val_loss)
    val_accuracies.append(val_acc)

    if val_loss < best_val_loss:
        best_val_loss = val_loss
        best_val_epoch = epoch
        best_model_state = deepcopy(model.state_dict())
    
    # Update learning rate
    scheduler.step()
    
    # Print epoch summary
    print(f'\nEpoch {epoch}/{num_epochs}:')
    print(f'  Train Loss: {train_loss:.4f}, Train Acc: {train_acc:.2f}%')
    print(f'  Validation Loss: {val_loss:.4f}, Validation Acc: {val_acc:.2f}%')
    print(f'  Learning Rate: {scheduler.get_last_lr()[0]:.6f}')
    print('-' * 50)

if best_model_state is None:
    raise RuntimeError("Training completed without saving a best validation model.")

model.load_state_dict(best_model_state)
print(f"\nSelected epoch {best_val_epoch} with validation loss {best_val_loss:.4f}.")

# Evaluate the selected model on the test set exactly once.
test_loss, test_accuracy, predictions, targets = evaluate(
    model, device, test_loader, criterion
)
print(f"Final Test Loss: {test_loss:.4f}")
print(f"Final Test Accuracy: {test_accuracy:.2f}%")
    
#-------------------학습 결과 그래프 도출-------------------------
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 5))

# Loss plot
ax1.plot(train_losses, label='Train Loss', marker='o')
ax1.plot(val_losses, label='Validation Loss', marker='s')
ax1.set_xlabel('Epoch')
ax1.set_ylabel('Loss')
ax1.set_title('Training and Validation Loss')
ax1.legend()
ax1.grid(True, alpha=0.3)

# Accuracy plot
ax2.plot(train_accuracies, label='Train Accuracy', marker='o')
ax2.plot(val_accuracies, label='Validation Accuracy', marker='s')
ax2.set_xlabel('Epoch')
ax2.set_ylabel('Accuracy (%)')
ax2.set_title('Training and Validation Accuracy')
ax2.legend()
ax2.grid(True, alpha=0.3)

plt.tight_layout()
plt.show()

# Summarize the most common misclassifications (rows: true labels, columns: predictions).
confusion = np.zeros((10, 10), dtype=int)
np.add.at(confusion, (targets, predictions), 1)
wrong_indices = np.flatnonzero(predictions != targets)
print(f"\nMisclassified test samples: {len(wrong_indices)} / {len(targets)}")

misclassification_counts = [
    (count, true_label, predicted_label)
    for true_label in range(10)
    for predicted_label in range(10)
    if true_label != predicted_label
    if (count := confusion[true_label, predicted_label]) > 0
]
misclassification_counts.sort(reverse=True)
print("Most common true -> predicted label confusions:")
for count, true_label, predicted_label in misclassification_counts[:5]:
    print(f"  {true_label} -> {predicted_label}: {count}")

if len(wrong_indices) > 0:
    examples = wrong_indices[:10]
    fig, axes = plt.subplots(2, 5, figsize=(12, 5))
    for axis, index in zip(axes.flat, examples):
        image, label = test_dataset[int(index)]
        axis.imshow(image.squeeze(0).numpy(), cmap="gray")
        axis.set_title(f"True: {label}, Pred: {predictions[index]}")
        axis.axis("off")
    for axis in axes.flat[len(examples):]:
        axis.axis("off")
    fig.suptitle("Misclassified MNIST test examples")
    plt.tight_layout()
    plt.show()