// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vacuum_msgs:msg/TrashCount.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vacuum_msgs/msg/detail/trash_count__rosidl_typesupport_introspection_c.h"
#include "vacuum_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vacuum_msgs/msg/detail/trash_count__functions.h"
#include "vacuum_msgs/msg/detail/trash_count__struct.h"


// Include directives for member types
// Member `type`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vacuum_msgs__msg__TrashCount__rosidl_typesupport_introspection_c__TrashCount_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vacuum_msgs__msg__TrashCount__init(message_memory);
}

void vacuum_msgs__msg__TrashCount__rosidl_typesupport_introspection_c__TrashCount_fini_function(void * message_memory)
{
  vacuum_msgs__msg__TrashCount__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember vacuum_msgs__msg__TrashCount__rosidl_typesupport_introspection_c__TrashCount_message_member_array[2] = {
  {
    "type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vacuum_msgs__msg__TrashCount, type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "count",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vacuum_msgs__msg__TrashCount, count),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vacuum_msgs__msg__TrashCount__rosidl_typesupport_introspection_c__TrashCount_message_members = {
  "vacuum_msgs__msg",  // message namespace
  "TrashCount",  // message name
  2,  // number of fields
  sizeof(vacuum_msgs__msg__TrashCount),
  vacuum_msgs__msg__TrashCount__rosidl_typesupport_introspection_c__TrashCount_message_member_array,  // message members
  vacuum_msgs__msg__TrashCount__rosidl_typesupport_introspection_c__TrashCount_init_function,  // function to initialize message memory (memory has to be allocated)
  vacuum_msgs__msg__TrashCount__rosidl_typesupport_introspection_c__TrashCount_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vacuum_msgs__msg__TrashCount__rosidl_typesupport_introspection_c__TrashCount_message_type_support_handle = {
  0,
  &vacuum_msgs__msg__TrashCount__rosidl_typesupport_introspection_c__TrashCount_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vacuum_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vacuum_msgs, msg, TrashCount)() {
  if (!vacuum_msgs__msg__TrashCount__rosidl_typesupport_introspection_c__TrashCount_message_type_support_handle.typesupport_identifier) {
    vacuum_msgs__msg__TrashCount__rosidl_typesupport_introspection_c__TrashCount_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vacuum_msgs__msg__TrashCount__rosidl_typesupport_introspection_c__TrashCount_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
