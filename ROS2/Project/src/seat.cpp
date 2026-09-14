#include "qt_project/seat.hpp"
#include <ctime> //이석 시간 체크 용도


//생성자 활용 --> 변수 초기화
Seat::Seat(int id, double pos_x, double pos_y)
    :seat_id(id), //id -> seta_id, pos_x -> x, pos_y ->y로 초기화됨
     x(pos_x),
     y(pos_y)
{
    occupied = false; //boo값 -> true, false로 설정
    absence_start_time = 0;
    has_belongings = false;
    penalty_processed = false;
}

//private 안에 선언된 변수들을 함수를 활용해서 return값으로 받아오기
//    --> private 변수에는 영향 X
int Seat::getSeatID()
{
    return seat_id;
}

bool Seat::isOccupied()
{
    return occupied;
}

bool Seat::hasBelongings()
{
    return has_belongings;
}

int Seat::getAbsenceStartTime()
{
    return absence_start_time;
}

//Seat 내부의 x,y --> getPosition함수를 거쳐 --> pos_x, pos_y 값으로 전달됨
void Seat::getPosition(double& pos_x, double& pos_y)
{
    pos_x = x;
    pos_y = y;
}

#include <ctime>

// 현재 사람이 있는지, 현재 짐이 있는지 판단
void Seat::updateStatus(bool new_occupied, bool new_has_belongings)
{
    if (new_occupied == true || new_has_belongings == false)
    {
        penalty_processed = false;
    }

    // 사람이 있는 상태에서 사람이 나갔고,
    // 짐이 남아 있는 경우
    if (occupied == true && new_occupied == false && new_has_belongings == true)
    {
        // 짐을 두고 이석한 순간부터 시간 측정
        absence_start_time = std::time(nullptr);
    }

    // 사람이 다시 들어온 경우
    else if (occupied == false && new_occupied == true)
    {
        // 이석 상태 해제
        absence_start_time = 0;
    }

    // 사람이 없고 짐도 없는 경우
    else if (new_occupied == false && new_has_belongings == false)
    {
        // 이석 대상이 아니므로 시간 초기화
        absence_start_time = 0;
    }

    // 현재 상태 갱신
    occupied = new_occupied;
    has_belongings = new_has_belongings;
}

bool Seat::isPenaltyTarget()
{

    std::time_t current_time = std::time(nullptr);

    int absence_total_time = current_time - absence_start_time;
    if(occupied == false && penalty_processed == false && has_belongings == true && (absence_total_time >= 20))
    {
        return true;
    }

    return false;
}

void Seat::processPenalty()
{
    penalty_processed = true;
}

bool Seat::isPenaltyProcessed()
{
    return penalty_processed;
}