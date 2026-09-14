// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qt_project:srv/ProcessPenalty.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qt_project/srv/process_penalty.h"


#ifndef QT_PROJECT__SRV__DETAIL__PROCESS_PENALTY__STRUCT_H_
#define QT_PROJECT__SRV__DETAIL__PROCESS_PENALTY__STRUCT_H_

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

/// Struct defined in srv/ProcessPenalty in the package qt_project.
typedef struct qt_project__srv__ProcessPenalty_Request
{
  rosidl_runtime_c__int32__Sequence seat_ids;
} qt_project__srv__ProcessPenalty_Request;

// Struct for a sequence of qt_project__srv__ProcessPenalty_Request.
typedef struct qt_project__srv__ProcessPenalty_Request__Sequence
{
  qt_project__srv__ProcessPenalty_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qt_project__srv__ProcessPenalty_Request__Sequence;

// Constants defined in the message

/// Struct defined in srv/ProcessPenalty in the package qt_project.
typedef struct qt_project__srv__ProcessPenalty_Response
{
  bool success;
} qt_project__srv__ProcessPenalty_Response;

// Struct for a sequence of qt_project__srv__ProcessPenalty_Response.
typedef struct qt_project__srv__ProcessPenalty_Response__Sequence
{
  qt_project__srv__ProcessPenalty_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qt_project__srv__ProcessPenalty_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  qt_project__srv__ProcessPenalty_Event__request__MAX_SIZE = 1
};
// response
enum
{
  qt_project__srv__ProcessPenalty_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/ProcessPenalty in the package qt_project.
typedef struct qt_project__srv__ProcessPenalty_Event
{
  service_msgs__msg__ServiceEventInfo info;
  qt_project__srv__ProcessPenalty_Request__Sequence request;
  qt_project__srv__ProcessPenalty_Response__Sequence response;
} qt_project__srv__ProcessPenalty_Event;

// Struct for a sequence of qt_project__srv__ProcessPenalty_Event.
typedef struct qt_project__srv__ProcessPenalty_Event__Sequence
{
  qt_project__srv__ProcessPenalty_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qt_project__srv__ProcessPenalty_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QT_PROJECT__SRV__DETAIL__PROCESS_PENALTY__STRUCT_H_
