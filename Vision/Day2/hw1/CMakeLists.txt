cmake_minimum_required(VERSION 3.8)

project(CalDist_pkg)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(
  include
)

add_executable(CalDist_node
  src/main.cpp
  src/UI/mainwindow.cpp
  src/UI/mainwindow.ui

  include/CalDist_pkg/UI/mainwindow.hpp

  src/Subscriber/image_subscriber.cpp
  include/CalDist_pkg/Subscriber/image_subscriber.hpp

  src/Distance/define_yellow_ball.cpp
  include/CalDist_pkg/Distance/define_yellow_ball.hpp

  src/Distance/distance_calculator.cpp
  include/CalDist_pkg/Distance/distance_calculator.hpp
)

ament_target_dependencies(CalDist_node
  rclcpp
  sensor_msgs
)

target_link_libraries(CalDist_node
  Qt6::Widgets
  ${OpenCV_LIBS}
)

install(
  TARGETS CalDist_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()