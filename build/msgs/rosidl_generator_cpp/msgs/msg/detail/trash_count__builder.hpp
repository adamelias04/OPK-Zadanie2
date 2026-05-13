// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msgs:msg/TrashCount.idl
// generated code does not contain a copyright notice

#ifndef MSGS__MSG__DETAIL__TRASH_COUNT__BUILDER_HPP_
#define MSGS__MSG__DETAIL__TRASH_COUNT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "msgs/msg/detail/trash_count__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace msgs
{

namespace msg
{

namespace builder
{

class Init_TrashCount_count
{
public:
  explicit Init_TrashCount_count(::msgs::msg::TrashCount & msg)
  : msg_(msg)
  {}
  ::msgs::msg::TrashCount count(::msgs::msg::TrashCount::_count_type arg)
  {
    msg_.count = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msgs::msg::TrashCount msg_;
};

class Init_TrashCount_type
{
public:
  Init_TrashCount_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrashCount_count type(::msgs::msg::TrashCount::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_TrashCount_count(msg_);
  }

private:
  ::msgs::msg::TrashCount msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::msgs::msg::TrashCount>()
{
  return msgs::msg::builder::Init_TrashCount_type();
}

}  // namespace msgs

#endif  // MSGS__MSG__DETAIL__TRASH_COUNT__BUILDER_HPP_
