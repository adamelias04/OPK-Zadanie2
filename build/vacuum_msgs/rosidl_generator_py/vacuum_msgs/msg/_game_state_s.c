// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from vacuum_msgs:msg/GameState.idl
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
#include "vacuum_msgs/msg/detail/game_state__struct.h"
#include "vacuum_msgs/msg/detail/game_state__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "vacuum_msgs/msg/detail/robot_status__functions.h"
#include "vacuum_msgs/msg/detail/trash_count__functions.h"
#include "vacuum_msgs/msg/detail/trash_item__functions.h"
// end nested array functions include
bool vacuum_msgs__msg__trash_count__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vacuum_msgs__msg__trash_count__convert_to_py(void * raw_ros_message);
bool vacuum_msgs__msg__trash_item__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vacuum_msgs__msg__trash_item__convert_to_py(void * raw_ros_message);
bool vacuum_msgs__msg__robot_status__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * vacuum_msgs__msg__robot_status__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool vacuum_msgs__msg__game_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[38];
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
    assert(strncmp("vacuum_msgs.msg._game_state.GameState", full_classname_dest, 37) == 0);
  }
  vacuum_msgs__msg__GameState * ros_message = _ros_message;
  {  // mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "mode");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->mode, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // phase
    PyObject * field = PyObject_GetAttrString(_pymsg, "phase");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->phase, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // elapsed_seconds
    PyObject * field = PyObject_GetAttrString(_pymsg, "elapsed_seconds");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->elapsed_seconds = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // score
    PyObject * field = PyObject_GetAttrString(_pymsg, "score");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->score = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // collected
    PyObject * field = PyObject_GetAttrString(_pymsg, "collected");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'collected'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!vacuum_msgs__msg__TrashCount__Sequence__init(&(ros_message->collected), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create vacuum_msgs__msg__TrashCount__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    vacuum_msgs__msg__TrashCount * dest = ros_message->collected.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!vacuum_msgs__msg__trash_count__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // active_trash
    PyObject * field = PyObject_GetAttrString(_pymsg, "active_trash");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'active_trash'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!vacuum_msgs__msg__TrashItem__Sequence__init(&(ros_message->active_trash), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create vacuum_msgs__msg__TrashItem__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    vacuum_msgs__msg__TrashItem * dest = ros_message->active_trash.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!vacuum_msgs__msg__trash_item__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // robots
    PyObject * field = PyObject_GetAttrString(_pymsg, "robots");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'robots'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!vacuum_msgs__msg__RobotStatus__Sequence__init(&(ros_message->robots), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create vacuum_msgs__msg__RobotStatus__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    vacuum_msgs__msg__RobotStatus * dest = ros_message->robots.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!vacuum_msgs__msg__robot_status__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // winner
    PyObject * field = PyObject_GetAttrString(_pymsg, "winner");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->winner, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * vacuum_msgs__msg__game_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of GameState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("vacuum_msgs.msg._game_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "GameState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  vacuum_msgs__msg__GameState * ros_message = (vacuum_msgs__msg__GameState *)raw_ros_message;
  {  // mode
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->mode.data,
      strlen(ros_message->mode.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // phase
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->phase.data,
      strlen(ros_message->phase.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "phase", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // elapsed_seconds
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->elapsed_seconds);
    {
      int rc = PyObject_SetAttrString(_pymessage, "elapsed_seconds", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // score
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->score);
    {
      int rc = PyObject_SetAttrString(_pymessage, "score", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // collected
    PyObject * field = NULL;
    size_t size = ros_message->collected.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    vacuum_msgs__msg__TrashCount * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->collected.data[i]);
      PyObject * pyitem = vacuum_msgs__msg__trash_count__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "collected", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // active_trash
    PyObject * field = NULL;
    size_t size = ros_message->active_trash.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    vacuum_msgs__msg__TrashItem * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->active_trash.data[i]);
      PyObject * pyitem = vacuum_msgs__msg__trash_item__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "active_trash", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // robots
    PyObject * field = NULL;
    size_t size = ros_message->robots.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    vacuum_msgs__msg__RobotStatus * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->robots.data[i]);
      PyObject * pyitem = vacuum_msgs__msg__robot_status__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "robots", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // winner
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->winner.data,
      strlen(ros_message->winner.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "winner", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
