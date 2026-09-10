<h1>워크스페이스의 src 폴더로 이동

cd ~/[워크스페이스 이름]/src 

# ament_cmake 빌드 타입을 사용하여 C++ 패키지 생성
ros2 pkg create --build-type ament_cmake ros_dd_cpp

# 워크스페이스 루트로 이동
cd ~/ros2_ws

# 특정 패키지만 빌드
colcon build --packages-select ros_dd_cpp

# 특정 패키지만 빌드
colcon build --packages-select ros_dd_cpp

<h1>패키지 확인
ros2 pkg list | grep ros_dd_cpp
