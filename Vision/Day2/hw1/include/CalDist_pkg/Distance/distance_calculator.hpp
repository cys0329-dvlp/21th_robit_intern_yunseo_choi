#ifndef CALDIST_PKG_DISTANCE_CALCULATOR_HPP
#define CALDIST_PKG_DISTANCE_CALCULATOR_HPP

#include "CalDist_pkg/Distance/define_yellow_ball.hpp"

class DistanceCalculator
{
public:
    DistanceCalculator();

    double calculateDistanceA(
        double REAL_ball_size,
        double camera_ball_size,
        double fx
    );

    double calculateDistanceB(
        double h,
        double theta,
        double v,
        double fy,
        double cy
    );

private:

    double REAL_ball_size; //공식에서의 W
    double camera_ball_size; // 공식에서의 w
    
    double Distance; //공식에서의 Z
    double fx; // 공식에서의 fx


};

#endif 