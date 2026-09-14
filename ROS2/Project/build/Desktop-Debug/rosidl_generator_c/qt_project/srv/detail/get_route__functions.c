// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from qt_project:srv/GetRoute.idl
// generated code does not contain a copyright notice
#include "qt_project/srv/detail/get_route__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `seat_ids`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
qt_project__srv__GetRoute_Request__init(qt_project__srv__GetRoute_Request * msg)
{
  if (!msg) {
    return false;
  }
  // seat_ids
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->seat_ids, 0)) {
    qt_project__srv__GetRoute_Request__fini(msg);
    return false;
  }
  return true;
}

void
qt_project__srv__GetRoute_Request__fini(qt_project__srv__GetRoute_Request * msg)
{
  if (!msg) {
    return;
  }
  // seat_ids
  rosidl_runtime_c__int32__Sequence__fini(&msg->seat_ids);
}

bool
qt_project__srv__GetRoute_Request__are_equal(const qt_project__srv__GetRoute_Request * lhs, const qt_project__srv__GetRoute_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // seat_ids
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->seat_ids), &(rhs->seat_ids)))
  {
    return false;
  }
  return true;
}

bool
qt_project__srv__GetRoute_Request__copy(
  const qt_project__srv__GetRoute_Request * input,
  qt_project__srv__GetRoute_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // seat_ids
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->seat_ids), &(output->seat_ids)))
  {
    return false;
  }
  return true;
}

qt_project__srv__GetRoute_Request *
qt_project__srv__GetRoute_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qt_project__srv__GetRoute_Request * msg = (qt_project__srv__GetRoute_Request *)allocator.allocate(sizeof(qt_project__srv__GetRoute_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qt_project__srv__GetRoute_Request));
  bool success = qt_project__srv__GetRoute_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
