#ifndef LIFECYCLE_QOS_PUBSUB__LIFECYCLE_PUBLISHER_HPP_
#define LIFECYCLE_QOS_PUBSUB__LIFECYCLE_PUBLISHER_HPP_

#include "rclcpp_lifecycle/lifecycle_node.hpp"
#include "std_msgs/msg/string.hpp"

class LifecyclePublisher : public rclcpp_lifecycle::LifecycleNode
{
public:
  explicit LifecyclePublisher(const rclcpp::NodeOptions & options = rclcpp::NodeOptions());

private:
  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn 
  on_configure(
    const rclcpp_lifecycle::State & state
) override;

  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn
  on_activate(
    const rclcpp_lifecycle::State & state
) override;

  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn 
  on_deactivate(
    const rclcpp_lifecycle::State & state
) override;

  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn 
  on_cleanup(
    const rclcpp_lifecycle::State & state
) override;

  void publish_message();

  rclcpp_lifecycle::LifecyclePublisher<std_msgs::msg::String>::SharedPtr publisher_;

  rclcpp::TimerBase::SharedPtr timer_;

  int count_;
};

#endif