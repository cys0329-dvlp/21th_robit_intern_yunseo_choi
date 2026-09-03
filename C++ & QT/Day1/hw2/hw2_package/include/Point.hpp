#ifndef Point_H
#define Point_H

class Point
{
public:
	int max_range; // 좌표 범위 최대값
	int min_range; // 좌표 범위 최소값
	int point_number; // 점의 개수

	int cal_Euclidean_Dist(int point_1, int point_2);
	float cal_Dist_sqrt(int a, int b);
};

#endif