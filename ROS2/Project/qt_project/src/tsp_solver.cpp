#include "qt_project/tsp_solver.hpp"
#include <cmath> //sqrt 유클리드 거리 계산에 필요함
#include <limits>
#include <algorithm> // reverse 기능 활용하기 위함
#include <iostream>

double TSPSolver::calculateDistance(double x1, double y1, double x2, double y2)
{
    double Dist;
    Dist = sqrt(pow((x1-x2),2) + pow((y1-y2),2));

    return Dist;
}

//매번 방문하지 않은 좌석 중 가장 가까운 좌석을 찾아야함
/*
    현재 좌석 
    -> 미방문 좌석 확인 
    -> 거리 계산
    -> 가장 짧은 거리 확인
    -> 그 좌석 방문
    -> 반복
*/
std::vector<int> TSPSolver::nearestNeighbor(std::vector<Point> seats)
{
    std::vector<int> route; 
    std::vector<bool> visited(seats.size(), false);

    // 좌석이 하나도 없으면 빈 경로 반환
    if (seats.empty())
    {
        return route;
    }

    // 첫 번째 좌석에서 출발
    int current = 0;
    visited[current] = true;
    route.push_back(seats[current].id);

    // 모든 좌석을 방문할 때까지 반복
    while (route.size() < seats.size())
    {
        double minDistance = std::numeric_limits<double>::max(); //numeric_limits: 초기 minDistance값을 큰 값으로 설정할 수 있게함 -> 실제 거리와 비교할 수 있게함
        int next = -1;

        // 현재 좌석에서 가장 가까운 미방문 좌석 탐색
        for (int i = 0; i < seats.size(); i++)
        {
            if (visited[i] == false) //방문하지 않은 자리인 경우에 최소 거리 계산
            {
                double distance = calculateDistance(seats[current].x, seats[current].y, seats[i].x, seats[i].y);

                if (distance < minDistance) // 방문하지않은 자리 모두 순회하면서 최소 거리 ㅏㅈ음
                {
                    minDistance = distance;
                    next = i; // 계속 순회하면서 최소 거리인 자리의 인덱스를 next에 저장
                }
            }
        }

        // 다음 좌석을 찾지 못한 경우
        if (next == -1)
        {
            break;
        }

        // 가장 가까운 좌석으로 이동
        current = next;
        visited[current] = true;
        route.push_back(seats[current].id);
    }

    return route;
}

std::vector<int> TSPSolver::twoOpt(std::vector<int> route, std::vector<Point> seats)
{
    if(route.size()<3) // 경로 사이즈가 너무 작으면 바꾸는게 의미 없기 때문에 그대로 감
    {
        return route; 
    }

    bool improved = true; //전의 계산 거리보다 더 짧아졌는지 아닌지 판단

    while(improved)
    {
        improved = false; //뒤에서 거리가 더 짧아지면 true로 바뀜

        std::cout << "2-opt 반복 시작" << std::endl;

        for(int i = 1; i<route.size()-1; i++)
        {
            for(int j = i+1; j < route.size()-1; j++)
            {
                Point p1;
                Point p2;
                Point p3;
                Point p4;

                for(int k = 0; k<seats.size(); k++)
                {
                    if(seats[k].id == route[i-1])
                    {
                        p1 = seats[k];
                    }
                    if (seats[k].id == route[i])
                    {
                        p2 = seats[k];
                    }

                    if (seats[k].id == route[j])
                    {
                        p3 = seats[k];
                    }

                    if (seats[k].id == route[j + 1])
                    {
                        p4 = seats[k];
                    }
                }

                //기존 경로 거리
                double oldDistance = calculateDistance(p1.x, p1.y, p2.x, p2.y) + calculateDistance(p3.x, p3.y, p4.x, p4.y);
                
                //경로 뒤집었을 때 거리
                double newDistance =  calculateDistance(p1.x, p1.y, p3.x, p3.y) + calculateDistance(p2.x, p2.y, p4.x, p4.y);

                 if (newDistance < oldDistance)
                {
                    std::reverse(route.begin() + i, route.begin() + j + 1);

                    improved = true;
                }
            }
        }
    }

    return route;
}
