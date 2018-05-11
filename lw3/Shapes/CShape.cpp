#include "stdafx.h"
#include "CShape.h"

enum ShapesTypes
{
	CIRCLE,
	RECTANGLE,
	TRIANGLE
};

CShape::CShape(const std::string & type)
{
	m_type = type;
}

CShape::~CShape()
{
}

CShape* CShape::CreateShape(const std::string & type, std::vector<std::string> &parts)
{
	if (type == "CIRCLE")
	{
		Point point(std::stoi(parts[0]), std::stoi(parts[1]));
		int radius = std::stoi(parts[2]);
		return CircleCreator::GetInstance().Create(point, radius);
	}
	if (type == "RECTANGLE")
	{
		Point point1(std::stoi(parts[0]), std::stoi(parts[1]));
		Point point2(std::stoi(parts[2]), std::stoi(parts[3]));
		return RectangleCreator::GetInstance().Create(point1, point2);
	}
	if (type == "TRIANGLE")
	{
		Point point1(std::stoi(parts[0]), std::stoi(parts[1]));
		Point point2(std::stoi(parts[2]), std::stoi(parts[3]));
		Point point3(std::stoi(parts[4]), std::stoi(parts[5]));
		return TriangleCreator::GetInstance().Create(point1, point2, point3);
	}
}

std::string CShape::GetName() const
{
	return "Shape: " + m_type;
}

