// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msgs:srv/UnloadTrash.idl
// generated code does not contain a copyright notice

#ifndef MSGS__SRV__DETAIL__UNLOAD_TRASH__BUILDER_HPP_
#define MSGS__SRV__DETAIL__UNLOAD_TRASH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "msgs/srv/detail/unload_trash__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace msgs
{

namespace srv
{

namespace builder
{

class Init_UnloadTrash_Request_robot_pos
{
public:
  explicit Init_UnloadTrash_Request_robot_pos(::msgs::srv::UnloadTrash_Request & msg)
  : msg_(msg)
  {}
  ::msgs::srv::UnloadTrash_Request robot_pos(::msgs::srv::UnloadTrash_Request::_robot_pos_type arg)
  {
    msg_.robot_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs::srv::UnloadTrash_Request msg_;
};

class Init_UnloadTrash_Request_robot_id
{
public:
  Init_UnloadTrash_Request_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UnloadTrash_Request_robot_pos robot_id(::msgs::srv::UnloadTrash_Request::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_UnloadTrash_Request_robot_pos(msg_);
  }

private:
  ::msgs::srv::UnloadTrash_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs::srv::UnloadTrash_Request>()
{
  return msgs::srv::builder::Init_UnloadTrash_Request_robot_id();
}

}  // namespace msgs


namespace msgs
{

namespace srv
{

namespace builder
{

class Init_UnloadTrash_Response_capacity_used
{
public:
  explicit Init_UnloadTrash_Response_capacity_used(::msgs::srv::UnloadTrash_Response & msg)
  : msg_(msg)
  {}
  ::msgs::srv::UnloadTrash_Response capacity_used(::msgs::srv::UnloadTrash_Response::_capacity_used_type arg)
  {
    msg_.capacity_used = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs::srv::UnloadTrash_Response msg_;
};

class Init_UnloadTrash_Response_score_gained
{
public:
  explicit Init_UnloadTrash_Response_score_gained(::msgs::srv::UnloadTrash_Response & msg)
  : msg_(msg)
  {}
  Init_UnloadTrash_Response_capacity_used score_gained(::msgs::srv::UnloadTrash_Response::_score_gained_type arg)
  {
    msg_.score_gained = std::move(arg);
    return Init_UnloadTrash_Response_capacity_used(msg_);
  }

private:
  ::msgs::srv::UnloadTrash_Response msg_;
};

class Init_UnloadTrash_Response_success
{
public:
  Init_UnloadTrash_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UnloadTrash_Response_score_gained success(::msgs::srv::UnloadTrash_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_UnloadTrash_Response_score_gained(msg_);
  }

private:
  ::msgs::srv::UnloadTrash_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs::srv::UnloadTrash_Response>()
{
  return msgs::srv::builder::Init_UnloadTrash_Response_success();
}

}  // namespace msgs

#endif  // MSGS__SRV__DETAIL__UNLOAD_TRASH__BUILDER_HPP_
