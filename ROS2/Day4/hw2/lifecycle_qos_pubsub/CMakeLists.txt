cmake_minimum_required(VERSION 3.8)
project(lifecycle_qos_pubsub)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_lifecycle REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(
  include
)

add_executable(
  lifecycle_publisher
  src/lifecycle_publisher.cpp
)

ament_target_dependencies(
  lifecycle_publisher
  rclcpp
  rclcpp_lifecycle
  std_msgs
)

add_executable(
  lifecycle_subscriber
  src/lifecycle_subscriber.cpp
)

ament_target_dependencies(
  lifecycle_subscriber
  rclcpp
  rclcpp_lifecycle
  std_msgs
)

install(
  TARGETS
    lifecycle_publisher
    lifecycle_subscriber
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()