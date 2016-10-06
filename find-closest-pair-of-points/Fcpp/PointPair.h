#pragma once
#include "Point.h"

class PointPair
{
public:
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

	bool operator == (PointPair& X) const;

	bool operator < (const PointPair& X) const;
};

