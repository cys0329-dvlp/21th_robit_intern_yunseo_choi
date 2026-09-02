#ifndef Monster_H
#define Monster_H

class Monster
{
public:
	int HP = 50, x = 5, y = 4; //class 선언할 때 미리 초기화
	Monster();
	Monster(int x, int y, int HP);
	int Be_Attacked();
};

#endif