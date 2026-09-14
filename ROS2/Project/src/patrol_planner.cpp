#include "qt_project/patrol_planner.hpp"

void PatrolPlanner::addSeat(const Seat& seat)
{
    seats.push_back(seat); //PatrolPlanner가 가지고있는 std::vector<Seat> seats;에 전달받은 좌석 하나 추가 
}

std::vector<Point> PatrolPlanner::getPatrolSeats()
{
    std::vector<Point> patrol_seats;

    for (int i = 0; i < seats.size(); i++)
    {
        if (seats[i].isPenaltyTarget())
        {
            double x;
            double y;

            seats[i].getPosition(x, y);

            Point point;

            point.id = seats[i].getSeatID();
            point.x = x;
            point.y = y;

            patrol_seats.push_back(point);
        }
    }

    return patrol_seats;
}

std::vector<int> PatrolPlanner::makePatrolRoute()
{
    // 순찰 대상 좌석 가져오기
    std::vector<Point> patrol_seats = getPatrolSeats();

    // 순찰 대상이 없으면 빈 경로 반환
    if (patrol_seats.empty())
    {
        return {};
    }

    // Nearest Neighbor로 초기 경로 생성
    std::vector<int> route = tsp_solver.nearestNeighbor(patrol_seats);

    // 2-opt로 경로 개선
    route = tsp_solver.twoOpt(route, patrol_seats);

    return route;
}

//updateStatus와 다른 점: upstateStatus = 좌석 하나의 상태를 실제로 변경하는 함수 but 이거는 여러 좌석 중에 일치하는 좌석을 찾아주는 역할
void PatrolPlanner::updateSeatStatus(int seat_id,bool occupied, bool has_belongings)
{
    for (int i = 0; i < seats.size(); i++)
    {
        if (seats[i].getSeatID() == seat_id)
        {
            seats[i].updateStatus(occupied, has_belongings);

            return;
        }
    }
}

//사람이 몇명인지에 따라 순찰 주기 조절
int PatrolPlanner::calculatePatrolInterval(int people_count)
{
    if (people_count <= 5)
    {
        return 20;
    }
    else if (people_count <= 15)
    {
        return 10;
    }
    else
    {
        return 5;
    }
}

//현재 좌석에 몇명이 있는지 count
int PatrolPlanner::countOccupiedSeats()
{
    int count = 0;

    for (int i = 0; i < seats.size(); i++)
    {
        if (seats[i].isOccupied())
        {
            count++;
        }
    }

    return count;
}

//service에서 받은 seat_id를 실제 Seat 객체에서 찾음 --> 좌표로 변환 --> 최종 순찰 경로 판단
std::vector<int> PatrolPlanner::makePatrolRoute(std::vector<int> seat_ids)
{
    std::vector<Point> patrol_seats;

    for (int seat_id : seat_ids)
    {
        for (int i = 0; i < seats.size(); i++)
        {
            if (seats[i].getSeatID() == seat_id)
            {
                double x;
                double y;

                seats[i].getPosition(x, y);

                Point point;

                point.id = seat_id;
                point.x = x;
                point.y = y;

                patrol_seats.push_back(point);

                break;
            }
        }
    }

    if (patrol_seats.empty())
    {
        return {};
    }

    std::vector<int> route = tsp_solver.nearestNeighbor(patrol_seats);

    route = tsp_solver.twoOpt(route, patrol_seats);

    return route;
}

//PatrolPlanner에 좌석 존재 여부 확인
bool PatrolPlanner::isValidSeat(int seat_id)
{
    for (int i = 0; i < seats.size(); i++)
    {
        if (seats[i].getSeatID() == seat_id)
        {
            return true;
        }
    }

    return false;
}

//이석한지 20초가 지났는지 아닌지 판단하는 함수
std::vector<int> PatrolPlanner::getPenaltySeatIDs()
{
    std::vector<int> penalty_seat_ids;

    for (int i = 0; i < seats.size(); i++)
    {
        if (seats[i].isPenaltyTarget())
        {
            penalty_seat_ids.push_back(seats[i].getSeatID());
        }
    }

    return penalty_seat_ids;
}

//순찰 완료하면 그 좌석 ID 전달 --> penalty_processed = true로 바꿈
void PatrolPlanner::processPenalty(
    const std::vector<int>& seat_ids)
{
    for (int seat_id : seat_ids)
    {
        for (int i = 0; i < seats.size(); i++)
        {
            if (seats[i].getSeatID() == seat_id)
            {
                seats[i].processPenalty();
                break;
            }
        }
    }
}

void PatrolPlanner::getSeatStatus(
    int seat_id,
    bool& occupied,
    bool& has_belongings,
    int& absence_start_time)
{
    for (int i = 0; i < seats.size(); i++)
    {
        if (seats[i].getSeatID() == seat_id)
        {
            occupied = seats[i].isOccupied();
            has_belongings = seats[i].hasBelongings();
            absence_start_time = seats[i].getAbsenceStartTime();

            return;
        }
    }

    occupied = false;
    has_belongings = false;
    absence_start_time = 0;
}

bool PatrolPlanner::isPenaltyProcessed(int seat_id)
{
    for (int i = 0; i < seats.size(); i++)
    {
        if (seats[i].getSeatID() == seat_id)
        {
            return seats[i].isPenaltyProcessed();
        }
    }

    return false;
}