// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from qt_project:msg/SeatStatus.idl
// generated code does not contain a copyright notice
#include "qt_project/msg/detail/seat_status__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "qt_project/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "qt_project/msg/detail/seat_status__struct.h"
#include "qt_project/msg/detail/seat_status__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _SeatStatus__ros_msg_type = qt_project__msg__SeatStatus;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_qt_project
bool cdr_serialize_qt_project__msg__SeatStatus(
  const qt_project__msg__SeatStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: seat_id
  {
    cdr << ros_message->seat_id;
  }

  // Field name: occupied
  {
    cdr << (ros_message->occupied ? true : false);
  }

  // Field name: has_belongings
  {
    cdr << (ros_message->has_belongings ? true : false);
  }

  // Field name: absence_start_time
  {
    cdr << ros_message->absence_start_time;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_qt_project
bool cdr_deserialize_qt_project__msg__SeatStatus(
  eprosima::fastcdr::Cdr & cdr,
  qt_project__msg__SeatStatus * ros_message)
{
  // Field name: seat_id
  {
    cdr >> ros_message->seat_id;
  }

  // Field name: occupied
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->occupied = tmp ? true : false;
  }

  // Field name: has_belongings
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->has_belongings = tmp ? true : false;
  }

  // Field name: absence_start_time
  {
    cdr >> ros_message->absence_start_time;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_qt_project
size_t get_serialized_size_qt_project__msg__SeatStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SeatStatus__ros_msg_type * ros_message = static_cast<const _SeatStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: seat_id
  {
    size_t item_size = sizeof(ros_message->seat_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: occupied
  {
    size_t item_size = sizeof(ros_message->occupied);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: has_belongings
  {
    size_t item_size = sizeof(ros_message->has_belongings);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: absence_start_time
  {
    size_t item_size = sizeof(ros_message->absence_start_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_qt_project
size_t max_serialized_size_qt_project__msg__SeatStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: seat_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: occupied
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: has_belongings
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: absence_start_time
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = qt_project__msg__SeatStatus;
    is_plain =
      (
      offsetof(DataType, absence_start_time) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_qt_project
bool cdr_serialize_key_qt_project__msg__SeatStatus(
  const qt_project__msg__SeatStatus * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: seat_id
  {
    cdr << ros_message->seat_id;
  }

  // Field name: occupied
  {
    cdr << (ros_message->occupied ? true : false);
  }

  // Field name: has_belongings
  {
    cdr << (ros_message->has_belongings ? true : false);
  }

  // Field name: absence_start_time
  {
    cdr << ros_message->absence_start_time;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_qt_project
size_t get_serialized_size_key_qt_project__msg__SeatStatus(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SeatStatus__ros_msg_type * ros_message = static_cast<const _SeatStatus__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: seat_id
  {
    size_t item_size = sizeof(ros_message->seat_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: occupied
  {
    size_t item_size = sizeof(ros_message->occupied);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: has_belongings
  {
    size_t item_size = sizeof(ros_message->has_belongings);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: absence_start_time
  {
    size_t item_size = sizeof(ros_message->absence_start_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_qt_project
size_t max_serialized_size_key_qt_project__msg__SeatStatus(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: seat_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: occupied
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: has_belongings
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: absence_start_time
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = qt_project__msg__SeatStatus;
    is_plain =
      (
      offsetof(DataType, absence_start_time) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _SeatStatus__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const qt_project__msg__SeatStatus * ros_message = static_cast<const qt_project__msg__SeatStatus *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_qt_project__msg__SeatStatus(ros_message, cdr);
}

static bool _SeatStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  qt_project__msg__SeatStatus * ros_message = static_cast<qt_project__msg__SeatStatus *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_qt_project__msg__SeatStatus(cdr, ros_message);
}

static uint32_t _SeatStatus__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_qt_project__msg__SeatStatus(
      untyped_ros_message, 0));
}

static size_t _SeatStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_qt_project__msg__SeatStatus(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SeatStatus = {
  "qt_project::msg",
  "SeatStatus",
  _SeatStatus__cdr_serialize,
  _SeatStatus__cdr_deserialize,
  _SeatStatus__get_serialized_size,
  _SeatStatus__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _SeatStatus__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SeatStatus,
  get_message_typesupport_handle_function,
  &qt_project__msg__SeatStatus__get_type_hash,
  &qt_project__msg__SeatStatus__get_type_description,
  &qt_project__msg__SeatStatus__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, qt_project, msg, SeatStatus)() {
  return &_SeatStatus__type_support;
}

#if defined(__cplusplus)
}
#endif
