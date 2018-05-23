#pragma once
#include "CShape.h"
#include "Point.h"

class CTriangle final :
	public CShape
{
public:
	CTriangle(Point p1, Point p2, Point p3);

	CBigNumbers GetPerimeter() const override;
	CBigNumbers GetSquare() const override;

private:
	Point m_p1;
	Point m_p2;
	Point m_p3;
};