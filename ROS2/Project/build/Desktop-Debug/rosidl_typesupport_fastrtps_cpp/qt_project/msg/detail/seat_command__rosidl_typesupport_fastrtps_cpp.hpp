// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from qt_project:msg/SeatCommand.idl
// generated code does not contain a copyright notice

#ifndef QT_PROJECT__MSG__DETAIL__SEAT_COMMAND__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define QT_PROJECT__MSG__DETAIL__SEAT_COMMAND__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "qt_project/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "qt_project/msg/detail/seat_command__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace qt_project
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qt_project
cdr_serialize(
  const qt_project::msg::SeatCommand & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qt_project
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  qt_project::msg::SeatCommand & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qt_project
get_serialized_size(
  const qt_project::msg::SeatCommand & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qt_project
max_serialized_size_SeatCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qt_project
cdr_serialize_key(
  const qt_project::msg::SeatCommand & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qt_project
get_serialized_size_key(
  const qt_project::msg::SeatCommand & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qt_project
max_serialized_size_key_SeatCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace qt_project

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qt_project
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, qt_project, msg, SeatCommand)();

#ifdef __cplusplus
}
#endif

#endif  // QT_PROJECT__MSG__DETAIL__SEAT_COMMAND__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
