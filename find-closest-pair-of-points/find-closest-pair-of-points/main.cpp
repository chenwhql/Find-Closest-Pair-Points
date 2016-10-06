#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<iostream>
//#include<vector>
#include<set>
#include<algorithm>
using namespace std;

#define LOCAL
#define ARRAY_MAX_SIZE (1000000+10)

/****************Point******************/
//point struct
struct Point
{
	int x, y;

	Point(int x = 0, int y = 0) :x(x), y(y){}

	Point& operator = (const Point& p)
	{
		this->x = p.x;
		this->y = p.y;
		return *this;
	}

	bool operator == (const Point& b) const
	{
		if (this->x == b.x && this->y == b.y)
			return true;
		else
			return false;
	}

	bool operator < (const Point& b) const
	{
		if (this->x == b.x)
			return this->y < b.y;
		return this->x < b.x;
	}
};

ostream& operator << (ostream& out, const Point& p)
{
	out << "(" << p.x << "," << p.y << ")";
	return out;
}

//计算两点间的距离的平方
int calc_distance_square(const Point& p1, const Point& p2)
{
	int x = abs(p2.x - p1.x);
	int y = abs(p2.y - p1.y);
	return (x*x + y*y);
}
/******************************************/

/************Point pair*****************/
struct PointPair
{
	Point A;
	Point B;

	PointPair(Point A, Point B) :A(A), B(B)
	{
		//让较小的点在前面
		if (this->B < this->A)
		{
			swap(this->A, this->B);
		}
	}

	bool operator == (PointPair& X) const
	{
		if ((this->A == X.A && this->B == X.B) ||
			(this->A == X.B && this->B == X.A))
			return true;
		else
			return false;
	}

	bool operator < (const PointPair& X) const
	{
		if (this->A == X.A)
			return this->B < X.B;
		return this->A < X.A;
	}

};
/**************************************/

set<Point> point_set_init;  //过滤掉重复的点
Point point_set[ARRAY_MAX_SIZE];  //存放输入的点集
int point_x[ARRAY_MAX_SIZE];  //存放输入的x坐标
set<PointPair> closest_pair_of_points;  //存放寻找的结果
int min_distance_square = 10000000000;  //存放最短距离的平方，减少运算量

/***********对比函数，辅助qsort****************/
int cmp_int(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}
int cmp_point_y(const void * a, const void * b)
{
	return ((*(Point*)a).y - (*(Point*)b).y);
}
/*******************************************/

/***************点集划分函数********************/
int point_set_partition(Point* P, int p, int r, int m)
{
	//找出x坐标中位数对应的点的位置,并与最后一个点交换
	for (int i = p; i <= r; ++i)
	{
		if (P[i].x == m)
		{
			swap(P[i], P[r]);
		}
	}
	//记录主键
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (P[j].x <= m)
		{
			i++;
			swap(P[j], P[i]);
		}
	}
	swap(P[i + 1], P[r]);

	return i + 1;
}
/*********************************************/

