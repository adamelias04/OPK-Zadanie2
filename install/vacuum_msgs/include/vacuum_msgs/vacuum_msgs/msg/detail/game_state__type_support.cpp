// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from vacuum_msgs:msg/GameState.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "vacuum_msgs/msg/detail/game_state__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace vacuum_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void GameState_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) vacuum_msgs::msg::GameState(_init);
}

void GameState_fini_function(void * message_memory)
{
  auto typed_message = static_cast<vacuum_msgs::msg::GameState *>(message_memory);
  typed_message->~GameState();
}

size_t size_function__GameState__collected(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vacuum_msgs::msg::TrashCount> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GameState__collected(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vacuum_msgs::msg::TrashCount> *>(untyped_member);
  return &member[index];
}

void * get_function__GameState__collected(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vacuum_msgs::msg::TrashCount> *>(untyped_member);
  return &member[index];
}

void fetch_function__GameState__collected(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vacuum_msgs::msg::TrashCount *>(
    get_const_function__GameState__collected(untyped_member, index));
  auto & value = *reinterpret_cast<vacuum_msgs::msg::TrashCount *>(untyped_value);
  value = item;
}

void assign_function__GameState__collected(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vacuum_msgs::msg::TrashCount *>(
    get_function__GameState__collected(untyped_member, index));
  const auto & value = *reinterpret_cast<const vacuum_msgs::msg::TrashCount *>(untyped_value);
  item = value;
}

void resize_function__GameState__collected(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vacuum_msgs::msg::TrashCount> *>(untyped_member);
  member->resize(size);
}

size_t size_function__GameState__active_trash(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vacuum_msgs::msg::TrashItem> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GameState__active_trash(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vacuum_msgs::msg::TrashItem> *>(untyped_member);
  return &member[index];
}

void * get_function__GameState__active_trash(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vacuum_msgs::msg::TrashItem> *>(untyped_member);
  return &member[index];
}

void fetch_function__GameState__active_trash(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vacuum_msgs::msg::TrashItem *>(
    get_const_function__GameState__active_trash(untyped_member, index));
  auto & value = *reinterpret_cast<vacuum_msgs::msg::TrashItem *>(untyped_value);
  value = item;
}

void assign_function__GameState__active_trash(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vacuum_msgs::msg::TrashItem *>(
    get_function__GameState__active_trash(untyped_member, index));
  const auto & value = *reinterpret_cast<const vacuum_msgs::msg::TrashItem *>(untyped_value);
  item = value;
}

void resize_function__GameState__active_trash(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vacuum_msgs::msg::TrashItem> *>(untyped_member);
  member->resize(size);
}

size_t size_function__GameState__robots(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<vacuum_msgs::msg::RobotStatus> *>(untyped_member);
  return member->size();
}

const void * get_const_function__GameState__robots(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<vacuum_msgs::msg::RobotStatus> *>(untyped_member);
  return &member[index];
}

void * get_function__GameState__robots(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<vacuum_msgs::msg::RobotStatus> *>(untyped_member);
  return &member[index];
}

void fetch_function__GameState__robots(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const vacuum_msgs::msg::RobotStatus *>(
    get_const_function__GameState__robots(untyped_member, index));
  auto & value = *reinterpret_cast<vacuum_msgs::msg::RobotStatus *>(untyped_value);
  value = item;
}

void assign_function__GameState__robots(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<vacuum_msgs::msg::RobotStatus *>(
    get_function__GameState__robots(untyped_member, index));
  const auto & value = *reinterpret_cast<const vacuum_msgs::msg::RobotStatus *>(untyped_value);
  item = value;
}

void resize_function__GameState__robots(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<vacuum_msgs::msg::RobotStatus> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember GameState_message_member_array[8] = {
  {
    "mode",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vacuum_msgs::msg::GameState, mode),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "phase",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vacuum_msgs::msg::GameState, phase),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "elapsed_seconds",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vacuum_msgs::msg::GameState, elapsed_seconds),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "score",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vacuum_msgs::msg::GameState, score),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "collected",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vacuum_msgs::msg::TrashCount>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vacuum_msgs::msg::GameState, collected),  // bytes offset in struct
    nullptr,  // default value
    size_function__GameState__collected,  // size() function pointer
    get_const_function__GameState__collected,  // get_const(index) function pointer
    get_function__GameState__collected,  // get(index) function pointer
    fetch_function__GameState__collected,  // fetch(index, &value) function pointer
    assign_function__GameState__collected,  // assign(index, value) function pointer
    resize_function__GameState__collected  // resize(index) function pointer
  },
  {
    "active_trash",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vacuum_msgs::msg::TrashItem>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vacuum_msgs::msg::GameState, active_trash),  // bytes offset in struct
    nullptr,  // default value
    size_function__GameState__active_trash,  // size() function pointer
    get_const_function__GameState__active_trash,  // get_const(index) function pointer
    get_function__GameState__active_trash,  // get(index) function pointer
    fetch_function__GameState__active_trash,  // fetch(index, &value) function pointer
    assign_function__GameState__active_trash,  // assign(index, value) function pointer
    resize_function__GameState__active_trash  // resize(index) function pointer
  },
  {
    "robots",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<vacuum_msgs::msg::RobotStatus>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vacuum_msgs::msg::GameState, robots),  // bytes offset in struct
    nullptr,  // default value
    size_function__GameState__robots,  // size() function pointer
    get_const_function__GameState__robots,  // get_const(index) function pointer
    get_function__GameState__robots,  // get(index) function pointer
    fetch_function__GameState__robots,  // fetch(index, &value) function pointer
    assign_function__GameState__robots,  // assign(index, value) function pointer
    resize_function__GameState__robots  // resize(index) function pointer
  },
  {
    "winner",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(vacuum_msgs::msg::GameState, winner),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers GameState_message_members = {
  "vacuum_msgs::msg",  // message namespace
  "GameState",  // message name
  8,  // number of fields
  sizeof(vacuum_msgs::msg::GameState),
  GameState_message_member_array,  // message members
  GameState_init_function,  // function to initialize message memory (memory has to be allocated)
  GameState_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t GameState_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &GameState_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace vacuum_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<vacuum_msgs::msg::GameState>()
{
  return &::vacuum_msgs::msg::rosidl_typesupport_introspection_cpp::GameState_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, vacuum_msgs, msg, GameState)() {
  return &::vacuum_msgs::msg::rosidl_typesupport_introspection_cpp::GameState_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
