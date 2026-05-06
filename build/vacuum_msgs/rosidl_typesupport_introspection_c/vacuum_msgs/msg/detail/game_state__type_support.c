// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from vacuum_msgs:msg/GameState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "vacuum_msgs/msg/detail/game_state__rosidl_typesupport_introspection_c.h"
#include "vacuum_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "vacuum_msgs/msg/detail/game_state__functions.h"
#include "vacuum_msgs/msg/detail/game_state__struct.h"


// Include directives for member types
// Member `mode`
// Member `phase`
// Member `winner`
#include "rosidl_runtime_c/string_functions.h"
// Member `collected`
#include "vacuum_msgs/msg/trash_count.h"
// Member `collected`
#include "vacuum_msgs/msg/detail/trash_count__rosidl_typesupport_introspection_c.h"
// Member `active_trash`
#include "vacuum_msgs/msg/trash_item.h"
// Member `active_trash`
#include "vacuum_msgs/msg/detail/trash_item__rosidl_typesupport_introspection_c.h"
// Member `robots`
#include "vacuum_msgs/msg/robot_status.h"
// Member `robots`
#include "vacuum_msgs/msg/detail/robot_status__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__GameState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  vacuum_msgs__msg__GameState__init(message_memory);
}

void vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__GameState_fini_function(void * message_memory)
{
  vacuum_msgs__msg__GameState__fini(message_memory);
}

size_t vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__size_function__GameState__collected(
  const void * untyped_member)
{
  const vacuum_msgs__msg__TrashCount__Sequence * member =
    (const vacuum_msgs__msg__TrashCount__Sequence *)(untyped_member);
  return member->size;
}

