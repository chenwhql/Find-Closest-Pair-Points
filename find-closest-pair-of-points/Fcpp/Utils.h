#pragma once
#include "Point.h"
#include "PointPair.h"
#include <set>

#define ARRAY_MAX_SIZE (1000000+10)

extern set<Point> point_set_init;  //���˵��ظ��ĵ�
extern Point point_set[ARRAY_MAX_SIZE];  //�������ĵ㼯
extern int point_x[ARRAY_MAX_SIZE];  //��������x����
extern set<PointPair> closest_pair_of_points;  //���Ѱ�ҵĽ��
extern int min_distance_square;  //�����̾����ƽ��������������
extern int cnt;  //��¼��ǰ��ŵ���±�

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

