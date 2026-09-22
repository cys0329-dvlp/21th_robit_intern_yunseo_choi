#ifndef CALDIST_PKG_IMAGE_SUBSCRIBER_HPP
#define CALDIST_PKG_IMAGE_SUBSCRIBER_HPP

#include <memory>

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>

#include <opencv2/opencv.hpp>

class ImageSubscriber : public rclcpp::Node
{
public:
   using SharedPtr = std::shared_ptr<ImageSubscriber>;

    ImageSubscriber();

    void startSubscription();
    void stopSubscription();
    bool isSubscribed() const;

    const cv::Mat &getFrame() const; // OpneCV 영상을 QT UI로 가져갈 수 있게함


private:
    void imageCallback(const sensor_msgs::msg::Image::SharedPtr msg);

    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_subscription_;

    cv::Mat frame_;
};

#endif // CALDIST_PKG_IMAGE_SUBSCRIBER_HPP

//ROS2에서 카메라 영상을 받는 역할만 담당 