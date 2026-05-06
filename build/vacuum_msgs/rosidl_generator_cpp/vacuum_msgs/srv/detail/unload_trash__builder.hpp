// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vacuum_msgs:srv/UnloadTrash.idl
// generated code does not contain a copyright notice

#ifndef VACUUM_MSGS__SRV__DETAIL__UNLOAD_TRASH__BUILDER_HPP_
#define VACUUM_MSGS__SRV__DETAIL__UNLOAD_TRASH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vacuum_msgs/srv/detail/unload_trash__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vacuum_msgs
{

namespace srv
{

namespace builder
{

class Init_UnloadTrash_Request_robot_pos
{
public:
  explicit Init_UnloadTrash_Request_robot_pos(::vacuum_msgs::srv::UnloadTrash_Request & msg)
  : msg_(msg)
  {}
  ::vacuum_msgs::srv::UnloadTrash_Request robot_pos(::vacuum_msgs::srv::UnloadTrash_Request::_robot_pos_type arg)
  {
    msg_.robot_pos = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vacuum_msgs::srv::UnloadTrash_Request msg_;
};

class Init_UnloadTrash_Request_robot_id
{
public:
  Init_UnloadTrash_Request_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UnloadTrash_Request_robot_pos robot_id(::vacuum_msgs::srv::UnloadTrash_Request::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_UnloadTrash_Request_robot_pos(msg_);
  }

private:
  ::vacuum_msgs::srv::UnloadTrash_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vacuum_msgs::srv::UnloadTrash_Request>()
{
  return vacuum_msgs::srv::builder::Init_UnloadTrash_Request_robot_id();
}

}  // namespace vacuum_msgs


namespace vacuum_msgs
{

namespace srv
{

namespace builder
{

class Init_UnloadTrash_Response_capacity_used
{
public:
  explicit Init_UnloadTrash_Response_capacity_used(::vacuum_msgs::srv::UnloadTrash_Response & msg)
  : msg_(msg)
  {}
  ::vacuum_msgs::srv::UnloadTrash_Response capacity_used(::vacuum_msgs::srv::UnloadTrash_Response::_capacity_used_type arg)
  {
    msg_.capacity_used = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vacuum_msgs::srv::UnloadTrash_Response msg_;
};

class Init_UnloadTrash_Response_score_gained
{
public:
  explicit Init_UnloadTrash_Response_score_gained(::vacuum_msgs::srv::UnloadTrash_Response & msg)
  : msg_(msg)
  {}
  Init_UnloadTrash_Response_capacity_used score_gained(::vacuum_msgs::srv::UnloadTrash_Response::_score_gained_type arg)
  {
    msg_.score_gained = std::move(arg);
    return Init_UnloadTrash_Response_capacity_used(msg_);
  }

private:
  ::vacuum_msgs::srv::UnloadTrash_Response msg_;
};

class Init_UnloadTrash_Response_success
{
public:
  Init_UnloadTrash_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UnloadTrash_Response_score_gained success(::vacuum_msgs::srv::UnloadTrash_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_UnloadTrash_Response_score_gained(msg_);
  }

private:
  ::vacuum_msgs::srv::UnloadTrash_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::vacuum_msgs::srv::UnloadTrash_Response>()
{
  return vacuum_msgs::srv::builder::Init_UnloadTrash_Response_success();
}

}  // namespace vacuum_msgs

#endif  // VACUUM_MSGS__SRV__DETAIL__UNLOAD_TRASH__BUILDER_HPP_
