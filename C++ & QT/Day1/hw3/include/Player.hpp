#ifndef Player_H
#define Player_H

#include "Monster.hpp"

class Player
{
public:
	int HP = 50, MP = 10, x = 0, y = 0; //class 선언할 때 미리 초기화
	Player();
	Player(int x, int y);
	void Attack(Monster &target);
	void Show_Status();
	void X_move(int move);
	void Y_move(int move);
};

#endif