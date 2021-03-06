// BigNumbers.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main(int argc, char *argv[])
{
	std::ifstream input(argv[1]);
	std::ofstream output(argv[2]);

	std::string str;
	
	while (getline(input, str))
	{
		std::vector<std::string> parts;
		boost::split(parts, str, boost::is_any_of(" "), boost::token_compress_on);
		
		CBigNumbers left(parts[0]);
		
		std::string sign = parts[1];
		CBigNumbers right(parts[2]);

		CBigNumbers res = CController::Calculate(left, right, *sign.c_str());
		CController::PrintToFile(left, right, res, *sign.c_str(), output);

		
	}
}

