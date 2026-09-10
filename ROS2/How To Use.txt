1. 워크스페이스의 src 폴더로 이동<br>

cd ~/[워크스페이스 이름]/src <br>

2. ament_cmake 빌드 타입을 사용하여 C++ 패키지 생성<br>
ros2 pkg create --build-type ament_cmake ros_dd_cpp<br>

3. 워크스페이스 루트로 이동<br>
cd ~/ros2_ws<br>

4. 특정 패키지만 빌드<br>
colcon build --packages-select ros_dd_cpp<br>

5. 환경 설정 적용<br>
source install/setup.bash<br>

6. 패키지 확인<br>
ros2 pkg list | grep ros_dd_cpp<br>
