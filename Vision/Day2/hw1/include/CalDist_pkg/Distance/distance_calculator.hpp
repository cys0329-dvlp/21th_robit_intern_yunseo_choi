#ifndef CALDIST_PKG_DISTANCE_CALCULATOR_HPP
#define CALDIST_PKG_DISTANCE_CALCULATOR_HPP

#include "CalDist_pkg/Distance/define_yellow_ball.hpp"

class DistanceCalculator
{
public:
    DistanceCalculator();

    double calculateDistance(
        const YellowBallResult &ball
    );

private:

    float REAL_ball_size;
    float camera_ball_size;
    // 거리 계산에 필요한 값
    // 예: 실제 공 크기, 카메라 관련 값 등

};

#endif 