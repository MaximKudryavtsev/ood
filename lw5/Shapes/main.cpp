// Shapes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h";

std::string const CIRCLE = "CIRCLE";
std::string const TRIANGLE = "TRIANGLE";
std::string const RECTANGLE = "RECTANGLE";

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
		CShape * shape = ShapeController::CreateShape(shapeName, parts);
		if (shape == nullptr)
		{
			continue;
		}
		CVisitorPrinter visitor;
		visitor.Print(output, *shape);
		//ShapeController::PrintShapes(shape, output);
	}

    return 0;
}

