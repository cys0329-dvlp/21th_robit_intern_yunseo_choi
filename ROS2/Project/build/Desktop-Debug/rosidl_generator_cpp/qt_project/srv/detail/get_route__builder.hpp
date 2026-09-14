// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from qt_project:srv/GetRoute.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "qt_project/srv/get_route.hpp"


#ifndef QT_PROJECT__SRV__DETAIL__GET_ROUTE__BUILDER_HPP_
#define QT_PROJECT__SRV__DETAIL__GET_ROUTE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "qt_project/srv/detail/get_route__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace qt_project
{

namespace srv
{

namespace builder
{

class Init_GetRoute_Request_seat_ids
{
public:
  Init_GetRoute_Request_seat_ids()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::qt_project::srv::GetRoute_Request seat_ids(::qt_project::srv::GetRoute_Request::_seat_ids_type arg)
  {
    msg_.seat_ids = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qt_project::srv::GetRoute_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::qt_project::srv::GetRoute_Request>()
{
  return qt_project::srv::builder::Init_GetRoute_Request_seat_ids();
}

}  // namespace qt_project


namespace qt_project
{

namespace srv
{

namespace builder
{

class Init_GetRoute_Response_route
{
public:
  Init_GetRoute_Response_route()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::qt_project::srv::GetRoute_Response route(::qt_project::srv::GetRoute_Response::_route_type arg)
  {
    msg_.route = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qt_project::srv::GetRoute_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::qt_project::srv::GetRoute_Response>()
{
  return qt_project::srv::builder::Init_GetRoute_Response_route();
}

}  // namespace qt_project


namespace qt_project
{

namespace srv
{

namespace builder
{

class Init_GetRoute_Event_response
{
public:
  explicit Init_GetRoute_Event_response(::qt_project::srv::GetRoute_Event & msg)
  : msg_(msg)
  {}
  ::qt_project::srv::GetRoute_Event response(::qt_project::srv::GetRoute_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qt_project::srv::GetRoute_Event msg_;
};

class Init_GetRoute_Event_request
{
public:
  explicit Init_GetRoute_Event_request(::qt_project::srv::GetRoute_Event & msg)
  : msg_(msg)
  {}
  Init_GetRoute_Event_response request(::qt_project::srv::GetRoute_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetRoute_Event_response(msg_);
  }

private:
  ::qt_project::srv::GetRoute_Event msg_;
};

class Init_GetRoute_Event_info
{
public:
  Init_GetRoute_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetRoute_Event_request info(::qt_project::srv::GetRoute_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetRoute_Event_request(msg_);
  }

private:
  ::qt_project::srv::GetRoute_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::qt_project::srv::GetRoute_Event>()
{
  return qt_project::srv::builder::Init_GetRoute_Event_info();
}

}  // namespace qt_project

#endif  // QT_PROJECT__SRV__DETAIL__GET_ROUTE__BUILDER_HPP_
