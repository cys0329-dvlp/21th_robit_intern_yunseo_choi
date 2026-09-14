// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from qt_project:msg/SeatStatus.idl
// generated code does not contain a copyright notice
#include "qt_project/msg/detail/seat_status__rosidl_typesupport_fastrtps_cpp.hpp"
#include "qt_project/msg/detail/seat_status__functions.h"
#include "qt_project/msg/detail/seat_status__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace qt_project
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qt_project
cdr_serialize(
  const qt_project::msg::SeatStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: seat_id
  cdr << ros_message.seat_id;

  // Member: occupied
  cdr << (ros_message.occupied ? true : false);

  // Member: has_belongings
  cdr << (ros_message.has_belongings ? true : false);

  // Member: absence_start_time
  cdr << ros_message.absence_start_time;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qt_project
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  qt_project::msg::SeatStatus & ros_message)
{
  // Member: seat_id
  cdr >> ros_message.seat_id;

  // Member: occupied
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.occupied = tmp ? true : false;
  }

  // Member: has_belongings
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.has_belongings = tmp ? true : false;
  }

  // Member: absence_start_time
  cdr >> ros_message.absence_start_time;

  return true;
}  // NOLINT(readability/fn_size)


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qt_project
get_serialized_size(
  const qt_project::msg::SeatStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: seat_id
  {
    size_t item_size = sizeof(ros_message.seat_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: occupied
  {
    size_t item_size = sizeof(ros_message.occupied);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: has_belongings
  {
    size_t item_size = sizeof(ros_message.has_belongings);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: absence_start_time
  {
    size_t item_size = sizeof(ros_message.absence_start_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qt_project
max_serialized_size_SeatStatus(
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

  // Member: seat_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // Member: occupied
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: has_belongings
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: absence_start_time
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
    using DataType = qt_project::msg::SeatStatus;
    is_plain =
      (
      offsetof(DataType, absence_start_time) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qt_project
cdr_serialize_key(
  const qt_project::msg::SeatStatus & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: seat_id
  cdr << ros_message.seat_id;

  // Member: occupied
  cdr << (ros_message.occupied ? true : false);

  // Member: has_belongings
  cdr << (ros_message.has_belongings ? true : false);

  // Member: absence_start_time
  cdr << ros_message.absence_start_time;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qt_project
get_serialized_size_key(
  const qt_project::msg::SeatStatus & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: seat_id
  {
    size_t item_size = sizeof(ros_message.seat_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: occupied
  {
    size_t item_size = sizeof(ros_message.occupied);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: has_belongings
  {
    size_t item_size = sizeof(ros_message.has_belongings);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: absence_start_time
  {
    size_t item_size = sizeof(ros_message.absence_start_time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_qt_project
max_serialized_size_key_SeatStatus(
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

  // Member: seat_id
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: occupied
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: has_belongings
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: absence_start_time
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
    using DataType = qt_project::msg::SeatStatus;
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
  auto typed_message =
    static_cast<const qt_project::msg::SeatStatus *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _SeatStatus__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<qt_project::msg::SeatStatus *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _SeatStatus__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const qt_project::msg::SeatStatus *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _SeatStatus__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_SeatStatus(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _SeatStatus__callbacks = {
  "qt_project::msg",
  "SeatStatus",
  _SeatStatus__cdr_serialize,
  _SeatStatus__cdr_deserialize,
  _SeatStatus__get_serialized_size,
  _SeatStatus__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _SeatStatus__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_SeatStatus__callbacks,
  get_message_typesupport_handle_function,
  &qt_project__msg__SeatStatus__get_type_hash,
  &qt_project__msg__SeatStatus__get_type_description,
  &qt_project__msg__SeatStatus__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace qt_project

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_qt_project
const rosidl_message_type_support_t *
get_message_type_support_handle<qt_project::msg::SeatStatus>()
{
  return &qt_project::msg::typesupport_fastrtps_cpp::_SeatStatus__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, qt_project, msg, SeatStatus)() {
  return &qt_project::msg::typesupport_fastrtps_cpp::_SeatStatus__handle;
}

#ifdef __cplusplus
}
#endif
