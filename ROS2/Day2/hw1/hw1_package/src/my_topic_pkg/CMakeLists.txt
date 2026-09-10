cmake_minimum_required(VERSION 3.8)
project(my_topic_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(custom_interfaces REQUIRED)

include_directories(include)

add_executable(int_array_publisher src/int_array_publisher.cpp)
ament_target_dependencies(int_array_publisher rclcpp custom_interfaces)

add_executable(int_array_subscriber src/int_array_subscriber.cpp)
ament_target_dependencies(int_array_subscriber rclcpp custom_interfaces)

install(TARGETS
  int_array_publisher
  int_array_subscriber
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)

  set(ament_cmake_copyright_FOUND TRUE)

  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
