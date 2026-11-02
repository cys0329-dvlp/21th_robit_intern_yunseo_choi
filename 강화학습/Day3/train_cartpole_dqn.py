#!/usr/bin/env python3
"""Train and evaluate a reproducible DQN agent on Gymnasium CartPole-v1."""

from __future__ import annotations

import argparse
import json
import platform
import random
from dataclasses import asdict, dataclass
from pathlib import Path
from typing import Sequence

import gymnasium as gym
import matplotlib

matplotlib.use("Agg")
import matplotlib.pyplot as plt
import numpy as np
import torch
from torch import nn


@dataclass
class Config:
    # 과제 재현성/평가 조건: seed 고정, 체크포인트마다 greedy 50회 평가.
    seed: int = 1
    episodes: int = 1_000
    eval_interval: int = 25
    eval_episodes: int = 50
    replay_capacity: int = 50_000
    batch_size: int = 64
    warmup_steps: int = 1_000
    gamma: float = 0.99
    learning_rate: float = 1e-3
    target_update_interval: int = 1_000
    epsilon_start: float = 1.0
    epsilon_end: float = 0.01
    epsilon_decay_steps: int = 20_000
    moving_average_window: int = 50
    output_dir: Path = Path(__file__).resolve().parent / "outputs"


class QNetwork(nn.Module):
    def __init__(self) -> None:
        super().__init__()
        # 과제 요구 구조: 상태 [위치, 속도, 막대 각도, 각속도] 4개,
        # 은닉층 64-ReLU-64-ReLU, 선형 Q값 2개(왼쪽 0, 오른쪽 1).
        self.layers = nn.Sequential(
            nn.Linear(4, 64),
            nn.ReLU(),
            nn.Linear(64,32),
            nn.ReLU(),
            nn.Linear(32, 2),
        )

    def forward(self, state: torch.Tensor) -> torch.Tensor:
        return self.layers(state)


class ReplayBuffer:
    def __init__(self, capacity: int, rng: np.random.Generator) -> None:
        self.states = np.zeros((capacity, 4), dtype=np.float32)
        self.actions = np.zeros(capacity, dtype=np.int64)
        self.rewards = np.zeros(capacity, dtype=np.float32)
        self.next_states = np.zeros((capacity, 4), dtype=np.float32)
        # truncated는 bootstrap에 사용하고, terminated만 bootstrap을 차단한다.
        self.terminated = np.zeros(capacity, dtype=np.float32)
        self.capacity = capacity
        self.rng = rng
        self.position = 0
        self.size = 0

    def add(
        self,
        state: np.ndarray,
        action: int,
        reward: float,
        next_state: np.ndarray,
        terminated: bool,
    ) -> None:
        self.states[self.position] = state
        self.actions[self.position] = action
        self.rewards[self.position] = reward
        self.next_states[self.position] = next_state
        self.terminated[self.position] = float(terminated)
        self.position = (self.position + 1) % self.capacity
        self.size = min(self.size + 1, self.capacity)

    def sample(self, batch_size: int) -> tuple[np.ndarray, ...]:
        indices = self.rng.choice(self.size, size=batch_size, replace=False)
        return (
            self.states[indices],
            self.actions[indices],
            self.rewards[indices],
            self.next_states[indices],
            self.terminated[indices],
        )


def seed_everything(seed: int) -> None:
    # Python/NumPy/PyTorch 난수를 함께 고정해 실행 간 차이를 줄인다.
    random.seed(seed)
    np.random.seed(seed)
    torch.manual_seed(seed)
    torch.set_num_threads(1)
    torch.use_deterministic_algorithms(True)


def select_action(
    network: QNetwork,
    state: np.ndarray,
    epsilon: float,
    rng: np.random.Generator,
) -> int:
    if rng.random() < epsilon:
        return int(rng.integers(2))
    with torch.no_grad():
        state_tensor = torch.as_tensor(state, dtype=torch.float32).unsqueeze(0)
        return int(network(state_tensor).argmax(dim=1).item())


def evaluate(
    network: QNetwork,
    episode_seeds: Sequence[int],
) -> list[float]:
    # 학습 중 epsilon을 쓰지 않는 greedy 정책으로 독립된 여러 에피소드를 평가한다.
    scores: list[float] = []
    env = gym.make("CartPole-v1")
    try:
        for episode_seed in episode_seeds:
            state, _ = env.reset(seed=episode_seed)
            episode_return = 0.0
            action_rng = np.random.default_rng(episode_seed)
            while True:
                action = select_action(
                    network, np.asarray(state, dtype=np.float32), 0.0,
                    action_rng,
                )
                state, reward, terminated, truncated, _ = env.step(action)
                episode_return += float(reward)
                if terminated or truncated:
                    break
            scores.append(episode_return)
    finally:
        env.close()
    return scores


