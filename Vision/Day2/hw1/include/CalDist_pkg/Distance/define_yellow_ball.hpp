#ifndef CALDIST_PKG_DEFINE_YELLOW_BALL_HPP
#define CALDIST_PKG_DEFINE_YELLOW_BALL_HPP

#include <opencv2/opencv.hpp>

struct YellowBallResult //검출 결과를 저장하는 구조체
{
    bool detected;

    cv::Point center;

    float radius;

    double area;

    cv::Rect bounding_box;
};

class DefineYellowBall
{
public:
    DefineYellowBall();
    
    //private에 정의된 함수들을 순서대로 전과정 연결
    YellowBallResult detect(cv::Mat &frame);

private:
    //BGR 이미지 입력 -> HSV 이미지 출력
    cv::Mat HSV(const cv::Mat &frame);

    //HSV에서 노란색 영역 추출
    cv::Mat createYellowMask(const cv::Mat &hsv_frame);

    //노이즈 제거 함수
    cv::Mat removeNoise(const cv::Mat &yellow_mask);

    //정리된 mask에서 contour 추출
    std::vector<std::vector<cv::Point>> findContours(const cv::Mat &hsv_frame);

    //contour 면적을 기준으로 작은 노이즈 제거하는 함수
    std::vector<std::vector<cv::Point>> filterContours(const std::vector<std::vector<cv::Point>> &contours);
};

#endif // CALDIST_PKG_DEFINE_YELLOW_BALL_HPP