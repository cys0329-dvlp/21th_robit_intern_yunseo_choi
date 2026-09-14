// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from qt_project:msg/SeatCommand.idl
// generated code does not contain a copyright notice

#include "qt_project/msg/detail/seat_command__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_qt_project
const rosidl_type_hash_t *
qt_project__msg__SeatCommand__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc5, 0x68, 0x19, 0x95, 0xe2, 0xa1, 0x39, 0xd6,
      0xf7, 0xef, 0xd6, 0xa1, 0x62, 0x88, 0x1b, 0xa0,
      0x67, 0x97, 0xb4, 0x6c, 0x79, 0x7e, 0xaf, 0x99,
      0xa3, 0xc6, 0x88, 0x79, 0xeb, 0x88, 0x0e, 0xcb,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char qt_project__msg__SeatCommand__TYPE_NAME[] = "qt_project/msg/SeatCommand";

// Define type names, field names, and default values
static char qt_project__msg__SeatCommand__FIELD_NAME__seat_id[] = "seat_id";
static char qt_project__msg__SeatCommand__FIELD_NAME__occupied[] = "occupied";
static char qt_project__msg__SeatCommand__FIELD_NAME__has_belongings[] = "has_belongings";

static rosidl_runtime_c__type_description__Field qt_project__msg__SeatCommand__FIELDS[] = {
  {
    {qt_project__msg__SeatCommand__FIELD_NAME__seat_id, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {qt_project__msg__SeatCommand__FIELD_NAME__occupied, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {qt_project__msg__SeatCommand__FIELD_NAME__has_belongings, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
qt_project__msg__SeatCommand__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {qt_project__msg__SeatCommand__TYPE_NAME, 26, 26},
      {qt_project__msg__SeatCommand__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32 seat_id\n"
  "bool occupied\n"
  "bool has_belongings";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
qt_project__msg__SeatCommand__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {qt_project__msg__SeatCommand__TYPE_NAME, 26, 26},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 47, 47},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
qt_project__msg__SeatCommand__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *qt_project__msg__SeatCommand__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
