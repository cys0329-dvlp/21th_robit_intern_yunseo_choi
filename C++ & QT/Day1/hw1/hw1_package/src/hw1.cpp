#include "Array.hpp"
#include <iostream>

/*
	<조건>
	1. 모든 변수와 함수를 클래스 멤버변수, 멤버함수로 작성
	2. 동적할당 사용
	3. 코드에서 생성하는 클래스 객체는 1개

	<계획>
	1. arr 생성 -> 동적할당해서 입력할 원소만큼만큼 생성
	2. 근데 class 사용해야됨 -> class 안에 arr 생성
	3. 나머지 연산 함수도 모두 class에 넣기
*/

int main()
{
	Array array = Array(); //Class 뭐라고 이름 짓고 사용할지 설정

	std::cout << "Enter the length of array: ";

	std::cin >> array.length; //array class의 length라는 멤버변수에 입력하고 저장
	
	array.arr = new int[array.length]; //입력받은 값만큼 arr 배열 길이 동적할당
	
	for (int i = 0; i < array.length; i++)
	{
		std::cout << "please enter int type: ";
		std::cin >> array.arr[i]; // 각 인덱스마다 값 입력받기
	}

	std::cout << "최대값: " << array.define_Max() << "\n";

	std::cout << "최소값: " << array.define_Min() << "\n";

	std::cout << "전체합: " << array.sum() << "\n";

	std::cout << "평균: " << array.avg() << "\n";


	/* 각 인덱스마다 값 잘 들어왔는지 확인하는 모듈
	for (int i = 0; i < array.length; i++)
	{
		std::cout << array.arr[i] << " ";
	}
	*/

	return 0;
}

int Array::define_Max()
{
	int max = arr[0];
	for (int i = 1; i < length; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	return max;
}

int Array::define_Min()
{

	int min = arr[0];

	for (int i = 1; i < length; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	return min;
}

int Array::sum()
{

	int sum = 0;

	for (int i = 0; i < length; i++)
	{
		sum += arr[i];
	}

	return sum;
}

float Array::avg()
{
	float avg = float(sum()) / float(length); //sum, length 모두 정수형이므로 실수형으로 형변환

	return avg;
}
