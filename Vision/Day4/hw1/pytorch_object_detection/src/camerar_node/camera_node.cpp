#include "pytorch_object_detection/camera_node/camera_node.hpp"
#include <std_msgs/msg/header.hpp>

CameraNode::CameraNode()
    : Node("camera_node") // 노드 이름: camera_node
{
    //publisher 생성(image_pub은 헤더파일에서 선언함)
    image_pub_ = this->create_publisher<sensor_msgs::msg::Image>(
    "/camera/image_raw", //토픽 이름
    10
    );

    cap_.open(0, cv::CAP_V4L2); //카메라 열기

    //카메라 안열릴 때 예외처리
    if(!cap_.isOpened())
    {
        RCLCPP_ERROR(this -> get_logger(), "카메라 열기 실패");
        return;
    }
    cv::Mat frame; //카메라에서 읽어온 프레임 저장할 변수
    
    while(rclcpp::ok()) //ROS2가 정상 작동되는 동안 반복
    {
        cap_ >> frame; //현재 프레임 하나를 읽어서 frame에 저장
        
        //프레임이 비었을 때 예외처리 
        if(frame.empty())
        {
            RCLCPP_ERROR(this->get_logger(), "카메라 프레임 열 수 없음");
            break;
        }

        //cv::Mat을 ROS2의 sensor_msgs로 변환함 / 이미지가 BGR 형식이라는 것을 나타냄
        auto msg = cv_bridge::CvImage(
        std_msgs::msg::Header(), 
        "bgr8", 
        frame
        ).toImageMsg();

        //변환한 이미지를 ROS2토픽으로 Publish
        image_pub_->publish(*msg);
        
        //창 크기 조절 기능, GUI 기능 최소화 -> 
        cv::namedWindow("Camera", cv::WINDOW_NORMAL | cv::WINDOW_GUI_NORMAL);
        //첫번째 인자: 화면 창 이름, 두번째 인자: 실제 보여줄 이미지
        cv::imshow("Camera", frame);

        if(cv::waitKey(1) == 27) //esc 누르면 카메라 종료
        {
            break;
        }
    }
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<CameraNode>();

    rclcpp::shutdown();

    return 0;
}