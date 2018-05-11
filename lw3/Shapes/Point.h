#pragma once
class Point
{
public:
	Point(int x, int y);
	Point();

	int GetX() const;
	int GetY() const;

private:
	int m_x;
	int m_y;
};