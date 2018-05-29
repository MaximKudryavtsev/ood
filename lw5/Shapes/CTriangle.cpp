#include "stdafx.h"
#include "CTriangle.h"

CTriangle::CTriangle(Point p1, Point p2, Point p3) : CShape("TRIANGLE")
{
	m_p1 = p1;
	m_p2 = p2;
	m_p3 = p3;
}


CBigNumbers CTriangle::GetPerimeter() const
{
	CBigNumbers a = (((m_p2.GetX() - m_p1.GetX()) * (m_p2.GetX() - m_p1.GetX())) + ((m_p2.GetY() - m_p1.GetY()) * (m_p2.GetY() - m_p1.GetY())));
	CBigNumbers b = (((m_p3.GetX() - m_p2.GetX()) * (m_p3.GetX() - m_p2.GetX())) + ((m_p3.GetY() - m_p2.GetY()) * (m_p3.GetY() - m_p2.GetY())));
	CBigNumbers c = (((m_p3.GetX() - m_p1.GetX()) * (m_p3.GetX() - m_p1.GetX())) + ((m_p3.GetY() - m_p1.GetY()) * (m_p3.GetY() - m_p1.GetY())));
	return sqrt(a);//sqrt(b) + sqrt(c);
}

CBigNumbers CTriangle::GetSquare() const
{
	return (((m_p1.GetX() - m_p3.GetX()) * (m_p2.GetY() - m_p3.GetY())) - ((m_p2.GetX() - m_p3.GetX()) * (m_p1.GetY() - m_p3.GetY()))) / 2;
}

void CTriangle::Accept(IShapeVisitor & v) const
{
	v.Visit(*this);
}
