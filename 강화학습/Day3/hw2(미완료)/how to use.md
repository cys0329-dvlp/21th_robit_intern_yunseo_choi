**requirments**
```
pip install stable-baselines3==2.3.0
pip install gymnasium[mujoco]
pip install mujoco
```
if ubuntu user
```
sudo apt-get install libosmesa6-dev
```
**Training**
```
python humanoid.py --env Humanoid-v5 --timesteps 200000 --save_dir models
```
**Playing a Saved Model**
```
python humanoid.py --play --env Humanoid-v5 --model models/Humanoid_v5_ppo_200k.zip --render
```


