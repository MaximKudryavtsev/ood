#pragma once
class Point
{
public:
	Point(std::string &x, std::string &y);
	Point();

	CBigNumbers GetX() const;
	CBigNumbers GetY() const;

private:
	CBigNumbers m_x;
	CBigNumbers m_y;
};