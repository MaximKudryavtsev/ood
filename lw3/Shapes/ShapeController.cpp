#include "stdafx.h"
#include "ShapeController.h"


ShapeController::ShapeController()
{
}


ShapeController::~ShapeController()
{
}

CShape* ShapeController::CreateShape(const std::string & type, std::vector<std::string> &parts)
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


void ShapeController::PrintShapes(CShape * shape, std::ofstream &output)
{
	output << shape->GetName() << std::endl;
	output << "Square =  " << std::fixed << std::setprecision(2) << shape->GetSquare() << std::endl;
	output << "Perimeter = " << shape->GetPerimeter() << std::endl << std::endl;
}