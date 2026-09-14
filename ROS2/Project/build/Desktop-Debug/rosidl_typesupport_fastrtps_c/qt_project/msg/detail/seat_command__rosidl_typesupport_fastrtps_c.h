// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from qt_project:msg/SeatCommand.idl
// generated code does not contain a copyright notice
#ifndef QT_PROJECT__MSG__DETAIL__SEAT_COMMAND__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define QT_PROJECT__MSG__DETAIL__SEAT_COMMAND__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "qt_project/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "qt_project/msg/detail/seat_command__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_qt_project
bool cdr_serialize_qt_project__msg__SeatCommand(
  const qt_project__msg__SeatCommand * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_qt_project
bool cdr_deserialize_qt_project__msg__SeatCommand(
  eprosima::fastcdr::Cdr &,
  qt_project__msg__SeatCommand * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_qt_project
size_t get_serialized_size_qt_project__msg__SeatCommand(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_qt_project
size_t max_serialized_size_qt_project__msg__SeatCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_qt_project
bool cdr_serialize_key_qt_project__msg__SeatCommand(
  const qt_project__msg__SeatCommand * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_qt_project
size_t get_serialized_size_key_qt_project__msg__SeatCommand(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_qt_project
size_t max_serialized_size_key_qt_project__msg__SeatCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_qt_project
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, qt_project, msg, SeatCommand)();

#ifdef __cplusplus
}
#endif

#endif  // QT_PROJECT__MSG__DETAIL__SEAT_COMMAND__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
