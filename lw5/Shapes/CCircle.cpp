#include "stdafx.h"
#include "CCircle.h"

CCircle::CCircle(Point p1, std::string radius) : CShape("CIRCLE")
{
	m_p1 = p1;
	m_radius = CBigNumbers(radius);
}

CBigNumbers CCircle::GetPerimeter() const
{
	return (2 * CBigNumbers(M_PI * 100) * m_radius) / 100;
}

CBigNumbers CCircle::GetSquare() const
{
	return (CBigNumbers(M_PI * 100) * m_radius * m_radius) / 100;
}

void CCircle::Accept(IShapeVisitor & v) const
{
	v.Visit(*this);
}
