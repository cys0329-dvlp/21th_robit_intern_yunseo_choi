#ifndef SEAT_HPP
#define SEAT_HPP

class Seat{

    private:
        int seat_id; //좌석 번호
        bool occupied; //사람이 있는지 없는지 판단 
        int absence_start_time; //좌석에서 이탈한 시간
        bool has_belongings; //짐이 남아있는지 없는지 체크

        double x,y;
        bool penalty_processed; //벌점이 들어갔는지 안들어갔는지 체크

    
    public:

        Seat(int id, double pose_x, double pos_y); //생성자

        int getSeatID(); //ID 받아오기
        bool isOccupied(); //사람 있는지 없는지 판단
        bool hasBelongings(); 
        int getAbsenceStartTime(); //좌석에서 이탈한 시간

        void getPosition(double& pos_x, double& pos_y); //좌석 위치 조회

        void updateStatus(bool new_occupied, bool new_has_belongings); //좌석 상태 변경
        bool isPenaltyTarget(); //벌점 대상 여부 확인 

        void processPenalty();
        bool isPenaltyProcessed();

};

#endif