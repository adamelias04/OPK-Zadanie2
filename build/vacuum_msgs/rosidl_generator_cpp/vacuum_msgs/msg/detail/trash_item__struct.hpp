// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from vacuum_msgs:msg/TrashItem.idl
// generated code does not contain a copyright notice

#ifndef VACUUM_MSGS__MSG__DETAIL__TRASH_ITEM__STRUCT_HPP_
#define VACUUM_MSGS__MSG__DETAIL__TRASH_ITEM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'color'
#include "std_msgs/msg/detail/color_rgba__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__vacuum_msgs__msg__TrashItem __attribute__((deprecated))
#else
# define DEPRECATED__vacuum_msgs__msg__TrashItem __declspec(deprecated)
#endif

namespace vacuum_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TrashItem_
{
  using Type = TrashItem_<ContainerAllocator>;

  explicit TrashItem_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_init),
    color(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ul;
      this->type = "";
      this->radius = 0.0f;
      this->score_value = 0l;
    }
  }

  explicit TrashItem_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : type(_alloc),
    position(_alloc, _init),
    color(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0ul;
      this->type = "";
      this->radius = 0.0f;
      this->score_value = 0l;
    }
  }

  // field types and members
  using _id_type =
    uint32_t;
  _id_type id;
  using _type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _type_type type;
  using _position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_type position;
  using _radius_type =
    float;
  _radius_type radius;
  using _color_type =
    std_msgs::msg::ColorRGBA_<ContainerAllocator>;
  _color_type color;
  using _score_value_type =
    int32_t;
  _score_value_type score_value;

  // setters for named parameter idiom
  Type & set__id(
    const uint32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__radius(
    const float & _arg)
  {
    this->radius = _arg;
    return *this;
  }
  Type & set__color(
    const std_msgs::msg::ColorRGBA_<ContainerAllocator> & _arg)
  {
    this->color = _arg;
    return *this;
  }
  Type & set__score_value(
    const int32_t & _arg)
  {
    this->score_value = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    vacuum_msgs::msg::TrashItem_<ContainerAllocator> *;
  using ConstRawPtr =
    const vacuum_msgs::msg::TrashItem_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<vacuum_msgs::msg::TrashItem_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<vacuum_msgs::msg::TrashItem_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      vacuum_msgs::msg::TrashItem_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<vacuum_msgs::msg::TrashItem_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      vacuum_msgs::msg::TrashItem_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<vacuum_msgs::msg::TrashItem_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<vacuum_msgs::msg::TrashItem_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<vacuum_msgs::msg::TrashItem_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__vacuum_msgs__msg__TrashItem
    std::shared_ptr<vacuum_msgs::msg::TrashItem_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__vacuum_msgs__msg__TrashItem
    std::shared_ptr<vacuum_msgs::msg::TrashItem_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrashItem_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->type != other.type) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->radius != other.radius) {
      return false;
    }
    if (this->color != other.color) {
      return false;
    }
    if (this->score_value != other.score_value) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrashItem_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrashItem_

// alias to use template instance with default allocator
using TrashItem =
  vacuum_msgs::msg::TrashItem_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace vacuum_msgs

#endif  // VACUUM_MSGS__MSG__DETAIL__TRASH_ITEM__STRUCT_HPP_
