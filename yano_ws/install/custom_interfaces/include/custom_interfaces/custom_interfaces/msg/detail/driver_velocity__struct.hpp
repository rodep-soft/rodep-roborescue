// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_interfaces:msg/DriverVelocity.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__MSG__DETAIL__DRIVER_VELOCITY__STRUCT_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__DRIVER_VELOCITY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__custom_interfaces__msg__DriverVelocity __attribute__((deprecated))
#else
# define DEPRECATED__custom_interfaces__msg__DriverVelocity __declspec(deprecated)
#endif

namespace custom_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DriverVelocity_
{
  using Type = DriverVelocity_<ContainerAllocator>;

  explicit DriverVelocity_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_vel = 0.0f;
      this->right_vel = 0.0f;
    }
  }

  explicit DriverVelocity_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->left_vel = 0.0f;
      this->right_vel = 0.0f;
    }
  }

  // field types and members
  using _left_vel_type =
    float;
  _left_vel_type left_vel;
  using _right_vel_type =
    float;
  _right_vel_type right_vel;

  // setters for named parameter idiom
  Type & set__left_vel(
    const float & _arg)
  {
    this->left_vel = _arg;
    return *this;
  }
  Type & set__right_vel(
    const float & _arg)
  {
    this->right_vel = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_interfaces::msg::DriverVelocity_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_interfaces::msg::DriverVelocity_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_interfaces::msg::DriverVelocity_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_interfaces::msg::DriverVelocity_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::DriverVelocity_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::DriverVelocity_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_interfaces::msg::DriverVelocity_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_interfaces::msg::DriverVelocity_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_interfaces::msg::DriverVelocity_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_interfaces::msg::DriverVelocity_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_interfaces__msg__DriverVelocity
    std::shared_ptr<custom_interfaces::msg::DriverVelocity_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_interfaces__msg__DriverVelocity
    std::shared_ptr<custom_interfaces::msg::DriverVelocity_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DriverVelocity_ & other) const
  {
    if (this->left_vel != other.left_vel) {
      return false;
    }
    if (this->right_vel != other.right_vel) {
      return false;
    }
    return true;
  }
  bool operator!=(const DriverVelocity_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DriverVelocity_

// alias to use template instance with default allocator
using DriverVelocity =
  custom_interfaces::msg::DriverVelocity_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__DRIVER_VELOCITY__STRUCT_HPP_