const void * vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__get_const_function__GameState__collected(
  const void * untyped_member, size_t index)
{
  const vacuum_msgs__msg__TrashCount__Sequence * member =
    (const vacuum_msgs__msg__TrashCount__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__get_function__GameState__collected(
  void * untyped_member, size_t index)
{
  vacuum_msgs__msg__TrashCount__Sequence * member =
    (vacuum_msgs__msg__TrashCount__Sequence *)(untyped_member);
  return &member->data[index];
}

void vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__fetch_function__GameState__collected(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vacuum_msgs__msg__TrashCount * item =
    ((const vacuum_msgs__msg__TrashCount *)
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__get_const_function__GameState__collected(untyped_member, index));
  vacuum_msgs__msg__TrashCount * value =
    (vacuum_msgs__msg__TrashCount *)(untyped_value);
  *value = *item;
}

void vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__assign_function__GameState__collected(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vacuum_msgs__msg__TrashCount * item =
    ((vacuum_msgs__msg__TrashCount *)
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__get_function__GameState__collected(untyped_member, index));
  const vacuum_msgs__msg__TrashCount * value =
    (const vacuum_msgs__msg__TrashCount *)(untyped_value);
  *item = *value;
}

bool vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__resize_function__GameState__collected(
  void * untyped_member, size_t size)
{
  vacuum_msgs__msg__TrashCount__Sequence * member =
    (vacuum_msgs__msg__TrashCount__Sequence *)(untyped_member);
  vacuum_msgs__msg__TrashCount__Sequence__fini(member);
  return vacuum_msgs__msg__TrashCount__Sequence__init(member, size);
}

size_t vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__size_function__GameState__active_trash(
  const void * untyped_member)
{
  const vacuum_msgs__msg__TrashItem__Sequence * member =
    (const vacuum_msgs__msg__TrashItem__Sequence *)(untyped_member);
  return member->size;
}

const void * vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__get_const_function__GameState__active_trash(
  const void * untyped_member, size_t index)
{
  const vacuum_msgs__msg__TrashItem__Sequence * member =
    (const vacuum_msgs__msg__TrashItem__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__get_function__GameState__active_trash(
  void * untyped_member, size_t index)
{
  vacuum_msgs__msg__TrashItem__Sequence * member =
    (vacuum_msgs__msg__TrashItem__Sequence *)(untyped_member);
  return &member->data[index];
}

void vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__fetch_function__GameState__active_trash(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vacuum_msgs__msg__TrashItem * item =
    ((const vacuum_msgs__msg__TrashItem *)
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__get_const_function__GameState__active_trash(untyped_member, index));
  vacuum_msgs__msg__TrashItem * value =
    (vacuum_msgs__msg__TrashItem *)(untyped_value);
  *value = *item;
}

void vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__assign_function__GameState__active_trash(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vacuum_msgs__msg__TrashItem * item =
    ((vacuum_msgs__msg__TrashItem *)
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__get_function__GameState__active_trash(untyped_member, index));
  const vacuum_msgs__msg__TrashItem * value =
    (const vacuum_msgs__msg__TrashItem *)(untyped_value);
  *item = *value;
}

bool vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__resize_function__GameState__active_trash(
  void * untyped_member, size_t size)
{
  vacuum_msgs__msg__TrashItem__Sequence * member =
    (vacuum_msgs__msg__TrashItem__Sequence *)(untyped_member);
  vacuum_msgs__msg__TrashItem__Sequence__fini(member);
  return vacuum_msgs__msg__TrashItem__Sequence__init(member, size);
}

size_t vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__size_function__GameState__robots(
  const void * untyped_member)
{
  const vacuum_msgs__msg__RobotStatus__Sequence * member =
    (const vacuum_msgs__msg__RobotStatus__Sequence *)(untyped_member);
  return member->size;
}

const void * vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__get_const_function__GameState__robots(
  const void * untyped_member, size_t index)
{
  const vacuum_msgs__msg__RobotStatus__Sequence * member =
    (const vacuum_msgs__msg__RobotStatus__Sequence *)(untyped_member);
  return &member->data[index];
}

void * vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__get_function__GameState__robots(
  void * untyped_member, size_t index)
{
  vacuum_msgs__msg__RobotStatus__Sequence * member =
    (vacuum_msgs__msg__RobotStatus__Sequence *)(untyped_member);
  return &member->data[index];
}

void vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__fetch_function__GameState__robots(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const vacuum_msgs__msg__RobotStatus * item =
    ((const vacuum_msgs__msg__RobotStatus *)
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__get_const_function__GameState__robots(untyped_member, index));
  vacuum_msgs__msg__RobotStatus * value =
    (vacuum_msgs__msg__RobotStatus *)(untyped_value);
  *value = *item;
}

void vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__assign_function__GameState__robots(
  void * untyped_member, size_t index, const void * untyped_value)
{
  vacuum_msgs__msg__RobotStatus * item =
    ((vacuum_msgs__msg__RobotStatus *)
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__get_function__GameState__robots(untyped_member, index));
  const vacuum_msgs__msg__RobotStatus * value =
    (const vacuum_msgs__msg__RobotStatus *)(untyped_value);
  *item = *value;
}

bool vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__resize_function__GameState__robots(
  void * untyped_member, size_t size)
{
  vacuum_msgs__msg__RobotStatus__Sequence * member =
    (vacuum_msgs__msg__RobotStatus__Sequence *)(untyped_member);
  vacuum_msgs__msg__RobotStatus__Sequence__fini(member);
  return vacuum_msgs__msg__RobotStatus__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__GameState_message_member_array[8] = {
  {
    "mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vacuum_msgs__msg__GameState, mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "phase",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vacuum_msgs__msg__GameState, phase),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "elapsed_seconds",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vacuum_msgs__msg__GameState, elapsed_seconds),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "score",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vacuum_msgs__msg__GameState, score),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "collected",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vacuum_msgs__msg__GameState, collected),  // bytes offset in struct
    NULL,  // default value
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__size_function__GameState__collected,  // size() function pointer
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__get_const_function__GameState__collected,  // get_const(index) function pointer
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__get_function__GameState__collected,  // get(index) function pointer
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__fetch_function__GameState__collected,  // fetch(index, &value) function pointer
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__assign_function__GameState__collected,  // assign(index, value) function pointer
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__resize_function__GameState__collected  // resize(index) function pointer
  },
  {
    "active_trash",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vacuum_msgs__msg__GameState, active_trash),  // bytes offset in struct
    NULL,  // default value
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__size_function__GameState__active_trash,  // size() function pointer
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__get_const_function__GameState__active_trash,  // get_const(index) function pointer
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__get_function__GameState__active_trash,  // get(index) function pointer
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__fetch_function__GameState__active_trash,  // fetch(index, &value) function pointer
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__assign_function__GameState__active_trash,  // assign(index, value) function pointer
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__resize_function__GameState__active_trash  // resize(index) function pointer
  },
  {
    "robots",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vacuum_msgs__msg__GameState, robots),  // bytes offset in struct
    NULL,  // default value
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__size_function__GameState__robots,  // size() function pointer
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__get_const_function__GameState__robots,  // get_const(index) function pointer
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__get_function__GameState__robots,  // get(index) function pointer
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__fetch_function__GameState__robots,  // fetch(index, &value) function pointer
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__assign_function__GameState__robots,  // assign(index, value) function pointer
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__resize_function__GameState__robots  // resize(index) function pointer
  },
  {
    "winner",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vacuum_msgs__msg__GameState, winner),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__GameState_message_members = {
  "vacuum_msgs__msg",  // message namespace
  "GameState",  // message name
  8,  // number of fields
  sizeof(vacuum_msgs__msg__GameState),
  vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__GameState_message_member_array,  // message members
  vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__GameState_init_function,  // function to initialize message memory (memory has to be allocated)
  vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__GameState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__GameState_message_type_support_handle = {
  0,
  &vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__GameState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_vacuum_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vacuum_msgs, msg, GameState)() {
  vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__GameState_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vacuum_msgs, msg, TrashCount)();
  vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__GameState_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vacuum_msgs, msg, TrashItem)();
  vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__GameState_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vacuum_msgs, msg, RobotStatus)();
  if (!vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__GameState_message_type_support_handle.typesupport_identifier) {
    vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__GameState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &vacuum_msgs__msg__GameState__rosidl_typesupport_introspection_c__GameState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