qt_project__srv__GetRoute_Request__destroy(qt_project__srv__GetRoute_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    qt_project__srv__GetRoute_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
qt_project__srv__GetRoute_Request__Sequence__init(qt_project__srv__GetRoute_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qt_project__srv__GetRoute_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(qt_project__srv__GetRoute_Request)) {
      return false;
    }
    data = (qt_project__srv__GetRoute_Request *)allocator.zero_allocate(size, sizeof(qt_project__srv__GetRoute_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = qt_project__srv__GetRoute_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        qt_project__srv__GetRoute_Request__fini(&data[i - 1]);
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
qt_project__srv__GetRoute_Request__Sequence__fini(qt_project__srv__GetRoute_Request__Sequence * array)
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
      qt_project__srv__GetRoute_Request__fini(&array->data[i]);
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

qt_project__srv__GetRoute_Request__Sequence *
qt_project__srv__GetRoute_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qt_project__srv__GetRoute_Request__Sequence * array = (qt_project__srv__GetRoute_Request__Sequence *)allocator.allocate(sizeof(qt_project__srv__GetRoute_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = qt_project__srv__GetRoute_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
qt_project__srv__GetRoute_Request__Sequence__destroy(qt_project__srv__GetRoute_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    qt_project__srv__GetRoute_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
qt_project__srv__GetRoute_Request__Sequence__are_equal(const qt_project__srv__GetRoute_Request__Sequence * lhs, const qt_project__srv__GetRoute_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!qt_project__srv__GetRoute_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
qt_project__srv__GetRoute_Request__Sequence__copy(
  const qt_project__srv__GetRoute_Request__Sequence * input,
  qt_project__srv__GetRoute_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(qt_project__srv__GetRoute_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(qt_project__srv__GetRoute_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    qt_project__srv__GetRoute_Request * data =
      (qt_project__srv__GetRoute_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!qt_project__srv__GetRoute_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          qt_project__srv__GetRoute_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!qt_project__srv__GetRoute_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `route`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
qt_project__srv__GetRoute_Response__init(qt_project__srv__GetRoute_Response * msg)
{
  if (!msg) {
    return false;
  }
  // route
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->route, 0)) {
    qt_project__srv__GetRoute_Response__fini(msg);
    return false;
  }
  return true;
}

void
qt_project__srv__GetRoute_Response__fini(qt_project__srv__GetRoute_Response * msg)
{
  if (!msg) {
    return;
  }
  // route
  rosidl_runtime_c__int32__Sequence__fini(&msg->route);
}

bool
qt_project__srv__GetRoute_Response__are_equal(const qt_project__srv__GetRoute_Response * lhs, const qt_project__srv__GetRoute_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // route
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->route), &(rhs->route)))
  {
    return false;
  }
  return true;
}

bool
qt_project__srv__GetRoute_Response__copy(
  const qt_project__srv__GetRoute_Response * input,
  qt_project__srv__GetRoute_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // route
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->route), &(output->route)))
  {
    return false;
  }
  return true;
}

qt_project__srv__GetRoute_Response *
qt_project__srv__GetRoute_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qt_project__srv__GetRoute_Response * msg = (qt_project__srv__GetRoute_Response *)allocator.allocate(sizeof(qt_project__srv__GetRoute_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qt_project__srv__GetRoute_Response));
  bool success = qt_project__srv__GetRoute_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
qt_project__srv__GetRoute_Response__destroy(qt_project__srv__GetRoute_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    qt_project__srv__GetRoute_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
qt_project__srv__GetRoute_Response__Sequence__init(qt_project__srv__GetRoute_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qt_project__srv__GetRoute_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(qt_project__srv__GetRoute_Response)) {
      return false;
    }
    data = (qt_project__srv__GetRoute_Response *)allocator.zero_allocate(size, sizeof(qt_project__srv__GetRoute_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = qt_project__srv__GetRoute_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        qt_project__srv__GetRoute_Response__fini(&data[i - 1]);
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
qt_project__srv__GetRoute_Response__Sequence__fini(qt_project__srv__GetRoute_Response__Sequence * array)
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
      qt_project__srv__GetRoute_Response__fini(&array->data[i]);
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

qt_project__srv__GetRoute_Response__Sequence *
qt_project__srv__GetRoute_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qt_project__srv__GetRoute_Response__Sequence * array = (qt_project__srv__GetRoute_Response__Sequence *)allocator.allocate(sizeof(qt_project__srv__GetRoute_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = qt_project__srv__GetRoute_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
qt_project__srv__GetRoute_Response__Sequence__destroy(qt_project__srv__GetRoute_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    qt_project__srv__GetRoute_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
qt_project__srv__GetRoute_Response__Sequence__are_equal(const qt_project__srv__GetRoute_Response__Sequence * lhs, const qt_project__srv__GetRoute_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!qt_project__srv__GetRoute_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
qt_project__srv__GetRoute_Response__Sequence__copy(
  const qt_project__srv__GetRoute_Response__Sequence * input,
  qt_project__srv__GetRoute_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(qt_project__srv__GetRoute_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(qt_project__srv__GetRoute_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    qt_project__srv__GetRoute_Response * data =
      (qt_project__srv__GetRoute_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!qt_project__srv__GetRoute_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          qt_project__srv__GetRoute_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!qt_project__srv__GetRoute_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "qt_project/srv/detail/get_route__functions.h"

bool
qt_project__srv__GetRoute_Event__init(qt_project__srv__GetRoute_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    qt_project__srv__GetRoute_Event__fini(msg);
    return false;
  }
  // request
  if (!qt_project__srv__GetRoute_Request__Sequence__init(&msg->request, 0)) {
    qt_project__srv__GetRoute_Event__fini(msg);
    return false;
  }
  // response
  if (!qt_project__srv__GetRoute_Response__Sequence__init(&msg->response, 0)) {
    qt_project__srv__GetRoute_Event__fini(msg);
    return false;
  }
  return true;
}

void
qt_project__srv__GetRoute_Event__fini(qt_project__srv__GetRoute_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  qt_project__srv__GetRoute_Request__Sequence__fini(&msg->request);
  // response
  qt_project__srv__GetRoute_Response__Sequence__fini(&msg->response);
}

bool
qt_project__srv__GetRoute_Event__are_equal(const qt_project__srv__GetRoute_Event * lhs, const qt_project__srv__GetRoute_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!qt_project__srv__GetRoute_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!qt_project__srv__GetRoute_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
qt_project__srv__GetRoute_Event__copy(
  const qt_project__srv__GetRoute_Event * input,
  qt_project__srv__GetRoute_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!qt_project__srv__GetRoute_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!qt_project__srv__GetRoute_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

qt_project__srv__GetRoute_Event *
qt_project__srv__GetRoute_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qt_project__srv__GetRoute_Event * msg = (qt_project__srv__GetRoute_Event *)allocator.allocate(sizeof(qt_project__srv__GetRoute_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(qt_project__srv__GetRoute_Event));
  bool success = qt_project__srv__GetRoute_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
qt_project__srv__GetRoute_Event__destroy(qt_project__srv__GetRoute_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    qt_project__srv__GetRoute_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
qt_project__srv__GetRoute_Event__Sequence__init(qt_project__srv__GetRoute_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qt_project__srv__GetRoute_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(qt_project__srv__GetRoute_Event)) {
      return false;
    }
    data = (qt_project__srv__GetRoute_Event *)allocator.zero_allocate(size, sizeof(qt_project__srv__GetRoute_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = qt_project__srv__GetRoute_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        qt_project__srv__GetRoute_Event__fini(&data[i - 1]);
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
qt_project__srv__GetRoute_Event__Sequence__fini(qt_project__srv__GetRoute_Event__Sequence * array)
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
      qt_project__srv__GetRoute_Event__fini(&array->data[i]);
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

qt_project__srv__GetRoute_Event__Sequence *
qt_project__srv__GetRoute_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  qt_project__srv__GetRoute_Event__Sequence * array = (qt_project__srv__GetRoute_Event__Sequence *)allocator.allocate(sizeof(qt_project__srv__GetRoute_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = qt_project__srv__GetRoute_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
qt_project__srv__GetRoute_Event__Sequence__destroy(qt_project__srv__GetRoute_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    qt_project__srv__GetRoute_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
qt_project__srv__GetRoute_Event__Sequence__are_equal(const qt_project__srv__GetRoute_Event__Sequence * lhs, const qt_project__srv__GetRoute_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!qt_project__srv__GetRoute_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
qt_project__srv__GetRoute_Event__Sequence__copy(
  const qt_project__srv__GetRoute_Event__Sequence * input,
  qt_project__srv__GetRoute_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(qt_project__srv__GetRoute_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(qt_project__srv__GetRoute_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    qt_project__srv__GetRoute_Event * data =
      (qt_project__srv__GetRoute_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!qt_project__srv__GetRoute_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          qt_project__srv__GetRoute_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!qt_project__srv__GetRoute_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
