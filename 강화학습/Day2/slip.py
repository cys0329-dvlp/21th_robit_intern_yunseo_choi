import random
import gymnasium as gym
import numpy as np
import matplotlib.pyplot as plt

class QAgent():
    def __init__(self):
        self.q_table = np.zeros((4,4,4)) #각각 
        self.eps = 1.0  # 입실론값 설정.
        self.gamma = 0.99
        self.alpha = 0.1

    def select_action(self, state): # 받아온 state를 바탕으로 본인의 정책을 수정. statem는 0~15
        row, col = int(state/4), state%4    # row와 column 형태로 수정
        rnum = random.random()  #0.0~1.0
        if rnum<self.eps: # 뽑은 랜덤 넘버가 입실론보다 낮다면
            action = random.randint(0,3) # 랜덤한 액션 설정
        else:
            action_val = self.q_table[:, row, col]  # row, col 위치에서 q table들을 보고 가장 큰 값을 가져온다
            action = np.argmax(action_val)  # 가장 큰 값의 인덱스

        return action

    def update_table(self, state, action, reward, next_state, terminated):
        row, col = divmod(state, 4)
        n_row, n_col = divmod(next_state, 4)

        old_q = self.q_table[action, row, col]

        if terminated:
            next_q = 0.0
        else:
            next_q = np.max(self.q_table[:, n_row, n_col])

        #Q-table 갱신 
        target = reward + self.gamma * next_q
        self.q_table[action, row, col] = old_q + self.alpha * (target - old_q)

    def decrease_eps(self):
        self.eps = max(0.01, self.eps * 0.9995)

    def show_table(self):
        arrows = ["←", "↓", "→", "↑"]
        holes = {5, 7, 11, 12}
        goal = 15
        grid = []

        for row in range(4):
            line = []
            for col in range(4):
                state = row * 4 + col

                if state == goal:
                    cell = " G "
                elif state in holes:
                    cell = " H "
                else:
                    action = int(np.argmax(self.q_table[:, row, col]))
                    cell = f" {arrows[action]} "

                line.append(cell)

            grid.append(line)

        print("정책 격자 (S=시작, G=목표, H=구멍)")
        grid[0][0] = " S" + grid[0][0][2:]
        for line in grid:
            print(" | ".join(line))

env = gym.make("FrozenLake-v1", is_slippery = True) #render_mode = "human"
agent = QAgent() # agent 만들기

MAXEPISODENUM = 100000
total_reward = 0

episode_rewards = [] #각 에피소드 별 학습 보상
episode_successes = [] #각 에피소드 별 성공률 

for epi in range(MAXEPISODENUM):
    done = False

    episode_reward = 0
    episode_success = False

    state = env.reset() # (0, {'prob' : 1}) <- (현재 위치, 다음 상태로 넘어갈 확률)
    state = state[0]

    while not done:
        action = agent.select_action(state)
        next_state, _, terminated, truncated, _ = env.step(action)   # agent가 선택하는 action
        done = terminated or truncated
        reward = 0 # 움직일 때마다 -1
        if(next_state == 15):   # 15번 위치에 도달하면 리워드 10
            reward = 1
            episode_success = True
        elif(next_state == 5 or next_state == 7 or next_state == 11 or next_state == 12):   # 구멍에 빠지면 리워드-10
            reward = 0

        total_reward += reward #전체 보상 
        episode_reward += reward #각 에피소드 별 보상 
        # env.render()
    
        agent.update_table(state, action, reward, next_state, terminated)
        state = next_state #다음 스테이트로 넘어감
    
    #학습 보상 및 성공률 기록 
    episode_rewards.append(episode_reward)
    episode_successes.append(int(episode_success))
    
    agent.decrease_eps()    # 입실론값 줄이기

    if(epi%1000 == 0 and epi != 0):
        print(f"{epi}/{MAXEPISODENUM}")
        print(total_reward/epi) #학습 시작부터 해당 시점까지 누적된 보상을 에피소드로 나눈 값 
np.save("q_table.npy", agent.q_table) #학습 끝난 뒤 Q-table 저장 


#--------Q heatmap 출력-------------
action_names = ["left", "down", "right", "up"]

fig, axes = plt.subplots(1, 4, figsize=(16, 4))

for action, name in enumerate(action_names):
    image = axes[action].imshow(agent.q_table[action], cmap="coolwarm")
    axes[action].set_title(f"{name} action")
    axes[action].set_xlabel("col")
    axes[action].set_ylabel("row")

    for row in range(4):
        for col in range(4):
            axes[action].text(
                col, row,
                f"{agent.q_table[action, row, col]:.2f}",
                ha="center",
                va="center"
            )

    fig.colorbar(image, ax=axes[action])

plt.tight_layout()
plt.savefig("q_table_heatmap.png")

#---------학습 끝난 뒤 학습 보상 및 성공률 곡선 출력---------------
window = 100
weights = np.ones(window) / window

reward_avg = np.convolve(episode_rewards, weights, mode="valid")
success_rate = np.convolve(episode_successes, weights, mode="valid") * 100
episodes = np.arange(window, MAXEPISODENUM + 1)

fig, axes = plt.subplots(2, 1, figsize=(10, 8))

axes[0].plot(episodes, reward_avg)
axes[0].set_title("Training Reward (100-episode average)")
axes[0].set_xlabel("Episode")
axes[0].set_ylabel("Average reward")

axes[1].plot(episodes, success_rate)
axes[1].set_title("Training Success Rate (100-episode window)")
axes[1].set_xlabel("Episode")
axes[1].set_ylabel("Success rate (%)")
axes[1].set_ylim(0, 100)

plt.tight_layout()
plt.savefig("training_curves.png")
plt.show()

agent.show_table()

##---------------------test----------------
env2 = gym.make("FrozenLake-v1", is_slippery = True, render_mode = "human")
agent.q_table = np.load("q_table.npy") #평가 전 저장된 Q-table 불러오기
agent.eps = 0.0 #테스트할 때는 예외 발생하면 안되니까 엡실론 0으로 설정 

num_eval_episodes = 200 #100개 에피소드로 테스트 
success_count = 0 #성공한 에피소드 수 

for epi in range(200):
    done = False
    s = env2.reset()[0]
    
    while not done:
        a = agent.select_action(s)
        n_s, _, terminated, truncated, _ = env2.step(a)
        done = terminated or truncated
        
        if terminated and n_s == 15:
            success_count += 1
        s = n_s
        
print(f"성공 횟수: {success_count}/{num_eval_episodes}")
print(f"성공률: {success_count / num_eval_episodes:.1%}")