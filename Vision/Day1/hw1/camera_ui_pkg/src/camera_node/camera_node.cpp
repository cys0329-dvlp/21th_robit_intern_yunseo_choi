#include "camera_ui_pkg/camera_node/camera_node.hpp"

#include <algorithm>
#include <cctype>

#include <cv_bridge/cv_bridge.hpp>
#include <std_msgs/msg/header.hpp>

namespace camera_ui_pkg
{

  //생성자 선언, 노드 이름 camera_node
CameraNode::CameraNode(const rclcpp::NodeOptions & options)
    : Node("camera_node", options)
{
    RCLCPP_INFO(
        this->get_logger(),
        "Camera Node Started");

    //declare_parameter: ROS2에서 parameter를 선언하는 함수 

    //camera_source = 파라미터 이름, 0은 기본 값
    camera_source_ =
        this->declare_parameter<std::string>("camera_source", "0");

    //프레임 가로 크기 설정 
    frame_width_ =
        this->declare_parameter<int>("frame_width", 640);

    //프레임 세로 크기 설정
    frame_height_ =
        this->declare_parameter<int>("frame_height", 480);

    //publish 주기
    publish_rate_hz_ =
        this->declare_parameter<double>("publish_rate_hz", 30.0);

    //카메라 열기 실패했다면 open failed 출력(예외처리)
    if (!openCaptureSource())
    {
        RCLCPP_ERROR(
            this->get_logger(),
            "Camera open failed.");

        return;
    }

    //image publisher 생성 -> 토픽 이름: image_raw
    image_pub_ =
        image_transport::create_publisher(this, "image_raw");

    //publish 주기 계산 -> 1초에 헤르츠 설정한만큼 보냄
    const auto period =
        std::chrono::duration<double>(1.0 / publish_rate_hz_);

    //bind: timer가 실행될 때 timercallback을 실행하라고 지정하는 뜻
    timer_ = this->create_wall_timer(
        std::chrono::duration_cast<std::chrono::milliseconds>(period),
        std::bind(
            &CameraNode::timerCallback,
            this));

    RCLCPP_INFO(
    this->get_logger(),
    "Camera Node Started: Real Camera");
}

CameraNode::~CameraNode()
{
    if (cap_.isOpened())
    {
        cap_.release();
    }
}

//카메라 여는 함수
bool CameraNode::openCaptureSource()
{
    // 숫자면 카메라 번호로 사용
    const bool is_index = !camera_source_.empty() && std::all_of(camera_source_.begin(),camera_source_.end(),[](unsigned char c)
    {
          return std::isdigit(c);
    });

    if (is_index)
    {
        cap_.open(std::stoi(camera_source_), cv::CAP_V4L2);
    }
    else
    {
        cap_.open(camera_source_);
    }

    if (cap_.isOpened())
    {
        // 카메라에서 사용할 해상도 설정
        cap_.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('Y', 'U', 'Y', 'V'));

        cap_.set(cv::CAP_PROP_FRAME_WIDTH, frame_width_);

        cap_.set(cv::CAP_PROP_FRAME_HEIGHT, frame_height_);

        const int actual_w =static_cast<int>(cap_.get(cv::CAP_PROP_FRAME_WIDTH));

        const int actual_h =static_cast<int>(cap_.get(cv::CAP_PROP_FRAME_HEIGHT));

        // 카메라가 요청한 해상도를 지원하지 않을 경우 실제 해상도 사용
        if (actual_w != frame_width_ || actual_h != frame_height_)
        {
            RCLCPP_WARN(this->get_logger(),"Camera resolution changed: %dx%d",actual_w,actual_h);

            frame_width_ = actual_w;
            frame_height_ = actual_h;
        }
    }

    return cap_.isOpened();
}


void CameraNode::timerCallback()
{
    cv::Mat frame;

    
        // 카메라에서 현재 프레임 받아오기
        if (!cap_.read(frame) || frame.empty())
        {
            RCLCPP_WARN(this->get_logger(),"Frame read failed");

            return;
        }
    

    std_msgs::msg::Header header;

    header.stamp = this->now();
    header.frame_id = "camera_frame";

    // OpenCV 이미지를 ROS Image로 변환
    const auto msg = cv_bridge::CvImage(header,"bgr8",frame).toImageMsg();

    image_pub_.publish(msg);
}

}

int main(int argc, char ** argv)
{
    rclcpp::init(argc, argv);

    auto node =
        std::make_shared<camera_ui_pkg::CameraNode>();

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}