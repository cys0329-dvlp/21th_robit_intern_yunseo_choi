cmake_minimum_required(VERSION 3.8)
project(color_object_detection)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(OpenCV REQUIRED)

add_executable(color_object_detection
  src/color_object_detection.cpp
)

target_include_directories(color_object_detection PUBLIC

  ${CMAKE_CURRENT_SOURCE_DIR}/include

)

ament_target_dependencies(color_object_detection
  rclcpp
)

target_link_libraries(color_object_detection
  ${OpenCV_LIBS}
)

install(TARGETS
  color_object_detection
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()