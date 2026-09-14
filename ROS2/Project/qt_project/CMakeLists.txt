cmake_minimum_required(VERSION 3.8)
project(qt_project)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(rosidl_typesupport_cpp REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(patrol_planner_node
  src/seat.cpp
  src/patrol_planner.cpp
  src/tsp_solver.cpp
  src/patrol_planner_node.cpp
)

add_dependencies(patrol_planner_node
  ${PROJECT_NAME}__rosidl_generator_cpp
)

add_executable(gui_monitor_node

  src/main.cpp
  src/gui_monitor_node.cpp
  ui/mainwindow.ui
)

set_target_properties(gui_monitor_node PROPERTIES
    AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/ui"
)


add_dependencies(gui_monitor_node
  ${PROJECT_NAME}__rosidl_generator_cpp
)

target_include_directories(gui_monitor_node PUBLIC

  ${CMAKE_CURRENT_BINARY_DIR}

  ${CMAKE_CURRENT_BINARY_DIR}/rosidl_generator_cpp
)

ament_target_dependencies(gui_monitor_node
  rclcpp
  rosidl_typesupport_cpp
  std_msgs
)

target_link_libraries(gui_monitor_node
  Qt6::Widgets
)

target_link_libraries(gui_monitor_node

  ${PROJECT_NAME}__rosidl_typesupport_cpp
)

target_include_directories(gui_monitor_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_include_directories(patrol_planner_node PUBLIC
  ${CMAKE_CURRENT_BINARY_DIR}/rosidl_generator_cpp
)

ament_target_dependencies(patrol_planner_node
  rclcpp
  rosidl_typesupport_cpp
  std_msgs
)



target_link_libraries(patrol_planner_node
  ${PROJECT_NAME}__rosidl_typesupport_cpp
)

target_include_directories(patrol_planner_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS
  patrol_planner_node
  gui_monitor_node
  DESTINATION lib/${PROJECT_NAME}
)
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/SeatStatus.msg"
  "msg/SeatCommand.msg"
  "srv/GetRoute.srv"
  "srv/ProcessPenalty.srv"
)

ament_export_dependencies(rosidl_default_runtime)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
