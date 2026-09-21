#include "CalDist_pkg/Distance/distance_calculator.hpp"

DistanceCalculator::DistanceCalculator()
{
    // 필요한 초기값 설정
}

double DistanceCalculator::calculateDistance(
    const YellowBallResult &ball
)
{
    if (!ball.detected)
    {
        return 0.0;
    }

    // 1. 공의 크기 정보 가져오기


    // 2. 거리 계산에 필요한 값 준비


    // 3. 거리 계산


    // 4. 계산된 거리 반환

}