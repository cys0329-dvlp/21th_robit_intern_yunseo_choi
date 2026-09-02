#include "Player.hpp"
#include "Monster.hpp"
#include <iostream>
#include <time.h>
using namespace std;
/*
	<조건>
	1. 명령어 입력받아서 플레이어 이동, 공격, status 표기 실행
	2. 몬스터 HP == 0 -> end
	3. 공격 한번 당 MP -1, MP 부족 상태에서 공격하면 END
	4. class 구성 참고

	<계획>
	1. x 좌표, y 좌표 따로 저장하는 변수 설정
	2. +-1 씩 해주는건 move 함수로 처리 -> 계속 갱신
	3. 전체 while 문으로 감싸서 무한 루프 돌리고 탈출 조건을 MP 소모 혹은 몬스터 피 0으로 설정
	4. 공격 성공 확률은 따로 명시되어있지않으므로 40%로 임의로 정함
*/

//---------기본 Setting----------

// **캐릭터 초기 값은 hpp파일에서 미리 선언해두었습니다**
Player::Player(int x, int y)
{
	this ->x = x;
	this-> y = y;
	HP = 0;
	MP = 0;
}

Monster::Monster(int x, int y, int HP)
{
	this->x = x;
	this->y = y;
	this->HP = HP;
}

//-----------기능 함수들----------
void Player::Show_Status()
{
	cout << "HP: " << HP << "\n" << "MP: " << MP << "\n" << "Position: " << x << ", " << y<<"\n";
}

void Player::X_move(int move)
{
	x += move;
}

void Player::Y_move(int move)
{
	y += move;
}

int Monster::Be_Attacked()
{
	HP -= 10;
	return HP;
}
int flag = 0; // Attack 함수가 void 이므로 return 값을 main으로 보내서 break를 사용할 수 없으므로 flag를 전역 변수로 설정해 main에 신호 보내는 용도
void Player::Attack(Monster &target)
{
	
	int percent = rand() % 100;
	if (percent >= 60) // 공격 성공
	{
		MP--; // 공격 실패, 성공 여부에 상관없이 1씩 깎임
		target.Be_Attacked(); // 공격 성공 시 target(monster)의 체력 -10
		cout << "공격 성공!\n" << "남은 체력: " << target.HP << "\n";
		if (target.HP == 0)
		{
			cout << "monster died!\n";
			flag = 1;
		}
		else if (MP < 0)
		{
			cout << "MP 부족!\n";
			flag = 1;
		}
	}

	else
	{	
		MP--; // 공격 실패, 성공 여부에 상관없이 1씩 깎임
		if (MP < 0)
		{
			cout << "MP 부족!\n";
			flag = 1;
		}
		else
		{
			cout << "공격 실패!\n" << "남은 체력: " << target.HP << "\n";
		}
	}

}

//--------main 함수------------
int main()
{
	srand(time(NULL)); // 공격 확률 40퍼 만들기 위해 랜덤함수로 값이 60 이상이면 공격 성공, 60 미만이면 공격 실패로 판단.

	//-----기본 Setting-----

	//1. 초기값 Setting
	Player player(0,0);

	Monster monster(5,4,50);
	
	//2. player Setting
	player.HP = 50;
	player.MP = 10;
	
	char Command;
	while (1)
	{
		cout << "Type Command(A/U/D/R/L/S)\n";
		cin >> Command; 

		if (Command == 'S')
		{
			player.Show_Status();
		}

		else if (Command == 'A')
		{
			player.Attack(monster);
			if (flag == 1)
			{
				break;
			}
		}
		else if (Command == 'D')
		{
			player.Y_move(-1);
			cout << "Y Position -1 moved!\n";
		}
		else if (Command == 'R')
		{
			player.X_move(1);
			cout << "X Position 1 moved!\n";
		}
		else if (Command == 'U')
		{
			player.Y_move(1);
			cout << "Y Position 1 moved!\n";
		}
		else if (Command == 'L')
		{
			player.X_move(-1);
			cout << "X Position -1 moved!\n";
		}
		
	}
	
	return 0;
}