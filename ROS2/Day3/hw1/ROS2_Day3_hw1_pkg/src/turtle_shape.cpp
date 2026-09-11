#include "ROS2_Day3_hw1_pkg/turtle_shape.hpp"

TurtleShape::TurtleShape()
    : Node("turtle_shape"),
      shape_(""),
      state_(0),
      drawing_(false),
      start_time_(this->get_clock()->now()),
      pen_r_(255),
      pen_g_(255),
      pen_b_(255),
      pen_width_(2)
{
    // =========================================================
    // YAML Parameter 선언
    // =========================================================

    this->declare_parameter("square_r", 0);
    this->declare_parameter("square_g", 255);
    this->declare_parameter("square_b", 0);
    this->declare_parameter("square_width", 5);

    this->declare_parameter("triangle_r", 255);
    this->declare_parameter("triangle_g", 0);
    this->declare_parameter("triangle_b", 0);
    this->declare_parameter("triangle_width", 3);

    this->declare_parameter("circle_r", 0);
    this->declare_parameter("circle_g", 0);
    this->declare_parameter("circle_b", 255);
    this->declare_parameter("circle_width", 7);


    // =========================================================
    // YAML Parameter 가져오기
    // =========================================================

    this->get_parameter("square_r", square_r_);
    this->get_parameter("square_g", square_g_);
    this->get_parameter("square_b", square_b_);
    this->get_parameter("square_width", square_width_);

    this->get_parameter("triangle_r", triangle_r_);
    this->get_parameter("triangle_g", triangle_g_);
    this->get_parameter("triangle_b", triangle_b_);
    this->get_parameter("triangle_width", triangle_width_);

    this->get_parameter("circle_r", circle_r_);
    this->get_parameter("circle_g", circle_g_);
    this->get_parameter("circle_b", circle_b_);
    this->get_parameter("circle_width", circle_width_);


    // =========================================================
    // cmd_vel Publisher
    // =========================================================

    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>(
        "/turtle1/cmd_vel",
        10
    );


    // =========================================================
    // SetPen Service Client
    // =========================================================

    pen_client_ = this->create_client<turtlesim::srv::SetPen>(
        "/turtle1/set_pen"
    );


    // =========================================================
    // Timer
    // 0.01초마다 timer_callback 실행
    // =========================================================

    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(10),
        std::bind(&TurtleShape::timer_callback, this)
    );


    // =========================================================
    // Keyboard Input Thread
    // =========================================================

    input_thread_ = std::thread(
        &TurtleShape::keyboard_input,
        this
    );
}


TurtleShape::~TurtleShape()
{
    if (input_thread_.joinable())
    {
        input_thread_.detach();
    }
}


// =============================================================
// 키보드 입력
// =============================================================

void TurtleShape::keyboard_input()
{
    while (rclcpp::ok())
    {
        std::cout << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "도형을 선택하세요." << std::endl;
        std::cout << "W : 사각형" << std::endl;
        std::cout << "S : 삼각형" << std::endl;
        std::cout << "A : 원" << std::endl;
        std::cout << "D : 종료" << std::endl;
        std::cout << "==============================" << std::endl;

        std::string key;

        std::cout << "입력 : ";
        std::cin >> key;

        // 대문자로 변환
        for (char & c : key)
        {
            c = static_cast<char>(std::toupper(c));
        }


        // =====================================================
        // 종료
        // =====================================================

        if (key == "D")
        {
            std::cout << "프로그램을 종료합니다." << std::endl;

            rclcpp::shutdown();

            break;
        }


        // =====================================================
        // 사각형
        // =====================================================

        else if (key == "W")
        {
            shape_ = "square";

            pen_r_ = square_r_;
            pen_g_ = square_g_;
            pen_b_ = square_b_;
            pen_width_ = square_width_;

            std::cout << "사각형 선택" << std::endl;
        }


        // =====================================================
        // 삼각형
        // =====================================================

        else if (key == "S")
        {
            shape_ = "triangle";

            pen_r_ = triangle_r_;
            pen_g_ = triangle_g_;
            pen_b_ = triangle_b_;
            pen_width_ = triangle_width_;

            std::cout << "삼각형 선택" << std::endl;
        }


        // =====================================================
        // 원
        // =====================================================

        else if (key == "A")
        {
            shape_ = "circle";

            pen_r_ = circle_r_;
            pen_g_ = circle_g_;
            pen_b_ = circle_b_;
            pen_width_ = circle_width_;

            std::cout << "원 선택" << std::endl;
        }


        // =====================================================
        // 잘못된 입력
        // =====================================================

        else
        {
            std::cout << "잘못된 입력입니다." << std::endl;

            continue;
        }


        // =====================================================
        // 펜 설정
        // =====================================================

        set_pen();


        // =====================================================
        // 도형 그리기 시작
        // =====================================================

        state_ = 0;
        start_time_ = this->get_clock()->now();
        drawing_ = true;
    }
}


// =============================================================
// 펜 설정
// =============================================================

