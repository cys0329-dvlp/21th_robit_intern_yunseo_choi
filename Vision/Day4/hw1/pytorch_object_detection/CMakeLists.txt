cmake_minimum_required(VERSION 3.8)
project(pytorch_object_detection)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(OpenCV REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenVINO REQUIRED)
find_package(ament_index_cpp REQUIRED)

include_directories(
  include
)

add_executable(camera_node
  src/camerar_node/camera_node.cpp
)

add_executable(inference_node
  src/inference_node/inference_node.cpp
)

ament_target_dependencies(camera_node
  rclcpp
  sensor_msgs
  cv_bridge
)

ament_target_dependencies(inference_node
  rclcpp
  sensor_msgs
  cv_bridge
  ament_index_cpp
)

target_link_libraries(camera_node
  ${OpenCV_LIBS}
)

target_link_libraries(inference_node
  openvino
  ${OpenCV_LIBS}
)

install(TARGETS
  camera_node
  inference_node
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY config launch models
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
