// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from qt_project:srv/ProcessPenalty.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "qt_project/srv/detail/process_penalty__functions.h"
#include "qt_project/srv/detail/process_penalty__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace qt_project
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _ProcessPenalty_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ProcessPenalty_Request_type_support_ids_t;

static const _ProcessPenalty_Request_type_support_ids_t _ProcessPenalty_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ProcessPenalty_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ProcessPenalty_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ProcessPenalty_Request_type_support_symbol_names_t _ProcessPenalty_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, qt_project, srv, ProcessPenalty_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, qt_project, srv, ProcessPenalty_Request)),
  }
};

typedef struct _ProcessPenalty_Request_type_support_data_t
{
  void * data[2];
} _ProcessPenalty_Request_type_support_data_t;

static _ProcessPenalty_Request_type_support_data_t _ProcessPenalty_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ProcessPenalty_Request_message_typesupport_map = {
  2,
  "qt_project",
  &_ProcessPenalty_Request_message_typesupport_ids.typesupport_identifier[0],
  &_ProcessPenalty_Request_message_typesupport_symbol_names.symbol_name[0],
  &_ProcessPenalty_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ProcessPenalty_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ProcessPenalty_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &qt_project__srv__ProcessPenalty_Request__get_type_hash,
  &qt_project__srv__ProcessPenalty_Request__get_type_description,
  &qt_project__srv__ProcessPenalty_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace qt_project

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<qt_project::srv::ProcessPenalty_Request>()
{
  return &::qt_project::srv::rosidl_typesupport_cpp::ProcessPenalty_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, qt_project, srv, ProcessPenalty_Request)() {
  return get_message_type_support_handle<qt_project::srv::ProcessPenalty_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "qt_project/srv/detail/process_penalty__functions.h"
// already included above
// #include "qt_project/srv/detail/process_penalty__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace qt_project
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _ProcessPenalty_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ProcessPenalty_Response_type_support_ids_t;

static const _ProcessPenalty_Response_type_support_ids_t _ProcessPenalty_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ProcessPenalty_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ProcessPenalty_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ProcessPenalty_Response_type_support_symbol_names_t _ProcessPenalty_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, qt_project, srv, ProcessPenalty_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, qt_project, srv, ProcessPenalty_Response)),
  }
};

typedef struct _ProcessPenalty_Response_type_support_data_t
{
  void * data[2];
} _ProcessPenalty_Response_type_support_data_t;

static _ProcessPenalty_Response_type_support_data_t _ProcessPenalty_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ProcessPenalty_Response_message_typesupport_map = {
  2,
  "qt_project",
  &_ProcessPenalty_Response_message_typesupport_ids.typesupport_identifier[0],
  &_ProcessPenalty_Response_message_typesupport_symbol_names.symbol_name[0],
  &_ProcessPenalty_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ProcessPenalty_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ProcessPenalty_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &qt_project__srv__ProcessPenalty_Response__get_type_hash,
  &qt_project__srv__ProcessPenalty_Response__get_type_description,
  &qt_project__srv__ProcessPenalty_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace qt_project

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<qt_project::srv::ProcessPenalty_Response>()
{
  return &::qt_project::srv::rosidl_typesupport_cpp::ProcessPenalty_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, qt_project, srv, ProcessPenalty_Response)() {
  return get_message_type_support_handle<qt_project::srv::ProcessPenalty_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "qt_project/srv/detail/process_penalty__functions.h"
// already included above
// #include "qt_project/srv/detail/process_penalty__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace qt_project
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _ProcessPenalty_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ProcessPenalty_Event_type_support_ids_t;

static const _ProcessPenalty_Event_type_support_ids_t _ProcessPenalty_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ProcessPenalty_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ProcessPenalty_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ProcessPenalty_Event_type_support_symbol_names_t _ProcessPenalty_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, qt_project, srv, ProcessPenalty_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, qt_project, srv, ProcessPenalty_Event)),
  }
};

typedef struct _ProcessPenalty_Event_type_support_data_t
{
  void * data[2];
} _ProcessPenalty_Event_type_support_data_t;

static _ProcessPenalty_Event_type_support_data_t _ProcessPenalty_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ProcessPenalty_Event_message_typesupport_map = {
  2,
  "qt_project",
  &_ProcessPenalty_Event_message_typesupport_ids.typesupport_identifier[0],
  &_ProcessPenalty_Event_message_typesupport_symbol_names.symbol_name[0],
  &_ProcessPenalty_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ProcessPenalty_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ProcessPenalty_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &qt_project__srv__ProcessPenalty_Event__get_type_hash,
  &qt_project__srv__ProcessPenalty_Event__get_type_description,
  &qt_project__srv__ProcessPenalty_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace qt_project

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<qt_project::srv::ProcessPenalty_Event>()
{
  return &::qt_project::srv::rosidl_typesupport_cpp::ProcessPenalty_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, qt_project, srv, ProcessPenalty_Event)() {
  return get_message_type_support_handle<qt_project::srv::ProcessPenalty_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "qt_project/srv/detail/process_penalty__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace qt_project
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _ProcessPenalty_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ProcessPenalty_type_support_ids_t;

static const _ProcessPenalty_type_support_ids_t _ProcessPenalty_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _ProcessPenalty_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ProcessPenalty_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ProcessPenalty_type_support_symbol_names_t _ProcessPenalty_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, qt_project, srv, ProcessPenalty)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, qt_project, srv, ProcessPenalty)),
  }
};

typedef struct _ProcessPenalty_type_support_data_t
{
  void * data[2];
} _ProcessPenalty_type_support_data_t;

static _ProcessPenalty_type_support_data_t _ProcessPenalty_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ProcessPenalty_service_typesupport_map = {
  2,
  "qt_project",
  &_ProcessPenalty_service_typesupport_ids.typesupport_identifier[0],
  &_ProcessPenalty_service_typesupport_symbol_names.symbol_name[0],
  &_ProcessPenalty_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t ProcessPenalty_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ProcessPenalty_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<qt_project::srv::ProcessPenalty_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<qt_project::srv::ProcessPenalty_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<qt_project::srv::ProcessPenalty_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<qt_project::srv::ProcessPenalty>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<qt_project::srv::ProcessPenalty>,
  &qt_project__srv__ProcessPenalty__get_type_hash,
  &qt_project__srv__ProcessPenalty__get_type_description,
  &qt_project__srv__ProcessPenalty__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace qt_project

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<qt_project::srv::ProcessPenalty>()
{
  return &::qt_project::srv::rosidl_typesupport_cpp::ProcessPenalty_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, qt_project, srv, ProcessPenalty)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<qt_project::srv::ProcessPenalty>();
}

#ifdef __cplusplus
}
#endif