void TurtleShape::set_pen()
{
    if (!pen_client_->wait_for_service(
            std::chrono::seconds(1)))
    {
        RCLCPP_WARN(
            this->get_logger(),
            "/turtle1/set_pen 서비스를 찾을 수 없습니다."
        );

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


// =============================================================
// 경과 시간
// =============================================================

double TurtleShape::elapsed_time()
{
    return (
        this->get_clock()->now() - start_time_
    ).seconds();
}


// =============================================================
// Timer Callback
// =============================================================

void TurtleShape::timer_callback()
{
    geometry_msgs::msg::Twist msg;


    // =========================================================
    // 그리고 있지 않으면 정지
    // =========================================================

    if (!drawing_)
    {
        msg.linear.x = 0.0;
        msg.angular.z = 0.0;

        publisher_->publish(msg);

        return;
    }


    double elapsed = elapsed_time();


    // =========================================================
    // 삼각형
    // =========================================================

    if (shape_ == "triangle")
    {
        // 1번째 변
        if (state_ == 0)
        {
            msg.linear.x = 2.0;
            msg.angular.z = 0.0;

            if (elapsed >= 1.5)
            {
                state_ = 1;
                start_time_ = this->get_clock()->now();
            }
        }

        // 1번째 120도 회전
        else if (state_ == 1)
        {
            msg.linear.x = 0.0;
            msg.angular.z = 2.0;

            if (elapsed >= 1.047)
            {
                state_ = 2;
                start_time_ = this->get_clock()->now();
            }
        }

        // 2번째 변
        else if (state_ == 2)
        {
            msg.linear.x = 2.0;
            msg.angular.z = 0.0;

            if (elapsed >= 1.5)
            {
                state_ = 3;
                start_time_ = this->get_clock()->now();
            }
        }

        // 2번째 120도 회전
        else if (state_ == 3)
        {
            msg.linear.x = 0.0;
            msg.angular.z = 2.0;

            if (elapsed >= 1.047)
            {
                state_ = 4;
                start_time_ = this->get_clock()->now();
            }
        }

        // 3번째 변
        else if (state_ == 4)
        {
            msg.linear.x = 2.0;
            msg.angular.z = 0.0;

            if (elapsed >= 1.5)
            {
                state_ = 5;
                start_time_ = this->get_clock()->now();
            }
        }

        // 3번째 120도 회전
        else if (state_ == 5)
        {
            msg.linear.x = 0.0;
            msg.angular.z = 2.0;

            if (elapsed >= 1.047)
            {
                state_ = 6;
                start_time_ = this->get_clock()->now();
            }
        }

        // 정지
        else if (state_ == 6)
        {
            msg.linear.x = 0.0;
            msg.angular.z = 0.0;

            drawing_ = false;

            std::cout << std::endl;
            std::cout << "삼각형 그리기 완료." << std::endl;
        }
    }


    // =========================================================
    // 사각형
    // =========================================================

    else if (shape_ == "square")
    {
        // 1번째 변
        if (state_ == 0)
        {
            msg.linear.x = 2.0;
            msg.angular.z = 0.0;

            if (elapsed >= 1.5)
            {
                state_ = 1;
                start_time_ = this->get_clock()->now();
            }
        }

        // 1번째 90도 회전
        else if (state_ == 1)
        {
            msg.linear.x = 0.0;
            msg.angular.z = 2.0;

            if (elapsed >= 0.785)
            {
                state_ = 2;
                start_time_ = this->get_clock()->now();
            }
        }

        // 2번째 변
        else if (state_ == 2)
        {
            msg.linear.x = 2.0;
            msg.angular.z = 0.0;

            if (elapsed >= 1.5)
            {
                state_ = 3;
                start_time_ = this->get_clock()->now();
            }
        }

        // 2번째 90도 회전
        else if (state_ == 3)
        {
            msg.linear.x = 0.0;
            msg.angular.z = 2.0;

            if (elapsed >= 0.785)
            {
                state_ = 4;
                start_time_ = this->get_clock()->now();
            }
        }

        // 3번째 변
        else if (state_ == 4)
        {
            msg.linear.x = 2.0;
            msg.angular.z = 0.0;

            if (elapsed >= 1.5)
            {
                state_ = 5;
                start_time_ = this->get_clock()->now();
            }
        }

        // 3번째 90도 회전
        else if (state_ == 5)
        {
            msg.linear.x = 0.0;
            msg.angular.z = 2.0;

            if (elapsed >= 0.785)
            {
                state_ = 6;
                start_time_ = this->get_clock()->now();
            }
        }

        // 4번째 변
        else if (state_ == 6)
        {
            msg.linear.x = 2.0;
            msg.angular.z = 0.0;

            if (elapsed >= 1.5)
            {
                state_ = 7;
                start_time_ = this->get_clock()->now();
            }
        }

        // 4번째 90도 회전
        else if (state_ == 7)
        {
            msg.linear.x = 0.0;
            msg.angular.z = 2.0;

            if (elapsed >= 0.785)
            {
                state_ = 8;
                start_time_ = this->get_clock()->now();
            }
        }

        // 정지
        else if (state_ == 8)
        {
            msg.linear.x = 0.0;
            msg.angular.z = 0.0;

            drawing_ = false;

            std::cout << std::endl;
            std::cout << "사각형 그리기 완료." << std::endl;
        }
    }


    // =========================================================
    // 원
    // =========================================================

    else if (shape_ == "circle")
    {
        msg.linear.x = 2.0;
        msg.angular.z = 1.0;

        if (elapsed >= 6.283)
        {
            msg.linear.x = 0.0;
            msg.angular.z = 0.0;

            drawing_ = false;

            std::cout << std::endl;
            std::cout << "원 그리기 완료." << std::endl;
        }
    }


    // =========================================================
    // Turtle 이동
    // =========================================================

    publisher_->publish(msg);
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<TurtleShape>();

    try
    {
        rclcpp::spin(node);
    }
    catch (const std::exception & e)
    {
        RCLCPP_ERROR(
            node->get_logger(),
            "예외 발생: %s",
            e.what()
        );
    }

    rclcpp::shutdown();

    return 0;
}