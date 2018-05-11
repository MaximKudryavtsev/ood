// Shapes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h";

std::string const CIRCLE = "CIRCLE";
std::string const TRIANGLE = "TRIANGLE";
std::string const RECTANGLE = "RECTANGLE";


void PrintShapes(CShape * shape, std::ofstream &output)
{
	output << shape->GetName() << std::endl;
	output << "Square =  " << std::fixed << std::setprecision(2) << shape->GetSquare() << std::endl;
	output << "Perimeter = " << shape->GetPerimeter() << std::endl << std::endl;
}

int main(int argc, char *argv[])
{
	
	std::ifstream file(argv[1]);
	std::ofstream output(argv[2]);
	std::string str;
	
	while (getline(file, str))
	{
		std::vector<std::string> parts;
		int foundIndex = str.find_first_of(':');
		std::string shapeName = str.substr(0, foundIndex);
		str = str.substr(foundIndex + 1);
		boost::split(parts, str, boost::is_any_of(";"), boost::token_compress_on);
		CShape * shape = CShape::CreateShape(shapeName, parts);
		if (shape == nullptr)
		{
			continue;
		}
		PrintShapes(shape, output);
	}

    return 0;
}

