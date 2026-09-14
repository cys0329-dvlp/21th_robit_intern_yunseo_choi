// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from qt_project:msg/SeatStatus.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "qt_project/msg/detail/seat_status__struct.h"
#include "qt_project/msg/detail/seat_status__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool qt_project__msg__seat_status__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[39];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("qt_project.msg._seat_status.SeatStatus", full_classname_dest, 38) == 0);
  }
  qt_project__msg__SeatStatus * ros_message = _ros_message;
  {  // seat_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "seat_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->seat_id = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // occupied
    PyObject * field = PyObject_GetAttrString(_pymsg, "occupied");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->occupied = (Py_True == field);
    Py_DECREF(field);
  }
  {  // has_belongings
    PyObject * field = PyObject_GetAttrString(_pymsg, "has_belongings");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->has_belongings = (Py_True == field);
    Py_DECREF(field);
  }
  {  // absence_start_time
    PyObject * field = PyObject_GetAttrString(_pymsg, "absence_start_time");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->absence_start_time = PyLong_AsLongLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * qt_project__msg__seat_status__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SeatStatus */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("qt_project.msg._seat_status");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SeatStatus");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  qt_project__msg__SeatStatus * ros_message = (qt_project__msg__SeatStatus *)raw_ros_message;
  {  // seat_id
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->seat_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "seat_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // occupied
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->occupied ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "occupied", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // has_belongings
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->has_belongings ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "has_belongings", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // absence_start_time
    PyObject * field = NULL;
    field = PyLong_FromLongLong(ros_message->absence_start_time);
    {
      int rc = PyObject_SetAttrString(_pymessage, "absence_start_time", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
