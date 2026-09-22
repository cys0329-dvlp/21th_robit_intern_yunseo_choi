<사용법>

1. 저장소 받기 

git clone https://github.com/cys0329-dvlp/21th_robit_intern_yunseo_choi.git
cd 21th_robit_intern_yunseo_choi

2. 워크스페이스 만들기(본인 워크스페이스 있다면 스킵)

mkdir -p ~/ros2_ws/src

3. hw1을 워크스페이스의 src로 복사

cp -r Vision/Day2/hw1 ~/ros2_ws/src/CalDist_pkg

4. 환경 설정(ROS2 jazzy 기준)

source /opt/ros/jazzy/setup.bash

5. 필요한 패키지 설치

sudo apt update
sudo apt install libopencv-dev qt6-base-dev

6. 빌드 및 실행 

cd ~/ros2_ws
colcon build --packages-select CalDist_pkg
source ~/ros2_ws/install/setup.bash
ros2 run CalDist_pkg CalDist_node

7. 별도의 명령어 없이 UI에 있는 publish start -> subscribe start 버튼 누르면 바로 시작됨
