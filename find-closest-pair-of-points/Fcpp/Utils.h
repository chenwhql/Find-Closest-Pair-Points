#pragma once
#include "Point.h"
#include "PointPair.h"
#include <set>

#define ARRAY_MAX_SIZE (1000000+10)

extern set<Point> point_set_init;  //过滤掉重复的点
extern Point point_set[ARRAY_MAX_SIZE];  //存放输入的点集
extern int point_x[ARRAY_MAX_SIZE];  //存放输入的x坐标
extern set<PointPair> closest_pair_of_points;  //存放寻找的结果
extern int min_distance_square;  //存放最短距离的平方，减少运算量
extern int cnt;  //记录当前存放点的下标

class Utils
{
public:
	Utils();
	~Utils();

	static int calc_distance_square(const Point& p1, const Point& p2);
	static int cmp_int(const void * a, const void * b);
	static int cmp_point_y(const void * a, const void * b);
	static int point_set_partition(Point* P, int p, int r, int m);
	static int find_closest_pair_of_points(Point* P, int p, int r);

};

