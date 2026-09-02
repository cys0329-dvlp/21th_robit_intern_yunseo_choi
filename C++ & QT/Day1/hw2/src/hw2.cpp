#include "Point.hpp"
#include <iostream>
#include <time.h>
#include <math.h>

/*
	<조건>
	1. 메모리 동적할당 사용
	2. structure 이용 -> 2차원 좌표 구현
	3. 2차원 점은 정해진 범위 내에서 랜덤으로 정해진 개수만큼 생성
	4. 2차원 좌표의 범위와 점의 개수는 cin으로 입력

	<계획>
	1. structure에서 x,y 좌표 정의 -> class에서 좌표 받아옴 -> class에 좌표 반환하는 함수 만들어서 main에서 사용
	2. 좌표 랜덤: structure에서 x,y 좌표 정의하고 main에서 랜덤으로 좌표값 할당하는 형식
	3. 좌표의 범위와 점의 개수는 변수는 class에서 선언하고 main문에서 cin으로 입력
	4. 좌표 간 거리 최대 최소 구하는 함수 따로 만들기 -> 시도했지만 함수 정의에서 오류가 생김 -> 구글링해보고 수정해도 해결되지않아 그냥 main에 작성
*/
struct _Point
{
	int* x_arr; //x 좌표 배열

	int* y_arr; //y 좌표 배열
};

int cal_Euclidean_Dist(int point_1, int point_2) // 두 x좌표 사이 거리 계산하는 함수
{
	int target = point_1 - point_2;
	int result = pow(target, 2);

	return result;
}

float cal_Dist_sqrt(int a, int b)
{
	int target = a + b;

	float result = sqrt(target);

	return result; 
}

int a = 0, b = 1, c = 0, d = 1; //만약 index 0,1이 최대 혹은 최소 거리라면 값이 다시 씌워지지않고 0,0으로 그대로 남기 때문에 0,1로 미리 설정을 해둬야함.
int main()
{
	//-----기본 Setting------

	struct _Point struct_point; // struct_point라는 이름으로 구조체 사용(class의 이름도 point이기 때문에 앞에 struct 붙여서 구분함)

	Point class_point; //class_point라는 이름으로 class 활용

	srand(time(NULL)); // 랜덤하게 값 받을 수 있도록함


	//--------점의 개수, 좌표 범위 입력 받기-----------

	//1. 점의 개수 입력받기 

	std::cout << "Please define the number of points: ";
	std::cin >> class_point.point_number;

	//2. 좌표 범위 최소값 입력받기
	std::cout << "Please define minimum of coordinate value: ";
	std::cin >> class_point.min_range;

	//3. 좌표 범위 최대값 입력받기
	std::cout << "Please define maximun of coordinate value: ";
	std::cin >> class_point.max_range;


	//----------x,y 좌표 배열 메모리 동적할당------------

	struct_point.x_arr = new int[class_point.point_number]; // 구조체 메모리 동적할당 -> 생성할 점의 개수에 맞춰서 배열 크기 조절

	struct_point.y_arr = new int[class_point.point_number]; // 구조체 메모리 동적할당 -> 생성할 점의 개수에 맞춰서 배열 크기 조절

	//--------좌표 범위 안에서 점 생성되도록 범위 설정------------

	//1. x 좌표 random하게 생성 

	for (int i = 0; i < class_point.point_number; i++)
	{
		while (struct_point.x_arr[i] < class_point.min_range)
		{
			struct_point.x_arr[i] = rand() % class_point.max_range; // 최대 범위를 초과하지않도록 random하게 생성

			if (struct_point.x_arr[i] >= class_point.min_range) break; // 최소 범위 이상일 때만 while문 종료 -> 최소 최대 범위 모두 지킴
		}

	}

	//2. y 좌표 random하게 생성
	for (int i = 0; i < class_point.point_number; i++)
	{
		while (struct_point.y_arr[i] < class_point.min_range)
		{
			struct_point.y_arr[i] = rand() % class_point.max_range; // 최대 범위를 초과하지않도록 random하게 생성

			if (struct_point.y_arr[i] > class_point.min_range) break; // 최소 범위 이상일 때만 while문 종료 -> 최소 최대 범위 모두 지킴
		}

	}

	//--------생성된 x,y 쌍 출력---------------

	std::cout << "\n\n" << "Generated Random Points" << "\n";

	for (int i = 0; i < class_point.point_number; i++)
	{
		std::cout << "Point" << i << " x: " << struct_point.x_arr[i] << ", y: " << struct_point.y_arr[i] << "\n";
	}

	//----------최소 거리 찾기------------
	float min = cal_Dist_sqrt(cal_Euclidean_Dist(struct_point.y_arr[0], struct_point.y_arr[1]), cal_Euclidean_Dist(struct_point.x_arr[0], struct_point.x_arr[1])); //맨 처음 좌표와 그 다음 좌표를 min이라고 설정
	
	for (int i = 0; i < class_point.point_number - 1; i++) // 모든 경우의 수 계산해야되기 때문에 앞의 값을 인덱스 0으로 고정시키고 뒤에 수 모두 계산 -> 인덱스 1 증가시키고 그 뒤에 수 모두 계산... 이런식으로 해서 모든 경우의수 계산
	{
		for (int j = i + 1; j < class_point.point_number; j++)
		{
			int x = cal_Euclidean_Dist(struct_point.y_arr[i], struct_point.y_arr[j]); //x 좌표 사이 거리 제곱 값
			int y = cal_Euclidean_Dist(struct_point.x_arr[i], struct_point.x_arr[j]); //y 좌표 사이 거리 제곱 값

			if (cal_Dist_sqrt(x, y) < min) // 
			{
				min = cal_Dist_sqrt(x, y);
				a = i;
				b = j;
			}

		}
	}

	//----------최대 거리 찾기------------
	float max = cal_Dist_sqrt(cal_Euclidean_Dist(struct_point.y_arr[0], struct_point.y_arr[1]), cal_Euclidean_Dist(struct_point.x_arr[0], struct_point.x_arr[1])); //맨 처음 좌표와 그 다음 좌표를 min이라고 설정

	for (int i = 0; i < class_point.point_number - 1; i++) // 모든 경우의 수 계산해야되기 때문에 앞의 값을 인덱스 0으로 고정시키고 뒤에 수 모두 계산 -> 인덱스 1 증가시키고 그 뒤에 수 모두 계산... 이런식으로 해서 모든 경우의수 계산
	{
		for (int j = i + 1; j < class_point.point_number; j++)
		{
			int x = cal_Euclidean_Dist(struct_point.y_arr[i], struct_point.y_arr[j]); //x 좌표 사이 거리 제곱 값
			int y = cal_Euclidean_Dist(struct_point.x_arr[i], struct_point.x_arr[j]); //y 좌표 사이 거리 제곱 값

			if (cal_Dist_sqrt(x, y) > max) // 
			{
				max = cal_Dist_sqrt(x, y);
				c = i;
				d = j;
			}

		}
	}

	//---------result 출력---------

	std::cout << "\n\n------result---------\n"; 
	std::cout <<  "minimum: " << min << "\n";
	std::cout << "pair of min coor. : " << "Point " << a << " and " << "Point " << b <<"\n\n";

	std::cout << "maximun: " << max << "\n";
	std::cout << "pair of max coor. : " << "Point " << c << " and " << "Point " << d << "\n\n";

	return 0;

}