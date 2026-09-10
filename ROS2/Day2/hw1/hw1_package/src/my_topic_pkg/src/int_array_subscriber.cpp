#include "my_topic_pkg/int_array_subscriber.hpp"

IntArraySubscriber::IntArraySubscriber()
: Node("int_array_subscriber")
{
  subscription_ = this->create_subscription<custom_interfaces::msg::IntArray>(
    "int_array_topic", 10,
    [this](const custom_interfaces::msg::IntArray & msg) { this->topic_callback(msg); });
}

void IntArraySubscriber::topic_callback(const custom_interfaces::msg::IntArray & msg) const
{
  std::cout << "받은 데이터: [ ";
  for (const auto & value : msg.data) {
    std::cout << value << ", ";
  }
  std::cout << "]" << std::endl;
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<IntArraySubscriber>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}