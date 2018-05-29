#pragma once
#include "CShape.h"
#include "Point.h"
#include "IShapeVisitor.h"

class CRectangle final :
	public CShape
{
public:
	CRectangle(Point p1, Point p2);

	CBigNumbers GetPerimeter() const override;
	CBigNumbers GetSquare() const override;
	void Accept(IShapeVisitor & v) const;
private:
	Point m_p1;
	Point m_p2;
};
