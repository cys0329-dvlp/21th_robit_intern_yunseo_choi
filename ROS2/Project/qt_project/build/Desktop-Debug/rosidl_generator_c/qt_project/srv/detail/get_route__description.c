// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from qt_project:srv/GetRoute.idl
// generated code does not contain a copyright notice

#include "qt_project/srv/detail/get_route__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_qt_project
const rosidl_type_hash_t *
qt_project__srv__GetRoute__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xb2, 0x00, 0xa2, 0xc1, 0x15, 0x03, 0x03, 0xf1,
      0xf6, 0x4f, 0xe2, 0x7c, 0xac, 0xb5, 0x6e, 0x66,
      0x76, 0xb0, 0x85, 0xaa, 0xf1, 0x6d, 0xcf, 0x9f,
      0xbe, 0x6f, 0x45, 0x96, 0xf1, 0x3d, 0x82, 0xa1,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_qt_project
const rosidl_type_hash_t *
qt_project__srv__GetRoute_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x45, 0x6e, 0xef, 0xd4, 0x94, 0x72, 0xf2, 0x28,
      0x97, 0x53, 0x0d, 0x0f, 0xfd, 0xfb, 0xbe, 0x58,
      0x92, 0x98, 0xae, 0xf8, 0xfe, 0xed, 0x87, 0x43,
      0xf9, 0x6c, 0xa6, 0x47, 0x7c, 0xbc, 0x74, 0xa3,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_qt_project
const rosidl_type_hash_t *
qt_project__srv__GetRoute_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x93, 0xd3, 0xfc, 0x10, 0x33, 0xe3, 0x70, 0x71,
      0x2f, 0x83, 0x18, 0x14, 0xc1, 0xdb, 0xab, 0x7e,
      0xb6, 0xb0, 0x5e, 0xe2, 0x7f, 0x2b, 0x83, 0xf5,
      0xc7, 0xa0, 0x32, 0x14, 0x0e, 0x68, 0xf9, 0xc0,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_qt_project
const rosidl_type_hash_t *
qt_project__srv__GetRoute_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x5c, 0xc2, 0xaa, 0x2e, 0xfd, 0xfa, 0x63, 0x26,
      0x0c, 0x66, 0xe0, 0x67, 0x83, 0x03, 0xc1, 0x7e,
      0xc9, 0x31, 0x69, 0x08, 0xed, 0xf8, 0x59, 0x97,
      0x57, 0x8b, 0xdc, 0xf3, 0x20, 0x3c, 0x9d, 0xa2,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char qt_project__srv__GetRoute__TYPE_NAME[] = "qt_project/srv/GetRoute";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char qt_project__srv__GetRoute_Event__TYPE_NAME[] = "qt_project/srv/GetRoute_Event";
