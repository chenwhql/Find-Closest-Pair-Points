#pragma once
#include<iostream>
using namespace std;

class Point
{
public:
	int x, y;

	Point(int x = 0, int y = 0) :x(x), y(y){}

	Point& operator = (const Point& p);

	bool operator == (const Point& b) const;

	bool operator < (const Point& b) const;
};

ostream& operator << (ostream& out, const Point& p);
