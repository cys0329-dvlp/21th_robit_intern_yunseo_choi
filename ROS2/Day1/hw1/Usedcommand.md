//실행
ros2 run turtlesim turtlesim_node

<사각형 만들기>
<br>//직진
<br>ros2 topic pub --rate 10 --times 10 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 1.0}, angular: {z: 0.0}}"

<br><br>//회전
<br>ros2 topic pub --rate 10.5 --times 7 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 0.0}, angular: {z: 1.0}}"

<br><br><원 만들기>
<br>ros2 topic pub --rate 10 --times 60 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 1.0}, angular: {z: 1.0}}"

<br><br><삼각형 만들기>
<br>//직진
<br>ros2 topic pub --rate 10 --times 10 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 1.0}, angular: {z: 0.0}}"

<br><br>//회전
<br>ros2 topic pub --rate 10.5 --times 7 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 0.0}, angular: {z: 1.333333333}}"
