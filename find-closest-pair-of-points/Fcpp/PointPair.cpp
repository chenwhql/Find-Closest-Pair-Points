#include "stdafx.h"
#include "PointPair.h"


bool PointPair::operator == (PointPair& X) const
{
	if ((this->A == X.A && this->B == X.B) ||
		(this->A == X.B && this->B == X.A))
		return true;
	else
		return false;
}

bool PointPair::operator < (const PointPair& X) const
{
	if (this->A == X.A)
		return this->B < X.B;
	return this->A < X.A;
}
