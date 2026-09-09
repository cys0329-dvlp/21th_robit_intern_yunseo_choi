// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef MINIMAL_SUBSCRIBER_HPP_
#define MINIMAL_SUBSCRIBER_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/float32.hpp"
#include "std_msgs/msg/bool.hpp"

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber();

private:
  void topic_callback(const std_msgs::msg::Int32 & msg) const;
  rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr subscription_;

  void text_callback(const std_msgs::msg::String & msg) const;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr text_subscription_;

  void float_callback(const std_msgs::msg::Float32 & msg) const;
  rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr float_subscription_;

  void bool_callback(const std_msgs::msg::Bool & msg) const;
  rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr bool_subscription_;
};

#endif  // MINIMAL_SUBSCRIBER_HPP_