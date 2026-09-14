// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from qt_project:srv/GetRoute.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "qt_project/srv/detail/get_route__rosidl_typesupport_introspection_c.h"
#include "qt_project/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "qt_project/srv/detail/get_route__functions.h"
#include "qt_project/srv/detail/get_route__struct.h"


// Include directives for member types
// Member `seat_ids`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__GetRoute_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  qt_project__srv__GetRoute_Request__init(message_memory);
}

void qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__GetRoute_Request_fini_function(void * message_memory)
{
  qt_project__srv__GetRoute_Request__fini(message_memory);
}

size_t qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__size_function__GetRoute_Request__seat_ids(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__get_const_function__GetRoute_Request__seat_ids(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__get_function__GetRoute_Request__seat_ids(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__fetch_function__GetRoute_Request__seat_ids(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__get_const_function__GetRoute_Request__seat_ids(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__assign_function__GetRoute_Request__seat_ids(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__get_function__GetRoute_Request__seat_ids(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__resize_function__GetRoute_Request__seat_ids(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__GetRoute_Request_message_member_array[1] = {
  {
    "seat_ids",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qt_project__srv__GetRoute_Request, seat_ids),  // bytes offset in struct
    NULL,  // default value
    qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__size_function__GetRoute_Request__seat_ids,  // size() function pointer
    qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__get_const_function__GetRoute_Request__seat_ids,  // get_const(index) function pointer
    qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__get_function__GetRoute_Request__seat_ids,  // get(index) function pointer
    qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__fetch_function__GetRoute_Request__seat_ids,  // fetch(index, &value) function pointer
    qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__assign_function__GetRoute_Request__seat_ids,  // assign(index, value) function pointer
    qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__resize_function__GetRoute_Request__seat_ids  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__GetRoute_Request_message_members = {
  "qt_project__srv",  // message namespace
  "GetRoute_Request",  // message name
  1,  // number of fields
  sizeof(qt_project__srv__GetRoute_Request),
  false,  // has_any_key_member_
  qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__GetRoute_Request_message_member_array,  // message members
  qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__GetRoute_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__GetRoute_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__GetRoute_Request_message_type_support_handle = {
  0,
  &qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__GetRoute_Request_message_members,
  get_message_typesupport_handle_function,
  &qt_project__srv__GetRoute_Request__get_type_hash,
  &qt_project__srv__GetRoute_Request__get_type_description,
  &qt_project__srv__GetRoute_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_qt_project
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qt_project, srv, GetRoute_Request)() {
  if (!qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__GetRoute_Request_message_type_support_handle.typesupport_identifier) {
    qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__GetRoute_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__GetRoute_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "qt_project/srv/detail/get_route__rosidl_typesupport_introspection_c.h"
// already included above
// #include "qt_project/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "qt_project/srv/detail/get_route__functions.h"
// already included above
// #include "qt_project/srv/detail/get_route__struct.h"


// Include directives for member types
// Member `route`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__GetRoute_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  qt_project__srv__GetRoute_Response__init(message_memory);
}

void qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__GetRoute_Response_fini_function(void * message_memory)
{
  qt_project__srv__GetRoute_Response__fini(message_memory);
}

size_t qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__size_function__GetRoute_Response__route(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__get_const_function__GetRoute_Response__route(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__get_function__GetRoute_Response__route(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__fetch_function__GetRoute_Response__route(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__get_const_function__GetRoute_Response__route(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__assign_function__GetRoute_Response__route(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__get_function__GetRoute_Response__route(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__resize_function__GetRoute_Response__route(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__GetRoute_Response_message_member_array[1] = {
  {
    "route",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qt_project__srv__GetRoute_Response, route),  // bytes offset in struct
    NULL,  // default value
    qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__size_function__GetRoute_Response__route,  // size() function pointer
    qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__get_const_function__GetRoute_Response__route,  // get_const(index) function pointer
    qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__get_function__GetRoute_Response__route,  // get(index) function pointer
    qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__fetch_function__GetRoute_Response__route,  // fetch(index, &value) function pointer
    qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__assign_function__GetRoute_Response__route,  // assign(index, value) function pointer
    qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__resize_function__GetRoute_Response__route  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__GetRoute_Response_message_members = {
  "qt_project__srv",  // message namespace
  "GetRoute_Response",  // message name
  1,  // number of fields
  sizeof(qt_project__srv__GetRoute_Response),
  false,  // has_any_key_member_
  qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__GetRoute_Response_message_member_array,  // message members
  qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__GetRoute_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__GetRoute_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__GetRoute_Response_message_type_support_handle = {
  0,
  &qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__GetRoute_Response_message_members,
  get_message_typesupport_handle_function,
  &qt_project__srv__GetRoute_Response__get_type_hash,
  &qt_project__srv__GetRoute_Response__get_type_description,
  &qt_project__srv__GetRoute_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_qt_project
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qt_project, srv, GetRoute_Response)() {
  if (!qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__GetRoute_Response_message_type_support_handle.typesupport_identifier) {
    qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__GetRoute_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__GetRoute_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "qt_project/srv/detail/get_route__rosidl_typesupport_introspection_c.h"
// already included above
// #include "qt_project/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "qt_project/srv/detail/get_route__functions.h"
// already included above
// #include "qt_project/srv/detail/get_route__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "qt_project/srv/get_route.h"
// Member `request`
// Member `response`
// already included above
// #include "qt_project/srv/detail/get_route__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__GetRoute_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  qt_project__srv__GetRoute_Event__init(message_memory);
}

void qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__GetRoute_Event_fini_function(void * message_memory)
{
  qt_project__srv__GetRoute_Event__fini(message_memory);
}

size_t qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__size_function__GetRoute_Event__request(
  const void * untyped_member)
{
  const qt_project__srv__GetRoute_Request__Sequence * member =
    (const qt_project__srv__GetRoute_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__get_const_function__GetRoute_Event__request(
  const void * untyped_member, size_t index)
{
  const qt_project__srv__GetRoute_Request__Sequence * member =
    (const qt_project__srv__GetRoute_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__get_function__GetRoute_Event__request(
  void * untyped_member, size_t index)
{
  qt_project__srv__GetRoute_Request__Sequence * member =
    (qt_project__srv__GetRoute_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__fetch_function__GetRoute_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const qt_project__srv__GetRoute_Request * item =
    ((const qt_project__srv__GetRoute_Request *)
    qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__get_const_function__GetRoute_Event__request(untyped_member, index));
  qt_project__srv__GetRoute_Request * value =
    (qt_project__srv__GetRoute_Request *)(untyped_value);
  *value = *item;
}

void qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__assign_function__GetRoute_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  qt_project__srv__GetRoute_Request * item =
    ((qt_project__srv__GetRoute_Request *)
    qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__get_function__GetRoute_Event__request(untyped_member, index));
  const qt_project__srv__GetRoute_Request * value =
    (const qt_project__srv__GetRoute_Request *)(untyped_value);
  *item = *value;
}

bool qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__resize_function__GetRoute_Event__request(
  void * untyped_member, size_t size)
{
  qt_project__srv__GetRoute_Request__Sequence * member =
    (qt_project__srv__GetRoute_Request__Sequence *)(untyped_member);
  qt_project__srv__GetRoute_Request__Sequence__fini(member);
  return qt_project__srv__GetRoute_Request__Sequence__init(member, size);
}

size_t qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__size_function__GetRoute_Event__response(
  const void * untyped_member)
{
  const qt_project__srv__GetRoute_Response__Sequence * member =
    (const qt_project__srv__GetRoute_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__get_const_function__GetRoute_Event__response(
  const void * untyped_member, size_t index)
{
  const qt_project__srv__GetRoute_Response__Sequence * member =
    (const qt_project__srv__GetRoute_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__get_function__GetRoute_Event__response(
  void * untyped_member, size_t index)
{
  qt_project__srv__GetRoute_Response__Sequence * member =
    (qt_project__srv__GetRoute_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__fetch_function__GetRoute_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const qt_project__srv__GetRoute_Response * item =
    ((const qt_project__srv__GetRoute_Response *)
    qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__get_const_function__GetRoute_Event__response(untyped_member, index));
  qt_project__srv__GetRoute_Response * value =
    (qt_project__srv__GetRoute_Response *)(untyped_value);
  *value = *item;
}

void qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__assign_function__GetRoute_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  qt_project__srv__GetRoute_Response * item =
    ((qt_project__srv__GetRoute_Response *)
    qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__get_function__GetRoute_Event__response(untyped_member, index));
  const qt_project__srv__GetRoute_Response * value =
    (const qt_project__srv__GetRoute_Response *)(untyped_value);
  *item = *value;
}

bool qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__resize_function__GetRoute_Event__response(
  void * untyped_member, size_t size)
{
  qt_project__srv__GetRoute_Response__Sequence * member =
    (qt_project__srv__GetRoute_Response__Sequence *)(untyped_member);
  qt_project__srv__GetRoute_Response__Sequence__fini(member);
  return qt_project__srv__GetRoute_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__GetRoute_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(qt_project__srv__GetRoute_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(qt_project__srv__GetRoute_Event, request),  // bytes offset in struct
    NULL,  // default value
    qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__size_function__GetRoute_Event__request,  // size() function pointer
    qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__get_const_function__GetRoute_Event__request,  // get_const(index) function pointer
    qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__get_function__GetRoute_Event__request,  // get(index) function pointer
    qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__fetch_function__GetRoute_Event__request,  // fetch(index, &value) function pointer
    qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__assign_function__GetRoute_Event__request,  // assign(index, value) function pointer
    qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__resize_function__GetRoute_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(qt_project__srv__GetRoute_Event, response),  // bytes offset in struct
    NULL,  // default value
    qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__size_function__GetRoute_Event__response,  // size() function pointer
    qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__get_const_function__GetRoute_Event__response,  // get_const(index) function pointer
    qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__get_function__GetRoute_Event__response,  // get(index) function pointer
    qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__fetch_function__GetRoute_Event__response,  // fetch(index, &value) function pointer
    qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__assign_function__GetRoute_Event__response,  // assign(index, value) function pointer
    qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__resize_function__GetRoute_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__GetRoute_Event_message_members = {
  "qt_project__srv",  // message namespace
  "GetRoute_Event",  // message name
  3,  // number of fields
  sizeof(qt_project__srv__GetRoute_Event),
  false,  // has_any_key_member_
  qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__GetRoute_Event_message_member_array,  // message members
  qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__GetRoute_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__GetRoute_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__GetRoute_Event_message_type_support_handle = {
  0,
  &qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__GetRoute_Event_message_members,
  get_message_typesupport_handle_function,
  &qt_project__srv__GetRoute_Event__get_type_hash,
  &qt_project__srv__GetRoute_Event__get_type_description,
  &qt_project__srv__GetRoute_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_qt_project
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qt_project, srv, GetRoute_Event)() {
  qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__GetRoute_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__GetRoute_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qt_project, srv, GetRoute_Request)();
  qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__GetRoute_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qt_project, srv, GetRoute_Response)();
  if (!qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__GetRoute_Event_message_type_support_handle.typesupport_identifier) {
    qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__GetRoute_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__GetRoute_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "qt_project/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "qt_project/srv/detail/get_route__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers qt_project__srv__detail__get_route__rosidl_typesupport_introspection_c__GetRoute_service_members = {
  "qt_project__srv",  // service namespace
  "GetRoute",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // qt_project__srv__detail__get_route__rosidl_typesupport_introspection_c__GetRoute_Request_message_type_support_handle,
  NULL,  // response message
  // qt_project__srv__detail__get_route__rosidl_typesupport_introspection_c__GetRoute_Response_message_type_support_handle
  NULL  // event_message
  // qt_project__srv__detail__get_route__rosidl_typesupport_introspection_c__GetRoute_Response_message_type_support_handle
};


static rosidl_service_type_support_t qt_project__srv__detail__get_route__rosidl_typesupport_introspection_c__GetRoute_service_type_support_handle = {
  0,
  &qt_project__srv__detail__get_route__rosidl_typesupport_introspection_c__GetRoute_service_members,
  get_service_typesupport_handle_function,
  &qt_project__srv__GetRoute_Request__rosidl_typesupport_introspection_c__GetRoute_Request_message_type_support_handle,
  &qt_project__srv__GetRoute_Response__rosidl_typesupport_introspection_c__GetRoute_Response_message_type_support_handle,
  &qt_project__srv__GetRoute_Event__rosidl_typesupport_introspection_c__GetRoute_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    qt_project,
    srv,
    GetRoute
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    qt_project,
    srv,
    GetRoute
  ),
  &qt_project__srv__GetRoute__get_type_hash,
  &qt_project__srv__GetRoute__get_type_description,
  &qt_project__srv__GetRoute__get_type_description_sources,
};

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qt_project, srv, GetRoute_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qt_project, srv, GetRoute_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qt_project, srv, GetRoute_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_qt_project
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qt_project, srv, GetRoute)(void) {
  if (!qt_project__srv__detail__get_route__rosidl_typesupport_introspection_c__GetRoute_service_type_support_handle.typesupport_identifier) {
    qt_project__srv__detail__get_route__rosidl_typesupport_introspection_c__GetRoute_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)qt_project__srv__detail__get_route__rosidl_typesupport_introspection_c__GetRoute_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qt_project, srv, GetRoute_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qt_project, srv, GetRoute_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, qt_project, srv, GetRoute_Event)()->data;
  }

  return &qt_project__srv__detail__get_route__rosidl_typesupport_introspection_c__GetRoute_service_type_support_handle;
}
