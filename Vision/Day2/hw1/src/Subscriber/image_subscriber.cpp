#include "CalDist_pkg/Subscriber/image_subscriber.hpp"

#include <cstring>

ImageSubscriber::ImageSubscriber()
    : Node("image_subscriber") //Node 이름: image_subscriber
{

    RCLCPP_INFO(this->get_logger(),"이미지 구독 시작");
}

void ImageSubscriber::startSubscription()
{
    if (image_subscription_)
    {
        RCLCPP_INFO(
            this->get_logger(),
            "Image subscription is already active"
        );

        return;
    }

    image_subscription_ =
        this->create_subscription<sensor_msgs::msg::Image>(
            "/camera1/camera/compressed_image",
            10,
            std::bind(
                &ImageSubscriber::imageCallback,
                this,
                std::placeholders::_1
            )
        );

    RCLCPP_INFO(
        this->get_logger(),
        "Image subscription started"
    );
}

void ImageSubscriber::stopSubscription()
{
    if (!image_subscription_)
    {
        RCLCPP_INFO(
            this->get_logger(),
            "Image subscription is already stopped"
        );

        return;
    }

    image_subscription_.reset();
    frame_.release();

    RCLCPP_INFO(
        this->get_logger(),
        "Image subscription stopped"
    );
}

bool ImageSubscriber::isSubscribed() const
{
    return image_subscription_ != nullptr;
}

//카메라 영상 들어오면 호출되는 함수
void ImageSubscriber::imageCallback(
    const sensor_msgs::msg::Image::SharedPtr msg)
{
    //처음 이미지가 들어왔을 때 한번만 카메라 이미지 받아오기 성공 출력됨
    RCLCPP_INFO_ONCE(this->get_logger(),"카메라 이미지 받아오기 성공");

    RCLCPP_INFO_ONCE(this->get_logger(),"Image size: %d x %d",msg->width,msg->height);

    RCLCPP_INFO_ONCE(this->get_logger(),"Image encoding: %s",msg->encoding.c_str());
    /*
    ROS에서 받은 이미지가 RGB 형식이면 
    rgb8 데이터 -> QImage -> camera_data_.image로 저장
    */
    if (msg->encoding == "rgb8") 
    {
        cv::Mat image( // cv::Mat = OpenCV에서 이미지를 저장하는 대표적인 자료형 
            msg->width,
            msg->height,
            CV_8UC3,
            const_cast<unsigned char *>(msg->data.data()),
            msg->step
        );

        cv::cvtColor(
            image,
            frame_,
            cv::COLOR_RGB2BGR
        );
    }

    /*
    ROS에서 받은 이미지가 BGR 형식이면 
    bgr8 데이터 -> QImage -> camera_data_.image로 저장
    */
    else if (msg->encoding == "bgr8")
    {
        cv::Mat image(
            msg->height,
            msg->width,
            CV_8UC3,
            const_cast<unsigned char *>(msg->data.data()),
            msg->step
        );

        frame_ = image.clone();
    }


    else
    {
        RCLCPP_WARN_ONCE(
            this->get_logger(),
            "Unsupported image encoding: %s",
            msg->encoding.c_str()
        );
    }
}

const cv::Mat &ImageSubscriber::getFrame() const
{
    return frame_; //계속 현재 저장되어있는 프레임을 불러옴
}
//카메라 영상 받아오는 역할함