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
}

//���������ľ���
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

vector<Point> point_set;  //�������ĵ㼯
vector<PointPair> closest_pair_of_points;  //���Ѱ�ҵĽ��
double min_distance = 100000;  //�����̾���

/*************select ��iС��Ԫ��*****************/
//�㷨����9.3�� SELECT�㷨 �ҳ��ܹ����㼯�ȷֵ�x��
//1. ��ȡ��λ��  ע��������ֵ�ϵ���λ�����������֣������ǻ��ֵ㼯���м���
int get_median(vector<int>& A, int p, int r)
{
	vector<int> median_set; //��Ÿ������λ��
	int n = r - p + 1;
	int last_group_member_num = n % 5;
	int five_member_group_num = n / 5; //n��Ԫ�ػ���Ϊ��n/5������ȡ������

	for (int i = p; i < n / 5; i++)
	{
		sort(A[p + i * 5], A[p + i * 5 + 4]);  //����
		median_set.push_back(A[p + i * 5 + 2]);
	}
	if (last_group_member_num != 0)
	{
		sort(A[n - last_group_member_num + 1], A[r]);
		median_set.push_back(A[n - last_group_member_num + (last_group_member_num/2)]);
	}

	//�ݹ��������
	if (median_set.size() == 1)
	{
		return median_set[0];
	}
	else
	{
		return get_median(median_set, 0, median_set.size()-1);
	}

	return 0; //����ִ�е�
}

//2. ����λ����������л���
int partition(vector<int>& A, int p, int r, int key)
{
	//�ҳ�x������λ����Ӧ�ĵ��λ��,�������һ���㽻��
	for (int i = p; i <= r; ++i)
	{
		if (A[i] == key)
		{
			swap(A[i], A[r]);
		}
	}
	//��¼����
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (A[j] <= key)
		{
			i++;
			swap(A[j], A[i]);
		}
	}
	swap(A[i + 1], A[r]);

	return i + 1;
}

//3. ѡ���iС��Ԫ��
int select(vector<int>& A, int p, int r, int i)
{
	//��ȡ��������λ��
	int median = get_median(A, p, r);
	int q = partition(A, p, r, median);
	int k = q - p + 1;
	if (i == k)
	{
		return A[i];
	}
	else if (i < k)
	{
		select(A, p, q-1, i);
	}
	else
	{
		select(A, q + 1, r, i - k);
	}
}
/*********************************************/

/***************�㼯���ֺ���********************/
int point_set_partition(vector<Point>& P, int p, int r, int m)
{
	//�ҳ�x������λ����Ӧ�ĵ��λ��,�������һ���㽻��
	for (int i = p; i <= r; ++i)
	{
		if (P[i].x == m)
		{
			swap(P[i], P[r]);
		}
	}
	//��¼����
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

//Ѱ�������Ժ���
double find_closest_pair_of_points(vector<Point>& P, int p, int r)
{
	if (r - p + 1 == 2)  //��ʣ2����
	{
		double dis = calc_distance(P[p], P[r]);
		if (dis < min_distance)
		{
			min_distance = dis;
			closest_pair_of_points.clear();
			closest_pair_of_points.push_back(PointPair(P[p], P[r]));
		}
		else if (dis == min_distance)
		{
			closest_pair_of_points.push_back(PointPair(P[p], P[r]));
		}
		return dis;
	}
	else if (r - p + 1 == 3) //��ʣ3����
	{
		double dis1 = calc_distance(P[p], P[p + 1]);
		double dis2 = calc_distance(P[p + 1], P[r]);
		double dis3 = calc_distance(P[p], P[r]);
		double min_dis = min(min(dis1, dis2), dis3);  //ע������������ֵ�������
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
	}
	else  //��ʣ��ֹ3����
	{
		//��ȡ�㼯��x���꼯
		vector<int> point_x;
		for (int i = 0; i < P.size(); ++i)
		{
			point_x.push_back(P[i].x);
		}
		//��ȡ���ֵ㼯����
		int x_median = select(point_x, 0, point_x.size(), point_x.size()/2);
		int divide_x = point_set_partition(P, p, r, x_median);
		//�ݹ�������ߵ���̾���
		double min_dis_left = find_closest_pair_of_points(P, p, divide_x);
		double min_dis_right = find_closest_pair_of_points(P, divide_x + 1, r);
		double min_x = min(min_dis_left, min_dis_right);
		//�����Ƿ�����Ҫ����min_distance��ֵ��
		//������Ϊ��������min_x��Χ�ڵĵ���ȡ����
		vector<Point> point_set_middle;
		for (int i = p; i <= divide_x; ++i)
		{
			if (abs(P[i].x - divide_x) <= min_x)
			{
				point_set_middle.push_back(P[i]);
			}
		}
		//����Щ�㰴Y���С����
		sort(point_set_middle.begin(), point_set_middle.end(), Point::cmp_by_y);
		//ÿһ����������7�������
		for (int i = 0; i < point_set_middle.size(); i++)
		{
			if ()
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("in.txt","r",stdin);
#endif


	//��ʼ����������� 
	srand(time(NULL));

	//


	return 0;
}