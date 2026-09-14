// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from qt_project:srv/ProcessPenalty.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qt_project/srv/process_penalty.hpp"


#ifndef QT_PROJECT__SRV__DETAIL__PROCESS_PENALTY__STRUCT_HPP_
#define QT_PROJECT__SRV__DETAIL__PROCESS_PENALTY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__qt_project__srv__ProcessPenalty_Request __attribute__((deprecated))
#else
# define DEPRECATED__qt_project__srv__ProcessPenalty_Request __declspec(deprecated)
#endif

namespace qt_project
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ProcessPenalty_Request_
{
  using Type = ProcessPenalty_Request_<ContainerAllocator>;

  explicit ProcessPenalty_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit ProcessPenalty_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _seat_ids_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _seat_ids_type seat_ids;

  // setters for named parameter idiom
  Type & set__seat_ids(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->seat_ids = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    qt_project::srv::ProcessPenalty_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const qt_project::srv::ProcessPenalty_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<qt_project::srv::ProcessPenalty_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<qt_project::srv::ProcessPenalty_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      qt_project::srv::ProcessPenalty_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<qt_project::srv::ProcessPenalty_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      qt_project::srv::ProcessPenalty_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<qt_project::srv::ProcessPenalty_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<qt_project::srv::ProcessPenalty_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<qt_project::srv::ProcessPenalty_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__qt_project__srv__ProcessPenalty_Request
    std::shared_ptr<qt_project::srv::ProcessPenalty_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__qt_project__srv__ProcessPenalty_Request
    std::shared_ptr<qt_project::srv::ProcessPenalty_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProcessPenalty_Request_ & other) const
  {
    if (this->seat_ids != other.seat_ids) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProcessPenalty_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProcessPenalty_Request_

// alias to use template instance with default allocator
using ProcessPenalty_Request =
  qt_project::srv::ProcessPenalty_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace qt_project


#ifndef _WIN32
# define DEPRECATED__qt_project__srv__ProcessPenalty_Response __attribute__((deprecated))
#else
# define DEPRECATED__qt_project__srv__ProcessPenalty_Response __declspec(deprecated)
#endif

namespace qt_project
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ProcessPenalty_Response_
{
  using Type = ProcessPenalty_Response_<ContainerAllocator>;

  explicit ProcessPenalty_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit ProcessPenalty_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    qt_project::srv::ProcessPenalty_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const qt_project::srv::ProcessPenalty_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<qt_project::srv::ProcessPenalty_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<qt_project::srv::ProcessPenalty_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      qt_project::srv::ProcessPenalty_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<qt_project::srv::ProcessPenalty_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      qt_project::srv::ProcessPenalty_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<qt_project::srv::ProcessPenalty_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<qt_project::srv::ProcessPenalty_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<qt_project::srv::ProcessPenalty_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__qt_project__srv__ProcessPenalty_Response
    std::shared_ptr<qt_project::srv::ProcessPenalty_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__qt_project__srv__ProcessPenalty_Response
    std::shared_ptr<qt_project::srv::ProcessPenalty_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProcessPenalty_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProcessPenalty_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProcessPenalty_Response_

// alias to use template instance with default allocator
using ProcessPenalty_Response =
  qt_project::srv::ProcessPenalty_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace qt_project


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__qt_project__srv__ProcessPenalty_Event __attribute__((deprecated))
#else
# define DEPRECATED__qt_project__srv__ProcessPenalty_Event __declspec(deprecated)
#endif

namespace qt_project
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ProcessPenalty_Event_
{
  using Type = ProcessPenalty_Event_<ContainerAllocator>;

  explicit ProcessPenalty_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit ProcessPenalty_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<qt_project::srv::ProcessPenalty_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<qt_project::srv::ProcessPenalty_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<qt_project::srv::ProcessPenalty_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<qt_project::srv::ProcessPenalty_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<qt_project::srv::ProcessPenalty_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<qt_project::srv::ProcessPenalty_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<qt_project::srv::ProcessPenalty_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<qt_project::srv::ProcessPenalty_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    qt_project::srv::ProcessPenalty_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const qt_project::srv::ProcessPenalty_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<qt_project::srv::ProcessPenalty_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<qt_project::srv::ProcessPenalty_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      qt_project::srv::ProcessPenalty_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<qt_project::srv::ProcessPenalty_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      qt_project::srv::ProcessPenalty_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<qt_project::srv::ProcessPenalty_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<qt_project::srv::ProcessPenalty_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<qt_project::srv::ProcessPenalty_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__qt_project__srv__ProcessPenalty_Event
    std::shared_ptr<qt_project::srv::ProcessPenalty_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__qt_project__srv__ProcessPenalty_Event
    std::shared_ptr<qt_project::srv::ProcessPenalty_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProcessPenalty_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProcessPenalty_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProcessPenalty_Event_

// alias to use template instance with default allocator
using ProcessPenalty_Event =
  qt_project::srv::ProcessPenalty_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace qt_project

namespace qt_project
{

namespace srv
{

struct ProcessPenalty
{
  using Request = qt_project::srv::ProcessPenalty_Request;
  using Response = qt_project::srv::ProcessPenalty_Response;
  using Event = qt_project::srv::ProcessPenalty_Event;
};

}  // namespace srv

}  // namespace qt_project

#endif  // QT_PROJECT__SRV__DETAIL__PROCESS_PENALTY__STRUCT_HPP_
