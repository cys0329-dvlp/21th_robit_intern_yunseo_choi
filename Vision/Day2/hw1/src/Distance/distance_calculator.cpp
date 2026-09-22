#include "CalDist_pkg/Distance/distance_calculator.hpp"

DistanceCalculator::DistanceCalculator()
{
}

double DistanceCalculator::calculateDistanceA(
    double REAL_ball_size,
    double camera_ball_size,
    double fx
)
{
    if (camera_ball_size <= 0.0)
    {
        return 0.0;
    }

    
    return (fx * REAL_ball_size) / camera_ball_size;
}

double DistanceCalculator::calculateDistanceB(
    double h,
    double theta,
    double v,
    double fy,
    double cy
)
{
    if (fy <= 0.0)
    {
        return 0.0;
    }

    //세타는 카메라의 각도, angle은 카메라 화면에서 공이 어디에 위치해있는지 판단하는 각도
    double yn = (v - cy) / fy;

    double theta_rad = theta * M_PI / 180.0; //M_PI = 파이(3.1415..)

    double angle = theta_rad + std::atan(yn);

    double tan_value = std::tan(angle);

    if (std::abs(tan_value) < 1e-9)
    {
        return 0.0;
    }

    return h / tan_value;
}

