// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vacuum_msgs:msg/TrashCount.idl
// generated code does not contain a copyright notice

#ifndef VACUUM_MSGS__MSG__DETAIL__TRASH_COUNT__STRUCT_HPP_
#define VACUUM_MSGS__MSG__DETAIL__TRASH_COUNT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__vacuum_msgs__msg__TrashCount __attribute__((deprecated))
#else
# define DEPRECATED__vacuum_msgs__msg__TrashCount __declspec(deprecated)
#endif

namespace vacuum_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TrashCount_
{
  using Type = TrashCount_<ContainerAllocator>;

  explicit TrashCount_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = "";
      this->count = 0ul;
    }
  }

  explicit TrashCount_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : type(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = "";
      this->count = 0ul;
    }
  }

  // field types and members
  using _type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _type_type type;
  using _count_type =
    uint32_t;
  _count_type count;

  // setters for named parameter idiom
  Type & set__type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__count(
    const uint32_t & _arg)
  {
    this->count = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vacuum_msgs::msg::TrashCount_<ContainerAllocator> *;
  using ConstRawPtr =
    const vacuum_msgs::msg::TrashCount_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vacuum_msgs::msg::TrashCount_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vacuum_msgs::msg::TrashCount_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vacuum_msgs::msg::TrashCount_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vacuum_msgs::msg::TrashCount_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vacuum_msgs::msg::TrashCount_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vacuum_msgs::msg::TrashCount_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vacuum_msgs::msg::TrashCount_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vacuum_msgs::msg::TrashCount_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vacuum_msgs__msg__TrashCount
    std::shared_ptr<vacuum_msgs::msg::TrashCount_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vacuum_msgs__msg__TrashCount
    std::shared_ptr<vacuum_msgs::msg::TrashCount_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrashCount_ & other) const
  {
    if (this->type != other.type) {
      return false;
    }
    if (this->count != other.count) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrashCount_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrashCount_

// alias to use template instance with default allocator
using TrashCount =
  vacuum_msgs::msg::TrashCount_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vacuum_msgs

#endif  // VACUUM_MSGS__MSG__DETAIL__TRASH_COUNT__STRUCT_HPP_
