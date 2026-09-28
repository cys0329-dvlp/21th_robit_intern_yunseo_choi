#ifndef PYTORCH_OBJECT_DETECTION_CAMERA_NODE_HPP
#define PYTORCH_OBJECT_DETECTION_CAMERA_NODE_HPP

#include <rclcpp/rclcpp.hpp>
#include <opencv2/opencv.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.hpp>
class CameraNode : public rclcpp::Node
{
public:
    CameraNode();

private:
    cv::VideoCapture cap_; //카메라 담당하는 핵심 변수

    //publisher추가(cv::Mat을 ROS2 Image 메시지로 변환해서 publish)
    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_pub_;
};

#endif