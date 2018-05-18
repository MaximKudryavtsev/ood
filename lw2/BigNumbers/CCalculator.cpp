#include "stdafx.h"
#include "CCalculator.h"


CCalculator::CCalculator()
{
}

CBigNumbers* CCalculator::Plus(CBigNumbers &left, CBigNumbers &right)
{
	std::vector<int> result;
	int carry = 0;
	int maxNumberSize = std::max(left.Digits.size(), right.Digits.size());
	
	for (int i = 0; i < maxNumberSize; i++)
	{
		int tempLeft = (left.Digits.size() > i) ? left.Digits[i] : 0;
		int tempRight = (right.Digits.size() > i) ? right.Digits[i] : 0;
		int sum = tempLeft + tempRight + carry;
		carry = 0;

		if (sum >= 10)
		{
			sum -= 10;
			carry = 1; 
		}

		result.push_back(sum);

		if (i == maxNumberSize - 1)
		{
			result.push_back(carry);
		}
	}

	while (result.size() > 1 && result[result.size() - 1] == 0)
	{
		result.erase(result.end() - 1);
	}

	return new CBigNumbers(result);
}

CBigNumbers* CCalculator::Minus(CBigNumbers &left, CBigNumbers &right)
{
	if (left < right)
	{
		throw std::invalid_argument("left value can't be more than right value");
	}

	std::vector<int> result;
	int carry = 0;
	bool isPositive = true;
	for (int i = 0; i < left.Digits.size(); i++)
	{
		int tempLeft = (left.Digits.size() > i) ? left.Digits[i] : 0;
		int tempRight = (right.Digits.size() > i) ? right.Digits[i] : 0;
		int difference = tempLeft - tempRight - carry;

		carry = difference < 0 ? 1 : 0;
		difference += carry == 1 && i != left.Digits.size() - 1 ? 10 : 0;

		result.push_back(difference);

		if (i == left.Digits.size() && carry == 1)
		{
			isPositive = false;
		}
	}

	while (left.Digits.size() > 1 && result[result.size() - 1] == 0)
	{
		result.erase(result.end() - 1);
	}

	return new CBigNumbers(result, isPositive);
}

CBigNumbers* CCalculator::Multiply(CBigNumbers &left, CBigNumbers &right)
{
	if (left.Digits.size() == 1 && left.Digits[0] == 0 || right.Digits.size() == 1 && right.Digits[0] == 0)
	{
		std::vector<int> zeroVector = { 0 };
		return new CBigNumbers(zeroVector);
	}

	std::vector<CBigNumbers> summands;

	for (int i = 0; i < left.Digits.size(); i++)
	{
		int carry = 0;
		for (int j = 0; j < right.Digits.size(); ++j)
		{
			int multiplied = left.Digits[i] * right.Digits[j] + carry;
			carry = multiplied / 10;
			multiplied %= 10;
			summands[i].Digits.push_back(multiplied);

			while (carry != 0 && right.Digits.size() - 1 == j)
			{
				int additional = carry;
				if (carry > 10)
				{
					carry /= 10;
					additional = carry % 10;
				}
				else
				{
					carry  = 0;
				}
				summands[i].Digits.push_back(additional);
			}
		}
	}

	CBigNumbers result;
	

}

bool CCalculator::AreEqual(CBigNumbers &left, CBigNumbers &right)
{
	if (left.Digits.size() == 0 && right.Digits.size() == 0)
	{
		return true;
	}

	if (left.Digits.size() == 0 || right.Digits.size() == 0)
	{
		return false;
	}
	
	return left.Digits == right.Digits;
}

bool CCalculator::IsMore(CBigNumbers &left, CBigNumbers &right)
{
	if (AreEqual(left, right))
	{
		return false;
	}

	if (left.Digits.size() == right.Digits.size())
	{
		for (int i = left.Digits.size() - 1; i >= 0; --i)
		{
			if (left.Digits[i] == right.Digits[i])
			{
				continue;
			}
			return left.Digits[i] > right.Digits[i];
		}
	}

	if (left.Digits.size() < right.Digits.size())
	{
		return false;
	}

	return true;
}

CBigNumbers* CCalculator::Calculate(CBigNumbers left, CBigNumbers right, char sign)
{
	switch (sign)
	{
	case '+':
		return left + right;
	case '-':
		return left - right;
	case '*':
		return left * right;
	case '/':
		return left / right;
	}
}

CCalculator::~CCalculator()
{
}