//寻找最近点对函数
int find_closest_pair_of_points(Point* P, int p, int r)
{
	int min_dis_square = 10000000000;

	if (r - p + 1 < 2)
	{
		return min_dis_square;
	}
	else if (r - p + 1 == 2)  //还剩2个点
	{
		min_dis_square = calc_distance_square(P[p], P[r]);
		if (min_dis_square < min_distance_square)
		{
			min_distance_square = min_dis_square;
			closest_pair_of_points.clear();
			closest_pair_of_points.insert(PointPair(P[p], P[r]));
		}
		else if (min_dis_square == min_distance_square)
		{
			closest_pair_of_points.insert(PointPair(P[p], P[r]));
		}
		return min_dis_square;
	}
	else if (r - p + 1 == 3) //还剩3个点
	{
		int dis1 = calc_distance_square(P[p], P[p + 1]);
		int dis2 = calc_distance_square(P[p + 1], P[r]);
		int dis3 = calc_distance_square(P[p], P[r]);
		min_dis_square = min(min(dis1, dis2), dis3);  //注意着三个距离值可能相等
		if (min_dis_square < min_distance_square)
		{
			min_distance_square = min_dis_square;
			closest_pair_of_points.clear();
			if (dis1 == min_dis_square)
			{
				closest_pair_of_points.insert(PointPair(P[p], P[p + 1]));
			}
			else if (dis2 == min_dis_square)
			{
				closest_pair_of_points.insert(PointPair(P[p + 1], P[r]));
			}
			else
			{
				closest_pair_of_points.insert(PointPair(P[p], P[r]));
			}
		}
		else if (min_dis_square == min_distance_square)
		{
			if (dis1 == min_dis_square)
			{
				closest_pair_of_points.insert(PointPair(P[p], P[p + 1]));
			}
			else if (dis2 == min_dis_square)
			{
				closest_pair_of_points.insert(PointPair(P[p + 1], P[r]));
			}
			else
			{
				closest_pair_of_points.insert(PointPair(P[p], P[r]));
			}
		}

		return min_dis_square;
	}
	else  //还剩不止3个点
	{
		//获取划分点集的轴
		int x_median = point_x[p + (r - p) / 2];
		int divide_x = point_set_partition(P, p, r, x_median);
		if (divide_x == r || divide_x == p) return min_dis_square;
		//递归求解两边的最短距离
		int min_dis_square_left = find_closest_pair_of_points(P, p, divide_x);
		int min_dis_square_right = find_closest_pair_of_points(P, divide_x + 1, r);
		min_dis_square = min(min_dis_square_left, min_dis_square_right);
		//这里是否再需要更新min_distance_square的值？
		//将以轴为中心左右min_x范围内的点提取出来
		Point* point_set_middle = new Point[r-p+1];
		int cnt = 0;
		for (int i = p; i <= r; ++i)
		{
			if (abs(P[i].x - x_median) <= min_dis_square)
			{
				point_set_middle[cnt++] = P[i];
			}
		}
		//将这些点按Y轴大小排序
		qsort(point_set_middle, cnt, sizeof(Point), cmp_point_y);
		//每一个点与其后的7个点相比
		for (int i = 0; i < cnt; ++i)
		{
			for (int j = i + 1; j <= ((i + 7) < cnt ? (i + 7) : cnt - 1); ++j)
			{
				//如果纵向间距已经大于min_dis_square，可以结束该轮比较
				if (abs(point_set_middle[j].y - point_set_middle[i].y) > min_dis_square)
					break;
				//注意轴上的点划分
				if ((point_set_middle[i].x < x_median && point_set_middle[j].x > x_median) ||
					(point_set_middle[i].x > x_median && point_set_middle[j].x < x_median) ||
					point_set_middle[i].x == x_median)
				{
					int min_new = calc_distance_square(point_set_middle[i], point_set_middle[j]);
					if (min_new < min_dis_square)
					{
						min_dis_square = min_new;
					}
					if (min_new < min_distance_square)
					{
						min_distance_square = min_new;
						closest_pair_of_points.clear();
						closest_pair_of_points.insert(PointPair(point_set_middle[i], point_set_middle[j]));
					}
					else if (min_new == min_distance_square)
					{
						closest_pair_of_points.insert(PointPair(point_set_middle[i], point_set_middle[j]));
					}
				}
			}
		}
	}

	return min_dis_square;
}

int main()
{
#ifdef LOCAL
	freopen("in_1_000_000.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int a, b, cnt = 0;
	double t_start = 0.0, t_end = 0.0;

	//初始化随机数种子 
	//srand(time(NULL));

	//input
	while (scanf("%d %d", &a, &b) == 2)
	{
		point_set_init.insert(Point(a,b));
	}

	for (set<Point>::iterator it = point_set_init.begin(); it != point_set_init.end(); ++it)
	{
		point_x[cnt] = it->x;
		point_set[cnt++] = *it;
	}	

	//记录开始时间
	t_start = (double)clock() / CLOCKS_PER_SEC;
	//计算,set在插入的时候已经是有序的
	//qsort(point_x, cnt, sizeof(int), cmp_int);
	int closest_distance_square = find_closest_pair_of_points(point_set, 0, cnt - 1);
	//记录结束时间
	t_end = (double)clock() / CLOCKS_PER_SEC;
	//输出计算时间
	printf("Calc Time used = %.2f\n", t_end - t_start);
	//输出结果
	cout << "the distancce: " << sqrt((double)closest_distance_square) << endl;
	cout << "the closest pair of points:" << endl;
	for (set<PointPair>::iterator it = closest_pair_of_points.begin(); it != closest_pair_of_points.end(); ++it)
	{
		cout << it->A << " and " << it->B << endl;
	}

	return 0;
}