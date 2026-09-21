cmake_minimum_required(VERSION 3.8)
project(camera_ui_pkg)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(image_transport REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Qt는 Q_OBJECT가 붙은 클래스(ui_node)를 moc로 전처리해야 하므로 AUTOMOC 필요
set(CMAKE_AUTOMOC ON)

include_directories(
  include
)

# ---- camera_node ----
add_executable(camera_node
  src/camera_node/camera_node.cpp
)

target_include_directories(camera_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

ament_target_dependencies(camera_node
  rclcpp
  sensor_msgs
  std_msgs
  image_transport
  cv_bridge
  OpenCV
)

# ---- ui_node (Qt) ----
add_executable(ui_node
  src/ui_node/ui_node.cpp
  include/camera_ui_pkg/ui_node/ui_node.hpp   # Q_OBJECT 포함 -> AUTOMOC가 이 헤더를 처리
)

target_include_directories(ui_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

ament_target_dependencies(ui_node
  rclcpp
  sensor_msgs
  std_msgs
  image_transport
  cv_bridge
  OpenCV
)

target_link_libraries(ui_node
  Qt6::Widgets
)

install(TARGETS
  camera_node
  ui_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
  launch
  config
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()