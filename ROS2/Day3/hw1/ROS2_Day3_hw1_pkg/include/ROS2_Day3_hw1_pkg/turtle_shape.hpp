#ifndef ROS2_DAY3_HW1_PKG__TURTLE_SHAPE_HPP_
#define ROS2_DAY3_HW1_PKG__TURTLE_SHAPE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/srv/set_pen.hpp"

#include <thread>
#include <string>

class TurtleShape : public rclcpp::Node
{
public:
    TurtleShape();
    ~TurtleShape();

private:
    // Publisher
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;

    // Service Client
    rclcpp::Client<turtlesim::srv::SetPen>::SharedPtr pen_client_;

    // Timer
    rclcpp::TimerBase::SharedPtr timer_;

    // Keyboard Thread
    std::thread input_thread_;

    // 현재 선택된 도형
    std::string shape_;

    // 그리기 상태
    int state_;
    bool drawing_;

    // 시작 시간
    rclcpp::Time start_time_;

    // 현재 펜 설정
    int pen_r_;
    int pen_g_;
    int pen_b_;
    int pen_width_;

    // YAML에서 읽어온 사각형 설정
    int square_r_;
    int square_g_;
    int square_b_;
    int square_width_;

    // YAML에서 읽어온 삼각형 설정
    int triangle_r_;
    int triangle_g_;
    int triangle_b_;
    int triangle_width_;

    // YAML에서 읽어온 원 설정
    int circle_r_;
    int circle_g_;
    int circle_b_;
    int circle_width_;

    // 키보드 입력
    void keyboard_input();

    // 펜 설정
    void set_pen();

    // Timer Callback
    void timer_callback();

    // 경과 시간
    double elapsed_time();
};

#endif  // ROS2_DAY3_HW1_PKG__TURTLE_SHAPE_HPP_