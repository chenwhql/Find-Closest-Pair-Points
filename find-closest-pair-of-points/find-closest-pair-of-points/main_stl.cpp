#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define LOCAL

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

	static bool cmp_by_x(const Point& p1, const Point& p2)
	{
		return p1.x < p2.x;
	}
	static bool cmp_by_y(const Point& p1, const Point& p2)
	{
		return p1.y < p2.y;
	}
};

ostream& operator << (ostream& out, const Point& p)
{
	out << "(" << p.x << "," << p.y << ")";
	return out;
}

//计算两点间的距离
double calc_distance(const Point& p1, const Point& p2)
{
	int x = abs(p2.x - p1.x);
	int y = abs(p2.y - p1.y);
	return sqrt((double)(x*x + y*y));
}
/******************************************/

/************Point pair*****************/
struct PointPair
{
	Point A;
	Point B;

	PointPair(Point A, Point B) :A(A), B(B){};

};
/**************************************/

vector<Point> point_set;  //存放输入的点集
vector<int> point_x;  //存放输入的x坐标
vector<PointPair> closest_pair_of_points;  //存放寻找的结果
double min_distance = 100000;  //存放最短距离

/*************找出划分点集的轴*****************/

/*********************************************/

/***************点集划分函数********************/
int point_set_partition(vector<Point>& P, int p, int r, int m)
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
double find_closest_pair_of_points(vector<Point>& P, int p, int r)
{
	double min_dis = 1000000.0;

	if (r - p + 1 < 2)
	{
		return min_dis;
	}
	else if (r - p + 1 == 2)  //还剩2个点
	{
		min_dis = calc_distance(P[p], P[r]);
		if (min_dis < min_distance)
		{
			min_distance = min_dis;
			closest_pair_of_points.clear();
			closest_pair_of_points.push_back(PointPair(P[p], P[r]));
		}
		else if (min_dis == min_distance)
		{
			closest_pair_of_points.push_back(PointPair(P[p], P[r]));
		}
		return min_dis;
	}
	else if (r - p + 1 == 3) //还剩3个点
	{
		double dis1 = calc_distance(P[p], P[p + 1]);
		double dis2 = calc_distance(P[p + 1], P[r]);
		double dis3 = calc_distance(P[p], P[r]);
		double min_dis = min(min(dis1, dis2), dis3);  //注意着三个距离值可能相等
		if (min_dis < min_distance)
		{
			min_distance = min_dis;
			closest_pair_of_points.clear();
			if (dis1 == min_dis)
			{
				closest_pair_of_points.push_back(PointPair(P[p], P[p + 1]));
			}
			else if (dis2 == min_dis)
			{
				closest_pair_of_points.push_back(PointPair(P[p + 1], P[r]));
			}
			else
			{
				closest_pair_of_points.push_back(PointPair(P[p], P[r]));
			}
		}
		else if (min_dis == min_distance)
		{
			if (dis1 == min_dis)
			{
				closest_pair_of_points.push_back(PointPair(P[p], P[p + 1]));
			}
			else if (dis2 == min_dis)
			{
				closest_pair_of_points.push_back(PointPair(P[p + 1], P[r]));
			}
			else
			{
				closest_pair_of_points.push_back(PointPair(P[p], P[r]));
			}
		}

		return min_dis;
	}
	else  //还剩不止3个点
	{
		//获取划分点集的轴
		int x_median = point_x[p + (r - p) / 2];
		int divide_x = point_set_partition(P, p, r, x_median);
		if (divide_x == r || divide_x == p) return min_dis;
		//递归求解两边的最短距离
		double min_dis_left = find_closest_pair_of_points(P, p, divide_x);
		double min_dis_right = find_closest_pair_of_points(P, divide_x + 1, r);
		min_dis = min(min_dis_left, min_dis_right);
		//这里是否再需要更新min_distance的值？
		//将以轴为中心左右min_x范围内的点提取出来
		vector<Point> point_set_middle;
		for (int i = p; i <= r; ++i)
		{
			if (abs(P[i].x - x_median) <= min_dis)
			{
				point_set_middle.push_back(P[i]);
			}
		}
		//将这些点按Y轴大小排序
		sort(point_set_middle.begin(), point_set_middle.end(), Point::cmp_by_y);
		//每一个点与其后的7个点相比
		for (int i = 0; i < point_set_middle.size(); ++i)
		{
			for (int j = i + 1; j <= ((i + 7) < point_set_middle.size() ? (i + 7) : point_set_middle.size() - 1); ++j)
			{
				//如果纵向间距已经大于min_dis，可以结束该轮比较
				if (abs(point_set_middle[j].x - point_set_middle[i].x) > min_dis)
					break;
				//注意轴上的点划分
				if ((point_set_middle[i].x < x_median && point_set_middle[j].x > x_median) ||
					(point_set_middle[i].x > x_median && point_set_middle[j].x < x_median) ||
					point_set_middle[i].x == x_median)
				{
					double min_new = calc_distance(point_set_middle[i], point_set_middle[j]);
					if (min_new < min_dis)
					{
						min_dis = min_new;
					}
					if (min_new < min_distance)
					{
						min_distance = min_new;
						closest_pair_of_points.clear();
						closest_pair_of_points.push_back(PointPair(point_set_middle[i], point_set_middle[j]));
					}
					else if (min_new == min_distance)
					{
						closest_pair_of_points.push_back(PointPair(point_set_middle[i], point_set_middle[j]));
					}
				}
			}
		}
	}

	return min_dis;
}

int main()
{
#ifdef LOCAL
	freopen("in_1_000_000.txt", "r", stdin);
	freopen("out.txt","w",stdout);
#endif
	int a, b;
	double t_start = 0.0, t_end = 0.0;

	//初始化随机数种子 
	//srand(time(NULL));

	//input
	while (scanf("%d %d", &a, &b) == 2)
	{
		point_x.push_back(a);
		point_set.push_back(Point(a, b));
	}

	//记录开始时间
	t_start = (double)clock() / CLOCKS_PER_SEC;
	//计算
	sort(point_x.begin(), point_x.end());
	double closest_distance = find_closest_pair_of_points(point_set, 0, point_set.size() - 1);
	//记录结束时间
	t_end = (double)clock() / CLOCKS_PER_SEC;
	//输出计算时间
	printf("Calc Time used = %.2f\n", t_end - t_start);
	//输出结果
	cout << "the distancce: " << min_distance << endl;
	cout << "the closest pair of points:" << endl;
	for (vector<PointPair>::iterator it = closest_pair_of_points.begin(); it != closest_pair_of_points.end(); ++it)
	{
		cout << it->A << " and " << it->B << endl;
	}

	return 0;
}