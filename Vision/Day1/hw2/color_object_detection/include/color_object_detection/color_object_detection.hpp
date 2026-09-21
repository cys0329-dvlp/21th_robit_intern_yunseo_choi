#ifndef COLOR_OBJECT_DETECTION__COLOR_OBJECT_DETECTION_HPP_
#define COLOR_OBJECT_DETECTION__COLOR_OBJECT_DETECTION_HPP_

#include <rclcpp/rclcpp.hpp>
#include <opencv2/opencv.hpp>

#include <string>
#include <vector>

class ColorObjectDetection : public rclcpp::Node
{
public:
    ColorObjectDetection();

private:
    void detectObjects(
        cv::Mat & image,
        const cv::Mat & mask,
        const std::string & color_name,
        const cv::Scalar & box_color);
};

#endif  // COLOR_OBJECT_DETECTION__COLOR_OBJECT_DETECTION_HPP_