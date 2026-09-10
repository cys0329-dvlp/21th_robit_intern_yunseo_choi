#include "turtle_shape.hpp"

#include <iostream>
#include <chrono>

using namespace std::chrono_literals;

TurtleShape::TurtleShape()
    : QObject(nullptr),
    Node("turtle_shape"),
    shape_(""),
    state_(0),
    drawing_(false),
    pen_r_(255),
    pen_g_(255),
    pen_b_(255),
    pen_width_(2)
{
    // cmd_vel Publisher
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>(
        "/turtle1/cmd_vel", 10);

    // SetPen Service Client
    pen_client_ = this->create_client<turtlesim::srv::SetPen>(
        "/turtle1/set_pen");

    start_time_ = this->get_clock()->now();

    // 0.01초마다 실행
    timer_ = this->create_wall_timer(
        10ms, std::bind(&TurtleShape::timer_callback, this));
}

// 사각형 버튼 클릭
void TurtleShape::onSquareButtonClicked()
{
    start_drawing("square", 0, 255, 0, 5);
    std::cout << "사각형 선택" << std::endl;
}

// 삼각형 버튼 클릭
void TurtleShape::onTriangleButtonClicked()
{
    start_drawing("triangle", 255, 0, 0, 3);
    std::cout << "삼각형 선택" << std::endl;
}

// 원 버튼 클릭
void TurtleShape::onCircleButtonClicked()
{
    start_drawing("circle", 0, 0, 255, 7);
    std::cout << "원 선택" << std::endl;
}

void TurtleShape::start_drawing(
    const std::string & shape,
    int r, int g, int b, int width)
{
    shape_ = shape;
    pen_r_ = r;
    pen_g_ = g;
    pen_b_ = b;
    pen_width_ = width;

    // 펜 설정
    set_pen();

    // 도형 그리기 시작
    state_ = 0;
    start_time_ = this->get_clock()->now();
    drawing_ = true;
}

void TurtleShape::set_pen()
{
    if (!pen_client_->wait_for_service(1s)) {
        RCLCPP_WARN(this->get_logger(), "/turtle1/set_pen 서비스를 찾을 수 없습니다.");
        return;
    }

    auto request = std::make_shared<turtlesim::srv::SetPen::Request>();
    request->r = pen_r_;
    request->g = pen_g_;
    request->b = pen_b_;
    request->width = pen_width_;
    request->off = 0;

    pen_client_->async_send_request(request);
}

double TurtleShape::elapsed_time()
{
    return (this->get_clock()->now() - start_time_).nanoseconds() / 1e9;
}

void TurtleShape::timer_callback()
{
    geometry_msgs::msg::Twist msg;

    // 그리는 중이 아니면 정지
    if (!drawing_) {
        msg.linear.x = 0.0;
        msg.angular.z = 0.0;
        publisher_->publish(msg);
        return;
    }

    double elapsed = elapsed_time();

    // 삼각형
    if (shape_ == "triangle") {
        if (state_ == 0) {
            msg.linear.x = 2.0;
            msg.angular.z = 0.0;
            if (elapsed >= 1.5) {
                state_ = 1;
                start_time_ = this->get_clock()->now();
            }
        } else if (state_ == 1) {
            msg.linear.x = 0.0;
            msg.angular.z = 2.0;
            if (elapsed >= 1.047) {
                state_ = 2;
                start_time_ = this->get_clock()->now();
            }
        } else if (state_ == 2) {
            msg.linear.x = 2.0;
            msg.angular.z = 0.0;
            if (elapsed >= 1.5) {
                state_ = 3;
                start_time_ = this->get_clock()->now();
            }
        } else if (state_ == 3) {
            msg.linear.x = 0.0;
            msg.angular.z = 2.0;
            if (elapsed >= 1.047) {
                state_ = 4;
                start_time_ = this->get_clock()->now();
            }
        } else if (state_ == 4) {
            msg.linear.x = 2.0;
            msg.angular.z = 0.0;
            if (elapsed >= 1.5) {
                state_ = 5;
                start_time_ = this->get_clock()->now();
            }
        } else if (state_ == 5) {
            msg.linear.x = 0.0;
            msg.angular.z = 2.0;
            if (elapsed >= 1.047) {
                state_ = 6;
                start_time_ = this->get_clock()->now();
            }
        } else if (state_ == 6) {
            msg.linear.x = 0.0;
            msg.angular.z = 0.0;
            drawing_ = false;
            std::cout << std::endl;
            std::cout << "삼각형 그리기 완료." << std::endl;
        }
    }
    // 사각형
    else if (shape_ == "square") {
        if (state_ == 0) {
            msg.linear.x = 2.0;
            msg.angular.z = 0.0;
            if (elapsed >= 1.5) {
                state_ = 1;
                start_time_ = this->get_clock()->now();
            }
        } else if (state_ == 1) {
            msg.linear.x = 0.0;
            msg.angular.z = 2.0;
            if (elapsed >= 0.785) {
                state_ = 2;
                start_time_ = this->get_clock()->now();
            }
        } else if (state_ == 2) {
            msg.linear.x = 2.0;
            msg.angular.z = 0.0;
            if (elapsed >= 1.5) {
                state_ = 3;
                start_time_ = this->get_clock()->now();
            }
        } else if (state_ == 3) {
            msg.linear.x = 0.0;
            msg.angular.z = 2.0;
            if (elapsed >= 0.785) {
                state_ = 4;
                start_time_ = this->get_clock()->now();
            }
        } else if (state_ == 4) {
            msg.linear.x = 2.0;
            msg.angular.z = 0.0;
            if (elapsed >= 1.5) {
                state_ = 5;
                start_time_ = this->get_clock()->now();
            }
        } else if (state_ == 5) {
            msg.linear.x = 0.0;
            msg.angular.z = 2.0;
            if (elapsed >= 0.785) {
                state_ = 6;
                start_time_ = this->get_clock()->now();
            }
        } else if (state_ == 6) {
            msg.linear.x = 2.0;
            msg.angular.z = 0.0;
            if (elapsed >= 1.5) {
                state_ = 7;
                start_time_ = this->get_clock()->now();
            }
        } else if (state_ == 7) {
            msg.linear.x = 0.0;
            msg.angular.z = 2.0;
            if (elapsed >= 0.785) {
                state_ = 8;
                start_time_ = this->get_clock()->now();
            }
        } else if (state_ == 8) {
            msg.linear.x = 0.0;
            msg.angular.z = 0.0;
            drawing_ = false;
            std::cout << std::endl;
            std::cout << "사각형 그리기 완료." << std::endl;
        }
    }
    // 원
    else if (shape_ == "circle") {
        msg.linear.x = 2.0;
        msg.angular.z = 1.0;

        if (elapsed >= 6.283) {
            msg.linear.x = 0.0;
            msg.angular.z = 0.0;
            drawing_ = false;
            std::cout << std::endl;
            std::cout << "원 그리기 완료." << std::endl;
        }
    }

    publisher_->publish(msg);
    emit cmdVelChanged(msg.linear.x, msg.angular.z);
}
