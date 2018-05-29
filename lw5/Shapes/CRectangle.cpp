#include "stdafx.h"
#include "CRectangle.h"

CRectangle::CRectangle(Point p1, Point p2) : CShape("RECTANGLE")
{
	m_p1 = p1;
	m_p2 = p2;
}

CBigNumbers CRectangle::GetPerimeter() const
{
	return CBigNumbers(2) * ((m_p1.GetX() - m_p2.GetX()) + (m_p1.GetY() - m_p2.GetY()));
}

CBigNumbers CRectangle::GetSquare() const
{
	return (m_p1.GetX() - m_p2.GetX()) * (m_p1.GetY() - m_p2.GetY());
}

void CRectangle::Accept(IShapeVisitor & v) const
{
	v.Visit(*this);
}