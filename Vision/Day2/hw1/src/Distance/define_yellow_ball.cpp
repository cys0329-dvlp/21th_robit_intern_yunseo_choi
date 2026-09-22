#include "CalDist_pkg/Distance/define_yellow_ball.hpp"
#include <rclcpp/rclcpp.hpp>

DefineYellowBall::DefineYellowBall()
{
}

//------------------HSV 변환------------------------
cv::Mat DefineYellowBall::HSV(const cv::Mat &frame)
{
    cv::Mat hsv_frame;

    cv::cvtColor(frame,hsv_frame,cv::COLOR_BGR2HSV); // BGR로 입력받은 이미지를 HSV로 변환

    return hsv_frame;
}

//-------------노란색 mask 생성-------------------------
cv::Mat DefineYellowBall::createYellowMask(const cv::Mat &hsv_frame)
{
    cv::Mat yellow_mask;

    cv::inRange(hsv_frame,cv::Scalar(20, 100, 100),cv::Scalar(35, 255, 255),yellow_mask);

    return yellow_mask;
}

//---------노이즈 제거-----------------------------------
cv::Mat DefineYellowBall::removeNoise(const cv::Mat &yellow_mask)
{
    cv::Mat cleaned_mask;

    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE,cv::Size(15, 15));

    cv::morphologyEx(yellow_mask,cleaned_mask,cv::MORPH_CLOSE, kernel);

    return cleaned_mask;
}

//------------진짜 contour를 찾는 역할만 수행-----------
std::vector<std::vector<cv::Point>>

DefineYellowBall::findContours(const cv::Mat &yellow_mask)
{
    std::vector<std::vector<cv::Point>> contours;

    cv::findContours(yellow_mask,contours,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE);

    return contours;
}

//-----------contour 면적을 기준으로 생기는 작은 노이즈 제거----------
std::vector<std::vector<cv::Point>>
DefineYellowBall::filterContours(const std::vector<std::vector<cv::Point>> &contours)
{
    std::vector<std::vector<cv::Point>> filtered_contours;

    for (const auto &contour : contours)
    {
        double area = cv::contourArea(contour);

        if (area < 500.0)
        {
            continue;
        }

        filtered_contours.push_back(contour);
    }

    return filtered_contours;
}

//위에 선언된 모든 함수들 전과정 엮어줌
YellowBallResult DefineYellowBall::detect(cv::Mat &frame)
{
    YellowBallResult result;

    //구조체에 정의된 변수들 초기화
    result.detected = false;
    result.center = cv::Point(0, 0);
    result.radius = 0.0f;
    result.area = 0.0;
    result.bounding_box = cv::Rect();

    //frame이 없으면 return 
    if (frame.empty())
    {
        return result;
    }

    //전체 과정 순서대로 실행
    cv::Mat hsv_frame = HSV(frame);

    cv::Mat yellow_mask = createYellowMask(hsv_frame);

    cv::Mat cleaned_mask = removeNoise(yellow_mask);

    std::vector<std::vector<cv::Point>> contours = findContours(cleaned_mask);

    std::vector<std::vector<cv::Point>> filtered_contours = filterContours(contours);
    
    if(filtered_contours.empty())
    {
        return result;
    }

    double largest_area = 0.0;
    std::vector<cv::Point> largest_contour;


    for (const auto &contour : filtered_contours)
    {
        double area = cv::contourArea(contour);

        if (area > largest_area)
        {
            largest_area = area;
            largest_contour = contour;
        }
    }
    
    if (largest_contour.empty())
    {
        return result;
    }

    cv::Rect bounding_box = cv::boundingRect(largest_contour);

    cv::Point2f center;
    float radius;
        
    cv::minEnclosingCircle(largest_contour,center,radius);
        
    result.detected = true;
    result.center = cv::Point(static_cast<int>(center.x),static_cast<int>(center.y));
        
    result.radius = radius;
    result.area = largest_area;
    result.bounding_box = bounding_box;

    RCLCPP_INFO_ONCE(
    rclcpp::get_logger("yellow_ball_test"),
    "Ball detected - center: (%d, %d), radius: %.2f, area: %.2f, bbox: (%d, %d, %d, %d)",
    result.center.x,
    result.center.y,
    result.radius,
    result.area,
    result.bounding_box.x,
    result.bounding_box.y,
    result.bounding_box.width,
    result.bounding_box.height
    );

    cv::rectangle(frame,bounding_box,cv::Scalar(0, 255, 0),3);

    return result;
}