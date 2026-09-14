#ifndef PATROL_PLANNER_HPP
#define PATROL_PLANNER_HPP

#include <vector>

#include "qt_project/seat.hpp"
#include "qt_project/tsp_solver.hpp"

class PatrolPlanner{

    private:
        std::vector<Seat> seats; //실제 좌석을 저장하는 공간
        TSPSolver tsp_solver; // TSP알고리즘을 PatrolPlanner가 사용하기위해 객체 생성

    public: 
        void addSeat(const Seat& seat); // 좌석을 seats에 추가하는 함수

        std::vector<Point> getPatrolSeats(); // 현재 순찰해야하는 좌석만 골라서 Point 형태로 반환 

        std::vector<int> makePatrolRoute(); // 최종적으로 route를 결정하는 함수 

        //특정 좌석의 상태를 Seat 객체에 전달 
        void updateSeatStatus(int seat_id, bool occupied, bool has_belongings);

        //현재 자습실에 사람이 몇명 있는지 받아서 순찰 주기 결정하는 함수
        int calculatePatrolInterval(int people_count);

        //최종 사람 수 반환 
        int countOccupiedSeats();

        std::vector<int> makePatrolRoute(std::vector<int> seat_ids);

        bool isValidSeat(int seat_id); //PatrolPlanner에 좌석 존재 여부 확인
        
        std::vector<int> getPenaltySeatIDs();

        void processPenalty(const std::vector<int>& seat_ids);

        void getSeatStatus(int seat_id, bool& occupied, bool& has_belongings, int& absence_start_time);
        bool isPenaltyProcessed(int seat_id);

};

#endif