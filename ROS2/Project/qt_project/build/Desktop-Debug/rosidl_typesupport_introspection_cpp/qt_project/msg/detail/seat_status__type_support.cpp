// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from qt_project:msg/SeatStatus.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "qt_project/msg/detail/seat_status__functions.h"
#include "qt_project/msg/detail/seat_status__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace qt_project
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void SeatStatus_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) qt_project::msg::SeatStatus(_init);
}

void SeatStatus_fini_function(void * message_memory)
{
  auto typed_message = static_cast<qt_project::msg::SeatStatus *>(message_memory);
  typed_message->~SeatStatus();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SeatStatus_message_member_array[4] = {
  {
    "seat_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qt_project::msg::SeatStatus, seat_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "occupied",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qt_project::msg::SeatStatus, occupied),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "has_belongings",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qt_project::msg::SeatStatus, has_belongings),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "absence_start_time",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qt_project::msg::SeatStatus, absence_start_time),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SeatStatus_message_members = {
  "qt_project::msg",  // message namespace
  "SeatStatus",  // message name
  4,  // number of fields
  sizeof(qt_project::msg::SeatStatus),
  false,  // has_any_key_member_
  SeatStatus_message_member_array,  // message members
  SeatStatus_init_function,  // function to initialize message memory (memory has to be allocated)
  SeatStatus_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SeatStatus_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SeatStatus_message_members,
  get_message_typesupport_handle_function,
  &qt_project__msg__SeatStatus__get_type_hash,
  &qt_project__msg__SeatStatus__get_type_description,
  &qt_project__msg__SeatStatus__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace qt_project


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<qt_project::msg::SeatStatus>()
{
  return &::qt_project::msg::rosidl_typesupport_introspection_cpp::SeatStatus_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, qt_project, msg, SeatStatus)() {
  return &::qt_project::msg::rosidl_typesupport_introspection_cpp::SeatStatus_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
