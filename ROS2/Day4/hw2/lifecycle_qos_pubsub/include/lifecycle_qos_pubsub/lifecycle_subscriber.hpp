#ifndef LIFECYCLE_QOS_PUBSUB__LIFECYCLE_SUBSCRIBER_HPP_
#define LIFECYCLE_QOS_PUBSUB__LIFECYCLE_SUBSCRIBER_HPP_

#include "rclcpp_lifecycle/lifecycle_node.hpp"
#include "std_msgs/msg/string.hpp"

class LifecycleSubscriber
  : public rclcpp_lifecycle::LifecycleNode
{
public:
  explicit LifecycleSubscriber(
    const rclcpp::NodeOptions & options =
    rclcpp::NodeOptions());

private:
  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
  on_configure(
    const rclcpp_lifecycle::State & state) override;

  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
  on_activate(
    const rclcpp_lifecycle::State & state) override;

  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
  on_deactivate(
    const rclcpp_lifecycle::State & state) override;

  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
  on_cleanup(
    const rclcpp_lifecycle::State & state) override;

  void topic_callback(
    const std_msgs::msg::String::SharedPtr msg);

  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr
    subscription_;
};

#endif