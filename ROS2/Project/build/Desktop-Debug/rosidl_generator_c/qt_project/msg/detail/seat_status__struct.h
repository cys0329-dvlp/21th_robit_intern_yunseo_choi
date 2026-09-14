// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qt_project:msg/SeatStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qt_project/msg/seat_status.h"


#ifndef QT_PROJECT__MSG__DETAIL__SEAT_STATUS__STRUCT_H_
#define QT_PROJECT__MSG__DETAIL__SEAT_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/SeatStatus in the package qt_project.
typedef struct qt_project__msg__SeatStatus
{
  int32_t seat_id;
  bool occupied;
  bool has_belongings;
  int64_t absence_start_time;
} qt_project__msg__SeatStatus;

// Struct for a sequence of qt_project__msg__SeatStatus.
typedef struct qt_project__msg__SeatStatus__Sequence
{
  qt_project__msg__SeatStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qt_project__msg__SeatStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QT_PROJECT__MSG__DETAIL__SEAT_STATUS__STRUCT_H_
