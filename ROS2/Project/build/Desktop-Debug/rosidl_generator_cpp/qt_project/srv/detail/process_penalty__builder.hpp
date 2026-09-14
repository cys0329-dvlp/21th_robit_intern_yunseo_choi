// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from qt_project:srv/ProcessPenalty.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qt_project/srv/process_penalty.hpp"


#ifndef QT_PROJECT__SRV__DETAIL__PROCESS_PENALTY__BUILDER_HPP_
#define QT_PROJECT__SRV__DETAIL__PROCESS_PENALTY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "qt_project/srv/detail/process_penalty__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace qt_project
{

namespace srv
{

namespace builder
{

class Init_ProcessPenalty_Request_seat_ids
{
public:
  Init_ProcessPenalty_Request_seat_ids()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::qt_project::srv::ProcessPenalty_Request seat_ids(::qt_project::srv::ProcessPenalty_Request::_seat_ids_type arg)
  {
    msg_.seat_ids = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qt_project::srv::ProcessPenalty_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::qt_project::srv::ProcessPenalty_Request>()
{
  return qt_project::srv::builder::Init_ProcessPenalty_Request_seat_ids();
}

}  // namespace qt_project


namespace qt_project
{

namespace srv
{

namespace builder
{

class Init_ProcessPenalty_Response_success
{
public:
  Init_ProcessPenalty_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::qt_project::srv::ProcessPenalty_Response success(::qt_project::srv::ProcessPenalty_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qt_project::srv::ProcessPenalty_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::qt_project::srv::ProcessPenalty_Response>()
{
  return qt_project::srv::builder::Init_ProcessPenalty_Response_success();
}

}  // namespace qt_project


namespace qt_project
{

namespace srv
{

namespace builder
{

class Init_ProcessPenalty_Event_response
{
public:
  explicit Init_ProcessPenalty_Event_response(::qt_project::srv::ProcessPenalty_Event & msg)
  : msg_(msg)
  {}
  ::qt_project::srv::ProcessPenalty_Event response(::qt_project::srv::ProcessPenalty_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qt_project::srv::ProcessPenalty_Event msg_;
};

class Init_ProcessPenalty_Event_request
{
public:
  explicit Init_ProcessPenalty_Event_request(::qt_project::srv::ProcessPenalty_Event & msg)
  : msg_(msg)
  {}
  Init_ProcessPenalty_Event_response request(::qt_project::srv::ProcessPenalty_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_ProcessPenalty_Event_response(msg_);
  }

private:
  ::qt_project::srv::ProcessPenalty_Event msg_;
};

class Init_ProcessPenalty_Event_info
{
public:
  Init_ProcessPenalty_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ProcessPenalty_Event_request info(::qt_project::srv::ProcessPenalty_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_ProcessPenalty_Event_request(msg_);
  }

private:
  ::qt_project::srv::ProcessPenalty_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::qt_project::srv::ProcessPenalty_Event>()
{
  return qt_project::srv::builder::Init_ProcessPenalty_Event_info();
}

}  // namespace qt_project

#endif  // QT_PROJECT__SRV__DETAIL__PROCESS_PENALTY__BUILDER_HPP_
