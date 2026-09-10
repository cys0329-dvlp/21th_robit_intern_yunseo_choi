#ifndef MY_TOPIC_PKG__INT_ARRAY_SUBSCRIBER_HPP_
#define MY_TOPIC_PKG__INT_ARRAY_SUBSCRIBER_HPP_

#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/msg/int_array.hpp"

class IntArraySubscriber : public rclcpp::Node
{
public:
  IntArraySubscriber();

private:
  void topic_callback(const custom_interfaces::msg::IntArray & msg) const;
  rclcpp::Subscription<custom_interfaces::msg::IntArray>::SharedPtr subscription_;
};

#endif