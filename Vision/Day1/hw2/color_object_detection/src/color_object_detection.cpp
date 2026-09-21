#include "color_object_detection/color_object_detection.hpp"

ColorObjectDetection::ColorObjectDetection()
    : Node("color_object_detection")
{
    RCLCPP_INFO(this->get_logger(), "Color Object Detection Node Started");

    this->declare_parameter<std::string>("image_path", "");

    std::string image_path = this->get_parameter("image_path").as_string();

    cv::Mat image = cv::imread(image_path); //yaml파일에 저장되어있는 경로 image_path에 저장해놓고

    if (image.empty())
    {
        std::cout<<"경로 불러오기 failed";
        return;
    }

    RCLCPP_INFO(
        this->get_logger(),
        "Image loaded successfully: %d x %d",
        image.cols,
        image.rows
    );

    cv::Mat hsv_image;

    cv::cvtColor(image, hsv_image, cv::COLOR_BGR2HSV); //BGR 값을 HSV로 변환해줌

    cv::Mat red_mask; // Red의 Hue값이 한 구간에 연속적으로 존재 X -> Hue값을 두개로 나눔
    cv::Mat red_mask_1;
    cv::Mat red_mask_2;
    cv::Mat blue_mask;
    cv::Mat green_mask;


    // 하한값, 상한값 정해놓고 범위에 들어오면 255, 벗어나면 0으로 설정함. 
    cv::inRange( // 범위에 들어오는 픽셀을 빨간색 영역으로 판단
        hsv_image,
        cv::Scalar(0, 70, 50), // 순서대로 H S V(하한값)
        cv::Scalar(10, 255, 255), // 순서대로 H S V(상한값)
        red_mask_1
    );

    cv::inRange(
        hsv_image,
        cv::Scalar(170, 70, 50), 
        cv::Scalar(179, 255, 255),
        red_mask_2
    );

    //강의 자료의 bitwise_and와 같은 기능 
    red_mask = red_mask_1 | red_mask_2; //두개로 나눴던 red_mask를 하나로 합치기

    cv::Mat kernel = cv::getStructuringElement(
        cv::MORPH_ELLIPSE,
        cv::Size(15, 15)
    );

    cv::morphologyEx(
        red_mask,
        red_mask,
        cv::MORPH_CLOSE,
        kernel
    );

    //파란색 하한값 상한값 정해주기
    cv::inRange(
        hsv_image,
        cv::Scalar(100, 100, 100),
        cv::Scalar(130, 255, 255),
        blue_mask
    );

    //초록색 하한값 상한값 정해주기 
    cv::inRange(
        hsv_image,
        cv::Scalar(35, 100, 100),
        cv::Scalar(85, 255, 255),
        green_mask
    );

    detectObjects(
        image,
        red_mask,
        "Red",
        cv::Scalar(0, 0, 255)
    );

    detectObjects(
        image,
        blue_mask,
        "Blue",
        cv::Scalar(255, 0, 0)
    );

    detectObjects(
        image,
        green_mask,
        "Green",
        cv::Scalar(0, 255, 0)
    );

    //결과 이미지 저장
    cv::imwrite("result.png", image);

    RCLCPP_INFO(
        this->get_logger(),
        "Result image saved as result.png"
    );
}

void ColorObjectDetection::detectObjects(
    cv::Mat & image,
    const cv::Mat & mask,
    const std::string & color_name,
    const cv::Scalar & box_color)
{
    std::vector<std::vector<cv::Point>> contours;

    //윤곽 찾기
    cv::findContours(
        mask,
        contours,
        cv::RETR_EXTERNAL,
        cv::CHAIN_APPROX_SIMPLE
    );

    int object_count = 0;

    for (const auto & contour : contours)
    {
        double area = cv::contourArea(contour);

        //영역 크기가 500 미만이면 노이즈라고 판단
        if (area < 500.0)
        {
            continue;
        }

        cv::Rect bounding_box = cv::boundingRect(contour);

        object_count++;

        cv::rectangle(image, bounding_box, box_color, 3);

        RCLCPP_INFO(
            this->get_logger(),
            "%s object %d: x=%d, y=%d, width=%d, height=%d, area=%.1f",
            color_name.c_str(),
            object_count,
            bounding_box.x,
            bounding_box.y,
            bounding_box.width,
            bounding_box.height,
            area
        );
    }

    RCLCPP_INFO(
        this->get_logger(),
        "%s objects detected: %d",
        color_name.c_str(),
        object_count
    );
}

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto node =
        std::make_shared<ColorObjectDetection>(); 

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}
