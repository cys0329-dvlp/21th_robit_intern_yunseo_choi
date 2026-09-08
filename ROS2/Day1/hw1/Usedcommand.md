//실행
ros2 run turtlesim turtlesim_node

<사각형 만들기>
//직진
ros2 topic pub --rate 10 --times 10 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 1.0}, angular: {z: 0.0}}"

//회전
ros2 topic pub --rate 10.5 --times 7 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 0.0}, angular: {z: 1.0}}"

<원 만들기>
ros2 topic pub --rate 10 --times 60 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 1.0}, angular: {z: 1.0}}"

<삼각형 만들기>
//직진
ros2 topic pub --rate 10 --times 10 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 1.0}, angular: {z: 0.0}}"

//회전
ros2 topic pub --rate 10.5 --times 7 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 0.0}, angular: {z: 1.333333333}}"
