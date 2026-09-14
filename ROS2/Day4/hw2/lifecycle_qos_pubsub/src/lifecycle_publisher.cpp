#include "lifecycle_qos_pubsub/lifecycle_publisher.hpp"
#include "rclcpp/executors.hpp"

using CallbackReturn =
  rclcpp_lifecycle::node_interfaces::LifecycleNodeInterface::CallbackReturn;

LifecyclePublisher::LifecyclePublisher(
  const rclcpp::NodeOptions & options)
: LifecycleNode("lifecycle_publisher", options),
  count_(0)
{
}


//------------- on configure() ----------------

CallbackReturn LifecyclePublisher::on_configure(
  const rclcpp_lifecycle::State &)
{
  RCLCPP_INFO(
    get_logger(),
    "on_configure()");

  auto qos = rclcpp::QoS(rclcpp::KeepLast(10));
  qos.reliable();
  qos.durability_volatile();

  publisher_ =
    create_publisher<std_msgs::msg::String>(
      "chatter",
      qos);

  timer_ = create_wall_timer(
    std::chrono::milliseconds(500),
    std::bind(
      &LifecyclePublisher::publish_message,
      this));

  return CallbackReturn::SUCCESS;
}

//------------- on activate() ----------------

CallbackReturn LifecyclePublisher::on_activate(
  const rclcpp_lifecycle::State &)
{
  RCLCPP_INFO(
    get_logger(),
    "on_activate()");

  publisher_->on_activate(); //Lifecycle Publisher 자체를 활성화 시키는 것

  return CallbackReturn::SUCCESS;
}

//-------------publish----------

void LifecyclePublisher::publish_message()
{
  // active 상태에서만 publish 가능하도록 체크함
  if (!publisher_->is_activated()) {
    return;
  }

  std_msgs::msg::String message;

  message.data =
    "Hello Lifecycle " + std::to_string(count_++);

  publisher_->publish(message);
}

//-------------- on_deactivate() ----------------

CallbackReturn LifecyclePublisher::on_deactivate(
  const rclcpp_lifecycle::State &)
{
  RCLCPP_INFO(
    get_logger(),
    "on_deactivate()");

  publisher_->on_deactivate();

  return CallbackReturn::SUCCESS;
}


//------------- on cleanup() ----------------

CallbackReturn LifecyclePublisher::on_cleanup(
  const rclcpp_lifecycle::State &)
{
  RCLCPP_INFO(
    get_logger(),
    "on_cleanup()");

  //만든 자원을 reset
  publisher_.reset();
  timer_.reset();

  return CallbackReturn::SUCCESS;
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  auto node =
    std::make_shared<LifecyclePublisher>();

  rclcpp::executors::SingleThreadedExecutor executor;

  executor.add_node(node->get_node_base_interface());

  executor.spin();

  rclcpp::shutdown();

  return 0;
}