def update_network(
    online_network: QNetwork,
    target_network: QNetwork,
    optimizer: torch.optim.Optimizer,
    replay_buffer: ReplayBuffer,
    config: Config,
) -> float:
    states, actions, rewards, next_states, terminated = replay_buffer.sample(
        config.batch_size
    )
    states_tensor = torch.as_tensor(states, dtype=torch.float32)
    actions_tensor = torch.as_tensor(actions, dtype=torch.int64)
    rewards_tensor = torch.as_tensor(rewards, dtype=torch.float32)
    next_states_tensor = torch.as_tensor(next_states, dtype=torch.float32)
    terminated_tensor = torch.as_tensor(terminated, dtype=torch.float32)

    # gather 후 squeeze(1)로 prediction을 [batch]로 만들고 target도 같은 shape으로 계산.
    predictions = online_network(states_tensor).gather(
        1, actions_tensor.unsqueeze(1)
    ).squeeze(1)
    # Target network는 no_grad로 고정하며, 실제 종료(terminated)에서만 bootstrap을 제거.
    with torch.no_grad():
        next_values = target_network(next_states_tensor).max(dim=1).values
        targets = rewards_tensor + config.gamma * next_values * (
            1.0 - terminated_tensor
        )

    loss = nn.functional.smooth_l1_loss(predictions, targets)
    optimizer.zero_grad(set_to_none=True)
    loss.backward()
    nn.utils.clip_grad_norm_(online_network.parameters(), max_norm=10.0)
    optimizer.step()
    return float(loss.item())


def save_plots(
    config: Config,
    episode_returns: Sequence[float],
    env_steps: Sequence[int],
    eval_means: Sequence[float],
    eval_stds: Sequence[float],
    loss_updates: Sequence[int],
    losses: Sequence[float],
    epsilon_steps: Sequence[int],
    epsilons: Sequence[float],
) -> None:
    config.output_dir.mkdir(parents=True, exist_ok=True)
    # 과제 그래프 4종 모두 seed와 체크포인트별 greedy 평가 횟수를 제목에 표시한다.
    eval_note = f"greedy evaluation: {config.eval_episodes} episodes/checkpoint"
    title_suffix = f"seed={config.seed} | {eval_note}"

    returns = np.asarray(episode_returns, dtype=np.float64)
    window = min(config.moving_average_window, len(returns))
    moving_average = np.convolve(
        returns, np.ones(window, dtype=np.float64) / window, mode="valid"
    )
    figure, axis = plt.subplots(figsize=(10, 5))
    # 학습 보상: 에피소드별 return과 이동 평균.
    axis.plot(np.arange(1, len(returns) + 1), returns, alpha=0.3, label="Episode return")
    axis.plot(
        np.arange(window, len(returns) + 1),
        moving_average,
        label=f"{window}-episode moving average",
    )
    axis.set(title=f"Training return | {title_suffix}", xlabel="Episode", ylabel="Return")
    axis.legend()
    figure.tight_layout()
    figure.savefig(config.output_dir / "training_returns.png", dpi=150)
    plt.close(figure)

    figure, axis = plt.subplots(figsize=(10, 5))
    # Greedy 평가: 환경 step별 평균과 표준편차 범위.
    steps = np.asarray(env_steps)
    means = np.asarray(eval_means)
    stds = np.asarray(eval_stds)
    axis.plot(steps, means, marker="o", label="Greedy mean return")
    axis.fill_between(steps, means - stds, means + stds, alpha=0.2, label="±1 std")
    axis.set(
        title=f"Greedy evaluation | {title_suffix}",
        xlabel="Environment step",
        ylabel="Return",
    )
    axis.legend()
    figure.tight_layout()
    figure.savefig(config.output_dir / "greedy_evaluation.png", dpi=150)
    plt.close(figure)

    figure, axis = plt.subplots(figsize=(10, 5))
    # TD loss는 optimizer update 횟수를 x축으로 기록한다.
    axis.plot(loss_updates, losses)
    axis.set(
        title=f"TD loss | {title_suffix}",
        xlabel="Optimizer update",
        ylabel="Smooth L1 loss",
    )
    figure.tight_layout()
    figure.savefig(config.output_dir / "td_loss.png", dpi=150)
    plt.close(figure)

    figure, axis = plt.subplots(figsize=(10, 5))
    # 탐험률 epsilon은 환경 step에 따라 감소한다.
    axis.plot(epsilon_steps, epsilons)
    axis.set(
        title=f"Exploration rate | {title_suffix}",
        xlabel="Environment step",
        ylabel="Epsilon",
    )
    figure.tight_layout()
    figure.savefig(config.output_dir / "epsilon.png", dpi=150)
    plt.close(figure)


