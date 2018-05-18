#include "stdafx.h"
#include "CBigNumbers.h"

CBigNumbers::CBigNumbers()
{
}

CBigNumbers::CBigNumbers(std::vector<int> number)
{
	Digits = number;
	std::reverse(number.begin(), number.end());
}

CBigNumbers::CBigNumbers(std::vector<int> number, bool isPositive = true)
{
	Digits = number;
	std::reverse(number.begin(), number.end());
	IsPositice = isPositive;
}

std::vector<int> CBigNumbers::StringToVector(const std::string &str)
{
	std::vector<int> number;
	std::string temp;
	for (int i = 0; i < str.length(); i++)
	{
		temp += str[i];
		number.push_back(stoi(temp));
		temp = "";
	}

	return number;
}

std::string CBigNumbers::ToString()
{
	std::vector<int> digitCopy = Digits;
	std::reverse(digitCopy.begin(), digitCopy.end());
	std::string result;
	for (int digit : digitCopy)
	{
		result += std::to_string(digit);
	}
	return result;
}

CBigNumbers* const operator+(CBigNumbers &left, CBigNumbers &right)
{
	return CCalculator::Plus(left, right);
}

CBigNumbers* const operator-(CBigNumbers &left, CBigNumbers &right)
{
	return CCalculator::Minus(left, right);
}

CBigNumbers* const operator*(CBigNumbers &left, CBigNumbers &right)
{
	return CCalculator::Multiply(left, right);
}


bool operator==(CBigNumbers &left, CBigNumbers &right)
{
	return CCalculator::AreEqual(left, right);
}

bool operator!=(CBigNumbers &left, CBigNumbers &right)
{
	return !CCalculator::AreEqual(left, right);
}

bool operator<(CBigNumbers &left, CBigNumbers &right)
{
	return !CCalculator::IsMore(left, right);
}

bool operator>(CBigNumbers &left, CBigNumbers &right)
{
	return CCalculator::IsMore(left, right);
}

CBigNumbers::~CBigNumbers()
{
}
