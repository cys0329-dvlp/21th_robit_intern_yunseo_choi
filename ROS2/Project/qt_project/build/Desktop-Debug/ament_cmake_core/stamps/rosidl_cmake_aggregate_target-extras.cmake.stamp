# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target qt_project::qt_project
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${qt_project_TARGETS}.
if(qt_project_TARGETS AND NOT TARGET qt_project::qt_project)
  add_library(qt_project::qt_project INTERFACE IMPORTED)
  set_target_properties(qt_project::qt_project PROPERTIES
    INTERFACE_LINK_LIBRARIES "${qt_project_TARGETS}")
endif()
