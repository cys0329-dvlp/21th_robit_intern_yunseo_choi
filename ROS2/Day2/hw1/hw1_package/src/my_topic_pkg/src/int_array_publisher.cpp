#include "my_topic_pkg/int_array_publisher.hpp"
#include <iostream>
#include <string>
#include <vector>

IntArrayPublisher::IntArrayPublisher()
: Node("int_array_publisher")
{
  publisher_ = this->create_publisher<custom_interfaces::msg::IntArray>("int_array_topic", 10);
}

void IntArrayPublisher::run()
{
  while (rclcpp::ok()) {
    std::vector<int32_t> numbers; //vector로 동적할당
    std::cout << "정수 입력 (종료하려면 빈 줄에서 Enter): " << std::endl;

    while (true) {
      std::string line;
      std::getline(std::cin, line);

      if (line.empty()) {
        break;  // 빈 입력이면 이번 벡터 입력 종료
      }

      try {
        numbers.push_back(std::stoi(line));
      } catch (const std::exception & e) {
        std::cout << "정수만 입력해주세요." << std::endl;
      }
    }

    if (numbers.empty()) {
      continue;  // 아무것도 입력 안 했으면 다시 처음부터
    }

    auto message = custom_interfaces::msg::IntArray();
    message.data = numbers;

    RCLCPP_INFO(this->get_logger(), "퍼블리시: %zu개의 정수", numbers.size());
    publisher_->publish(message);
  }
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<IntArrayPublisher>();
  node->run();
  rclcpp::shutdown();
  return 0;
}