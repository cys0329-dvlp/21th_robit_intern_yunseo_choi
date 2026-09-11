cmake_minimum_required(VERSION 3.8)

project(ROS2_Day3_hw2_pkg)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(NOT CMAKE_CXX_STANDARD_REQUIRED)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

include_directories(
  include
)

add_executable(traffic_light_node
  src/traffic_light_node.cpp
)

ament_target_dependencies(traffic_light_node
  rclcpp
  std_msgs
)

add_executable(vehicle_node
  src/vehicle_node.cpp
)

ament_target_dependencies(vehicle_node
  rclcpp
  std_msgs
  geometry_msgs
)

add_executable(qt_simulator_node
  src/qt_simulator_node.cpp
)

ament_target_dependencies(qt_simulator_node
  rclcpp
  std_msgs
  geometry_msgs
)

target_link_libraries(qt_simulator_node
  Qt5::Widgets
)

install(
  TARGETS
    traffic_light_node
    vehicle_node
    qt_simulator_node
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY include/
  DESTINATION include
)

install(
  DIRECTORY config
  DESTINATION share/${PROJECT_NAME}
)

install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()