static char qt_project__srv__GetRoute_Request__TYPE_NAME[] = "qt_project/srv/GetRoute_Request";
static char qt_project__srv__GetRoute_Response__TYPE_NAME[] = "qt_project/srv/GetRoute_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char qt_project__srv__GetRoute__FIELD_NAME__request_message[] = "request_message";
static char qt_project__srv__GetRoute__FIELD_NAME__response_message[] = "response_message";
static char qt_project__srv__GetRoute__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field qt_project__srv__GetRoute__FIELDS[] = {
  {
    {qt_project__srv__GetRoute__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {qt_project__srv__GetRoute_Request__TYPE_NAME, 31, 31},
    },
    {NULL, 0, 0},
  },
  {
    {qt_project__srv__GetRoute__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {qt_project__srv__GetRoute_Response__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
  {
    {qt_project__srv__GetRoute__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {qt_project__srv__GetRoute_Event__TYPE_NAME, 29, 29},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription qt_project__srv__GetRoute__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {qt_project__srv__GetRoute_Event__TYPE_NAME, 29, 29},
    {NULL, 0, 0},
  },
  {
    {qt_project__srv__GetRoute_Request__TYPE_NAME, 31, 31},
    {NULL, 0, 0},
  },
  {
    {qt_project__srv__GetRoute_Response__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
qt_project__srv__GetRoute__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {qt_project__srv__GetRoute__TYPE_NAME, 23, 23},
      {qt_project__srv__GetRoute__FIELDS, 3, 3},
    },
    {qt_project__srv__GetRoute__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = qt_project__srv__GetRoute_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = qt_project__srv__GetRoute_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = qt_project__srv__GetRoute_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char qt_project__srv__GetRoute_Request__FIELD_NAME__seat_ids[] = "seat_ids";

static rosidl_runtime_c__type_description__Field qt_project__srv__GetRoute_Request__FIELDS[] = {
  {
    {qt_project__srv__GetRoute_Request__FIELD_NAME__seat_ids, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
qt_project__srv__GetRoute_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {qt_project__srv__GetRoute_Request__TYPE_NAME, 31, 31},
      {qt_project__srv__GetRoute_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char qt_project__srv__GetRoute_Response__FIELD_NAME__route[] = "route";

static rosidl_runtime_c__type_description__Field qt_project__srv__GetRoute_Response__FIELDS[] = {
  {
    {qt_project__srv__GetRoute_Response__FIELD_NAME__route, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32_UNBOUNDED_SEQUENCE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
qt_project__srv__GetRoute_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {qt_project__srv__GetRoute_Response__TYPE_NAME, 32, 32},
      {qt_project__srv__GetRoute_Response__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char qt_project__srv__GetRoute_Event__FIELD_NAME__info[] = "info";
static char qt_project__srv__GetRoute_Event__FIELD_NAME__request[] = "request";
static char qt_project__srv__GetRoute_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field qt_project__srv__GetRoute_Event__FIELDS[] = {
  {
    {qt_project__srv__GetRoute_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {qt_project__srv__GetRoute_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {qt_project__srv__GetRoute_Request__TYPE_NAME, 31, 31},
    },
    {NULL, 0, 0},
  },
  {
    {qt_project__srv__GetRoute_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {qt_project__srv__GetRoute_Response__TYPE_NAME, 32, 32},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription qt_project__srv__GetRoute_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {qt_project__srv__GetRoute_Request__TYPE_NAME, 31, 31},
    {NULL, 0, 0},
  },
  {
    {qt_project__srv__GetRoute_Response__TYPE_NAME, 32, 32},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
qt_project__srv__GetRoute_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {qt_project__srv__GetRoute_Event__TYPE_NAME, 29, 29},
      {qt_project__srv__GetRoute_Event__FIELDS, 3, 3},
    },
    {qt_project__srv__GetRoute_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = qt_project__srv__GetRoute_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = qt_project__srv__GetRoute_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32[] seat_ids\n"
  "---\n"
  "int32[] route";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
qt_project__srv__GetRoute__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {qt_project__srv__GetRoute__TYPE_NAME, 23, 23},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 34, 34},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
qt_project__srv__GetRoute_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {qt_project__srv__GetRoute_Request__TYPE_NAME, 31, 31},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
qt_project__srv__GetRoute_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {qt_project__srv__GetRoute_Response__TYPE_NAME, 32, 32},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
qt_project__srv__GetRoute_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {qt_project__srv__GetRoute_Event__TYPE_NAME, 29, 29},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
qt_project__srv__GetRoute__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *qt_project__srv__GetRoute__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *qt_project__srv__GetRoute_Event__get_individual_type_description_source(NULL);
    sources[3] = *qt_project__srv__GetRoute_Request__get_individual_type_description_source(NULL);
    sources[4] = *qt_project__srv__GetRoute_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
qt_project__srv__GetRoute_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *qt_project__srv__GetRoute_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
qt_project__srv__GetRoute_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *qt_project__srv__GetRoute_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
qt_project__srv__GetRoute_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *qt_project__srv__GetRoute_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *qt_project__srv__GetRoute_Request__get_individual_type_description_source(NULL);
    sources[3] = *qt_project__srv__GetRoute_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
