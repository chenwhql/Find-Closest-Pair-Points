#include "stdafx.h"
#include "Point.h"

Point& Point::operator = (const Point& p)
{
	this->x = p.x;
	this->y = p.y;
	return *this;
}

bool Point::operator == (const Point& b) const
{
	if (this->x == b.x && this->y == b.y)
		return true;
	else
		return false;
}

bool Point::operator < (const Point& b) const
{
	if (this->x == b.x)
		return this->y < b.y;
	return this->x < b.x;
}

ostream& operator << (ostream& out, const Point& p)
{
	out << "(" << p.x << "," << p.y << ")";
	return out;
}