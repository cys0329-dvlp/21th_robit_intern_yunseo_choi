// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from qt_project:msg/SeatStatus.idl
// generated code does not contain a copyright notice

#include "qt_project/msg/detail/seat_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_qt_project
const rosidl_type_hash_t *
qt_project__msg__SeatStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc4, 0xf3, 0x38, 0x9a, 0xb9, 0xa0, 0x07, 0x81,
      0x2a, 0x33, 0x4a, 0x45, 0xa9, 0x1e, 0x1b, 0x19,
      0xb8, 0x92, 0x5f, 0x30, 0xc4, 0x03, 0x56, 0xef,
      0x1b, 0x0f, 0x1f, 0x95, 0x08, 0x60, 0x10, 0x0f,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char qt_project__msg__SeatStatus__TYPE_NAME[] = "qt_project/msg/SeatStatus";

// Define type names, field names, and default values
static char qt_project__msg__SeatStatus__FIELD_NAME__seat_id[] = "seat_id";
static char qt_project__msg__SeatStatus__FIELD_NAME__occupied[] = "occupied";
static char qt_project__msg__SeatStatus__FIELD_NAME__has_belongings[] = "has_belongings";
static char qt_project__msg__SeatStatus__FIELD_NAME__absence_start_time[] = "absence_start_time";

static rosidl_runtime_c__type_description__Field qt_project__msg__SeatStatus__FIELDS[] = {
  {
    {qt_project__msg__SeatStatus__FIELD_NAME__seat_id, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {qt_project__msg__SeatStatus__FIELD_NAME__occupied, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {qt_project__msg__SeatStatus__FIELD_NAME__has_belongings, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {qt_project__msg__SeatStatus__FIELD_NAME__absence_start_time, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
qt_project__msg__SeatStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {qt_project__msg__SeatStatus__TYPE_NAME, 25, 25},
      {qt_project__msg__SeatStatus__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32 seat_id \n"
  "bool occupied \n"
  "bool has_belongings  \n"
  "int64 absence_start_time";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
qt_project__msg__SeatStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {qt_project__msg__SeatStatus__TYPE_NAME, 25, 25},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 76, 76},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
qt_project__msg__SeatStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *qt_project__msg__SeatStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
