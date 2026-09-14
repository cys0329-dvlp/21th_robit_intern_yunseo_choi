// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from qt_project:msg/SeatCommand.idl
// generated code does not contain a copyright notice
#include "qt_project/msg/detail/seat_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
qt_project__msg__SeatCommand__init(qt_project__msg__SeatCommand * msg)
{
  if (!msg) {
    return false;
  }
  // seat_id
  // occupied
  // has_belongings
  return true;
}

void
qt_project__msg__SeatCommand__fini(qt_project__msg__SeatCommand * msg)
{
  if (!msg) {
    return;
  }
  // seat_id
  // occupied
  // has_belongings
}

bool
qt_project__msg__SeatCommand__are_equal(const qt_project__msg__SeatCommand * lhs, const qt_project__msg__SeatCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // seat_id
  if (lhs->seat_id != rhs->seat_id) {
    return false;
  }
  // occupied
  if (lhs->occupied != rhs->occupied) {
    return false;
  }
  // has_belongings
  if (lhs->has_belongings != rhs->has_belongings) {
    return false;
  }
  return true;
}

bool
qt_project__msg__SeatCommand__copy(
  const qt_project__msg__SeatCommand * input,
  qt_project__msg__SeatCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // seat_id
  output->seat_id = input->seat_id;
  // occupied
  output->occupied = input->occupied;
  // has_belongings
  output->has_belongings = input->has_belongings;
  return true;
}

qt_project__msg__SeatCommand *
qt_project__msg__SeatCommand__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qt_project__msg__SeatCommand * msg = (qt_project__msg__SeatCommand *)allocator.allocate(sizeof(qt_project__msg__SeatCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qt_project__msg__SeatCommand));
  bool success = qt_project__msg__SeatCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
qt_project__msg__SeatCommand__destroy(qt_project__msg__SeatCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    qt_project__msg__SeatCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
qt_project__msg__SeatCommand__Sequence__init(qt_project__msg__SeatCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qt_project__msg__SeatCommand * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(qt_project__msg__SeatCommand)) {
      return false;
    }
    data = (qt_project__msg__SeatCommand *)allocator.zero_allocate(size, sizeof(qt_project__msg__SeatCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = qt_project__msg__SeatCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        qt_project__msg__SeatCommand__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
qt_project__msg__SeatCommand__Sequence__fini(qt_project__msg__SeatCommand__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      qt_project__msg__SeatCommand__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

qt_project__msg__SeatCommand__Sequence *
qt_project__msg__SeatCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qt_project__msg__SeatCommand__Sequence * array = (qt_project__msg__SeatCommand__Sequence *)allocator.allocate(sizeof(qt_project__msg__SeatCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = qt_project__msg__SeatCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
qt_project__msg__SeatCommand__Sequence__destroy(qt_project__msg__SeatCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    qt_project__msg__SeatCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
qt_project__msg__SeatCommand__Sequence__are_equal(const qt_project__msg__SeatCommand__Sequence * lhs, const qt_project__msg__SeatCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!qt_project__msg__SeatCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
qt_project__msg__SeatCommand__Sequence__copy(
  const qt_project__msg__SeatCommand__Sequence * input,
  qt_project__msg__SeatCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(qt_project__msg__SeatCommand)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(qt_project__msg__SeatCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    qt_project__msg__SeatCommand * data =
      (qt_project__msg__SeatCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!qt_project__msg__SeatCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          qt_project__msg__SeatCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!qt_project__msg__SeatCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
