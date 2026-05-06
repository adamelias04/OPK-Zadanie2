// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from vacuum_msgs:msg/TrashCount.idl
// generated code does not contain a copyright notice

#ifndef VACUUM_MSGS__MSG__DETAIL__TRASH_COUNT__BUILDER_HPP_
#define VACUUM_MSGS__MSG__DETAIL__TRASH_COUNT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "vacuum_msgs/msg/detail/trash_count__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace vacuum_msgs
{

namespace msg
{

namespace builder
{

class Init_TrashCount_count
{
public:
  explicit Init_TrashCount_count(::vacuum_msgs::msg::TrashCount & msg)
  : msg_(msg)
  {}
  ::vacuum_msgs::msg::TrashCount count(::vacuum_msgs::msg::TrashCount::_count_type arg)
  {
    msg_.count = std::move(arg);
    return std::move(msg_);
  }

private:
  ::vacuum_msgs::msg::TrashCount msg_;
};

class Init_TrashCount_type
{
public:
  Init_TrashCount_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrashCount_count type(::vacuum_msgs::msg::TrashCount::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_TrashCount_count(msg_);
  }

private:
  ::vacuum_msgs::msg::TrashCount msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::vacuum_msgs::msg::TrashCount>()
{
  return vacuum_msgs::msg::builder::Init_TrashCount_type();
}

}  // namespace vacuum_msgs

#endif  // VACUUM_MSGS__MSG__DETAIL__TRASH_COUNT__BUILDER_HPP_
