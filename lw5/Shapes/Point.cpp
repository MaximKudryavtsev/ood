#include "stdafx.h"
#include "Point.h"

Point::Point(std::string &x, std::string &y)
{
	m_x = CBigNumbers(x);
	m_y = CBigNumbers(y);
}

Point::Point()
{
	m_x = 0;
	m_y = 0;
}

CBigNumbers Point::GetX() const
{
	return m_x;
}

CBigNumbers Point::GetY() const
{
	return m_y;
}

