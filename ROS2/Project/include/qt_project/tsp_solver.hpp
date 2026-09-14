#ifndef TSP_SOLVER_HPP
#define TSP_SOLVER_HPP

#include <vector>


struct Point
{
    int id;
    double x;
    double y;
    
};


class TSPSolver{

    private:


    public:
        double calculateDistance(double x1, double y1, double x2, double y2);
        std::vector<int> nearestNeighbor(std::vector<Point> seats); //순찰할 좌석의 개수 int를 저장하는 vector
        //경로의 두 구간을 뒤집어보면서 전체 거리가 줄어드는지 확인하는 알고리즘
        std::vector<int> twoOpt(std::vector<int> route, std::vector<Point> seats);
};      

#endif