#include "lifecycle_qos_pubsub/lifecycle_subscriber.hpp"
#include "rclcpp/executors.hpp"
using CallbackReturn =
  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;

LifecycleSubscriber::LifecycleSubscriber(
  const rclcpp::NodeOptions & options)
: LifecycleNode("lifecycle_subscriber", options)
{
}

CallbackReturn LifecycleSubscriber::on_configure(
  const rclcpp_lifecycle::State &)
{
  RCLCPP_INFO(
    get_logger(),
    "on_configure()");

  auto qos = rclcpp::QoS(rclcpp::KeepLast(10));
  qos.reliable();
  qos.durability_volatile();

  subscription_ =
    create_subscription<std_msgs::msg::String>(
      "chatter",
      qos,
      std::bind(
        &LifecycleSubscriber::topic_callback,
        this,
        std::placeholders::_1));

  return CallbackReturn::SUCCESS;
}

CallbackReturn LifecycleSubscriber::on_activate(
  const rclcpp_lifecycle::State &)
{
  RCLCPP_INFO(
    get_logger(),
    "on_activate()");

  return CallbackReturn::SUCCESS;
}

CallbackReturn LifecycleSubscriber::on_deactivate(
  const rclcpp_lifecycle::State &)
{
  RCLCPP_INFO(
    get_logger(),
    "on_deactivate()");

  return CallbackReturn::SUCCESS;
}

CallbackReturn LifecycleSubscriber::on_cleanup(
  const rclcpp_lifecycle::State &)
{
  RCLCPP_INFO(
    get_logger(),
    "on_cleanup()");

  subscription_.reset();

  return CallbackReturn::SUCCESS;
}

void LifecycleSubscriber::topic_callback(
  const std_msgs::msg::String::SharedPtr msg)
{
  RCLCPP_INFO(
    get_logger(),
    "Received: '%s'",
    msg->data.c_str());
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  auto node =
    std::make_shared<LifecycleSubscriber>();

  rclcpp::executors::SingleThreadedExecutor executor;

  executor.add_node(node->get_node_base_interface());

  executor.spin();

  rclcpp::shutdown();

  return 0;
}