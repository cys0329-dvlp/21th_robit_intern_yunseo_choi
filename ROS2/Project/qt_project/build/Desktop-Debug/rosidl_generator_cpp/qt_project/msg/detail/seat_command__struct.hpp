// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from qt_project:msg/SeatCommand.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qt_project/msg/seat_command.hpp"


#ifndef QT_PROJECT__MSG__DETAIL__SEAT_COMMAND__STRUCT_HPP_
#define QT_PROJECT__MSG__DETAIL__SEAT_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__qt_project__msg__SeatCommand __attribute__((deprecated))
#else
# define DEPRECATED__qt_project__msg__SeatCommand __declspec(deprecated)
#endif

namespace qt_project
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SeatCommand_
{
  using Type = SeatCommand_<ContainerAllocator>;

  explicit SeatCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->seat_id = 0l;
      this->occupied = false;
      this->has_belongings = false;
    }
  }

  explicit SeatCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->seat_id = 0l;
      this->occupied = false;
      this->has_belongings = false;
    }
  }

  // field types and members
  using _seat_id_type =
    int32_t;
  _seat_id_type seat_id;
  using _occupied_type =
    bool;
  _occupied_type occupied;
  using _has_belongings_type =
    bool;
  _has_belongings_type has_belongings;

  // setters for named parameter idiom
  Type & set__seat_id(
    const int32_t & _arg)
  {
    this->seat_id = _arg;
    return *this;
  }
  Type & set__occupied(
    const bool & _arg)
  {
    this->occupied = _arg;
    return *this;
  }
  Type & set__has_belongings(
    const bool & _arg)
  {
    this->has_belongings = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    qt_project::msg::SeatCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const qt_project::msg::SeatCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<qt_project::msg::SeatCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<qt_project::msg::SeatCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      qt_project::msg::SeatCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<qt_project::msg::SeatCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      qt_project::msg::SeatCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<qt_project::msg::SeatCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<qt_project::msg::SeatCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<qt_project::msg::SeatCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__qt_project__msg__SeatCommand
    std::shared_ptr<qt_project::msg::SeatCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__qt_project__msg__SeatCommand
    std::shared_ptr<qt_project::msg::SeatCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SeatCommand_ & other) const
  {
    if (this->seat_id != other.seat_id) {
      return false;
    }
    if (this->occupied != other.occupied) {
      return false;
    }
    if (this->has_belongings != other.has_belongings) {
      return false;
    }
    return true;
  }
  bool operator!=(const SeatCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SeatCommand_

// alias to use template instance with default allocator
using SeatCommand =
  qt_project::msg::SeatCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace qt_project

#endif  // QT_PROJECT__MSG__DETAIL__SEAT_COMMAND__STRUCT_HPP_
