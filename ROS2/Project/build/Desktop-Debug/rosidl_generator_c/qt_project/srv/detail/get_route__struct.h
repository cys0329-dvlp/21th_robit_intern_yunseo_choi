// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qt_project:srv/GetRoute.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qt_project/srv/get_route.h"


#ifndef QT_PROJECT__SRV__DETAIL__GET_ROUTE__STRUCT_H_
#define QT_PROJECT__SRV__DETAIL__GET_ROUTE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'seat_ids'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/GetRoute in the package qt_project.
typedef struct qt_project__srv__GetRoute_Request
{
  rosidl_runtime_c__int32__Sequence seat_ids;
} qt_project__srv__GetRoute_Request;

// Struct for a sequence of qt_project__srv__GetRoute_Request.
typedef struct qt_project__srv__GetRoute_Request__Sequence
{
  qt_project__srv__GetRoute_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qt_project__srv__GetRoute_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'route'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/GetRoute in the package qt_project.
typedef struct qt_project__srv__GetRoute_Response
{
  rosidl_runtime_c__int32__Sequence route;
} qt_project__srv__GetRoute_Response;

// Struct for a sequence of qt_project__srv__GetRoute_Response.
typedef struct qt_project__srv__GetRoute_Response__Sequence
{
  qt_project__srv__GetRoute_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qt_project__srv__GetRoute_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  qt_project__srv__GetRoute_Event__request__MAX_SIZE = 1
};
// response
enum
{
  qt_project__srv__GetRoute_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/GetRoute in the package qt_project.
typedef struct qt_project__srv__GetRoute_Event
{
  service_msgs__msg__ServiceEventInfo info;
  qt_project__srv__GetRoute_Request__Sequence request;
  qt_project__srv__GetRoute_Response__Sequence response;
} qt_project__srv__GetRoute_Event;

// Struct for a sequence of qt_project__srv__GetRoute_Event.
typedef struct qt_project__srv__GetRoute_Event__Sequence
{
  qt_project__srv__GetRoute_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qt_project__srv__GetRoute_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QT_PROJECT__SRV__DETAIL__GET_ROUTE__STRUCT_H_
