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

#include <functional>
#include <memory>

#include "minimal_subscriber.hpp"

using std::placeholders::_1;

MinimalSubscriber::MinimalSubscriber()
: Node("minimal_subscriber")
{
  subscription_ = this->create_subscription<std_msgs::msg::Int32>(
    "number", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));

  text_subscription_ = this->create_subscription<std_msgs::msg::String>(
    "text", 10, std::bind(&MinimalSubscriber::text_callback, this, _1));

  float_subscription_ = this->create_subscription<std_msgs::msg::Float32>(
    "float_number", 10, std::bind(&MinimalSubscriber::float_callback, this, _1));

  bool_subscription_ = this->create_subscription<std_msgs::msg::Bool>(
    "bool_number", 10, std::bind(&MinimalSubscriber::bool_callback, this, _1));
}

void MinimalSubscriber::topic_callback(const std_msgs::msg::Int32 & msg) const
{
  RCLCPP_INFO(this->get_logger(), "I heard: '%d'", msg.data);
}

void MinimalSubscriber::text_callback(const std_msgs::msg::String & msg) const
{
  RCLCPP_INFO(this->get_logger(), "I heard text: '%s'", msg.data.c_str());
}

void MinimalSubscriber::float_callback(const std_msgs::msg::Float32 & msg) const
{
  RCLCPP_INFO(this->get_logger(), "I heard float: '%f'", msg.data);
}

void MinimalSubscriber::bool_callback(const std_msgs::msg::Bool & msg) const
{
  RCLCPP_INFO(this->get_logger(), "I heard bool: '%d'", msg.data);
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}