def run(config: Config) -> None:
    # 학습은 CPU에서 수행하고, target network는 optimizer에 등록하지 않는다.
    seed_everything(config.seed)
    action_rng = np.random.default_rng(config.seed)
    replay_rng = np.random.default_rng(config.seed + 1)
    replay_buffer = ReplayBuffer(config.replay_capacity, replay_rng)

    env = gym.make("CartPole-v1")
    env.action_space.seed(config.seed)
    online_network = QNetwork()
    target_network = QNetwork()
    target_network.load_state_dict(online_network.state_dict())
    target_network.requires_grad_(False)
    # optimizer는 online network만 갱신한다.
    optimizer = torch.optim.Adam(online_network.parameters(), lr=config.learning_rate)

    episode_returns: list[float] = []
    evaluation_steps: list[int] = []
    evaluation_means: list[float] = []
    evaluation_stds: list[float] = []
    evaluation_records: list[dict[str, object]] = []
    loss_updates: list[int] = []
    losses: list[float] = []
    epsilon_steps = [0]
    epsilons = [config.epsilon_start]
    global_env_step = 0
    optimizer_updates = 0

    evaluation_seeds = [
        config.seed + 10_000 + index for index in range(config.eval_episodes)
    ]
    # 체크포인트 평가 점수가 흔들릴 수 있어 가장 높은 평균의 모델을 별도로 보관한다.
    best_eval_mean = float("-inf")
    best_checkpoint_episode = 0
    best_network_state: dict[str, torch.Tensor] | None = None
    try:
        for episode in range(1, config.episodes + 1):
            state, _ = env.reset(seed=config.seed if episode == 1 else None)
            episode_return = 0.0
            while True:
                epsilon = max(
                    config.epsilon_end,
                    config.epsilon_start
                    - (config.epsilon_start - config.epsilon_end)
                    * global_env_step
                    / config.epsilon_decay_steps,
                )
                state_array = np.asarray(state, dtype=np.float32)
                action = select_action(online_network, state_array, epsilon, action_rng)
                next_state, reward, terminated, truncated, _ = env.step(action)
                next_state_array = np.asarray(next_state, dtype=np.float32)

                replay_buffer.add(
                    state_array, action, float(reward), next_state_array, terminated
                )
                global_env_step += 1
                episode_return += float(reward)

                if replay_buffer.size >= max(config.batch_size, config.warmup_steps):
                    optimizer_updates += 1
                    loss_value = update_network(
                        online_network, target_network, optimizer,
                        replay_buffer, config,
                    )
                    loss_updates.append(optimizer_updates)
                    losses.append(loss_value)
                    if optimizer_updates % config.target_update_interval == 0:
                        target_network.load_state_dict(online_network.state_dict())

                epsilon_steps.append(global_env_step)
                epsilons.append(max(
                    config.epsilon_end,
                    config.epsilon_start
                    - (config.epsilon_start - config.epsilon_end)
                    * global_env_step
                    / config.epsilon_decay_steps,
                ))
                state = next_state
                if terminated or truncated:
                    break

            episode_returns.append(episode_return)
            should_evaluate = (
                episode % config.eval_interval == 0 or episode == config.episodes
            )
            if should_evaluate:
                scores = evaluate(online_network, evaluation_seeds)
                mean = float(np.mean(scores))
                std = float(np.std(scores, ddof=1)) if len(scores) > 1 else 0.0
                evaluation_steps.append(global_env_step)
                evaluation_means.append(mean)
                evaluation_stds.append(std)
                evaluation_records.append({
                    "episode": episode,
                    "environment_step": global_env_step,
                    "episodes": len(scores),
                    "mean": mean,
                    "std": std,
                    "min": float(np.min(scores)),
                    "max": float(np.max(scores)),
                    "returns": scores,
                })
                if mean > best_eval_mean:
                    best_eval_mean = mean
                    best_checkpoint_episode = episode
                    best_network_state = {
                        name: tensor.detach().clone()
                        for name, tensor in online_network.state_dict().items()
                    }
                print(
                    f"Episode {episode:4d} | env steps {global_env_step:7d} | "
                    f"train return {episode_return:6.1f} | "
                    f"greedy {mean:6.2f} ± {std:5.2f} "
                    f"(min {min(scores):.0f}, max {max(scores):.0f}; "
                    f"n={len(scores)}) | epsilon {epsilons[-1]:.3f}"
                )
            elif episode % 10 == 0:
                print(
                    f"Episode {episode:4d}/{config.episodes} | "
                    f"return {episode_return:6.1f} | "
                    f"env steps {global_env_step:7d} | epsilon {epsilons[-1]:.3f}"
                )
    finally:
        env.close()

    if best_network_state is None:
        raise RuntimeError("Training completed without a greedy evaluation checkpoint")
    online_network.load_state_dict(best_network_state)
    heldout_seeds = [
        config.seed + 20_000 + index for index in range(config.eval_episodes)
    ]
    # 체크포인트 선택에 사용하지 않은 seed 50회로 최종 성능을 반복 평가한다.
    heldout_scores = evaluate(online_network, heldout_seeds)
    heldout_mean = float(np.mean(heldout_scores))
    heldout_std = (
        float(np.std(heldout_scores, ddof=1)) if len(heldout_scores) > 1 else 0.0
    )

    config.output_dir.mkdir(parents=True, exist_ok=True)
    torch.save(online_network.state_dict(), config.output_dir / "best_model.pt")
    save_plots(
        config,
        episode_returns,
        evaluation_steps,
        evaluation_means,
        evaluation_stds,
        loss_updates,
        losses,
        epsilon_steps,
        epsilons,
    )

    run_metadata = {
        "config": {**asdict(config), "output_dir": str(config.output_dir)},
        "versions": {
            # 실행 재현을 위해 Python 및 핵심 라이브러리 버전을 함께 저장한다.
            "python": platform.python_version(),
            "platform": platform.platform(),
            "numpy": np.__version__,
            "pytorch": torch.__version__,
            "gymnasium": gym.__version__,
        },
        "evaluation": {
            "episodes_per_checkpoint": config.eval_episodes,
            "checkpoint_count": len(evaluation_records),
            "total_greedy_episodes": sum(
                int(record["episodes"]) for record in evaluation_records
            ) + len(heldout_scores),
            "selected_checkpoint_episode": best_checkpoint_episode,
            "selected_checkpoint_mean": best_eval_mean,
            "heldout_final": {
                "episodes": len(heldout_scores),
                "mean": heldout_mean,
                "std": heldout_std,
                "min": float(np.min(heldout_scores)),
                "max": float(np.max(heldout_scores)),
                "returns": heldout_scores,
            },
            "checkpoints": evaluation_records,
        },
    }
    with (config.output_dir / "run_metadata.json").open("w", encoding="utf-8") as file:
        json.dump(run_metadata, file, indent=2, ensure_ascii=False)
    print(
        f"\nSelected checkpoint: episode {best_checkpoint_episode} "
        f"(training evaluation mean={best_eval_mean:.2f})"
    )
    print(
        f"Held-out greedy evaluation ({len(heldout_scores)} episodes): "
        f"mean={heldout_mean:.2f}, std={heldout_std:.2f}, "
        f"min={min(heldout_scores):.0f}, max={max(heldout_scores):.0f}"
    )
    print(f"Plots and run metadata saved to: {config.output_dir}")


def parse_args() -> Config:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--seed", type=int, default=1)
    parser.add_argument("--episodes", type=int, default=1_000)
    parser.add_argument("--eval-interval", type=int, default=25)
    parser.add_argument("--eval-episodes", type=int, default=50)
    parser.add_argument("--output-dir", type=Path, default=Config.output_dir)
    args = parser.parse_args()

    if args.episodes < 1:
        parser.error("--episodes must be at least 1")
    if args.eval_interval < 1:
        parser.error("--eval-interval must be at least 1")
    if args.eval_episodes < 1:
        parser.error("--eval-episodes must be at least 1")
    return Config(
        seed=args.seed,
        episodes=args.episodes,
        eval_interval=args.eval_interval,
        eval_episodes=args.eval_episodes,
        output_dir=args.output_dir,
    )


if __name__ == "__main__":
    run(parse_args())
