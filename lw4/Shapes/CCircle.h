#pragma once
#include "CShape.h"
#include "Point.h"
#define _USE_MATH_DEFINES
#include "math.h"

class CCircle final :
	public CShape
{
public:
	CCircle(Point p1, std::string radius);

	CBigNumbers GetPerimeter() const override;
	CBigNumbers GetSquare() const override;
private:
	Point m_p1;
	CBigNumbers m_radius;
};
