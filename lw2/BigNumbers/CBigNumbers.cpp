#include "stdafx.h"
#include "CBigNumbers.h"

CBigNumbers::CBigNumbers()
{
}

CBigNumbers::CBigNumbers(std::string &number)
{
	std::string temp;
	for (int i = number.length() - 1; i >= 0; --i)
	{
		int num = atoi(number.substr(i, 1).c_str());
		m_number.push_back(num);
	}
	Normalize();
}

CBigNumbers::CBigNumbers(int number)
{
	while (number != 0)
	{
		m_number.push_back(number % 10);
		number /= 10;
	}
}

void CBigNumbers::Normalize()
{
	while (m_number.size() > 1 && m_number.back() == 0)
		m_number.pop_back();
}

int CBigNumbers::GetSize() const
{
	return m_number.size();
}

std::string CBigNumbers::ToString()
{
	std::vector<int> digitCopy = m_number;
	std::reverse(digitCopy.begin(), digitCopy.end());
	std::string result;
	for (int digit : digitCopy)
	{
		result += std::to_string(digit);
	}
	return result;
}

const CBigNumbers & CBigNumbers::operator=(const CBigNumbers & number)
{
	if (&number != this)
	{
		m_number = number.m_number;
	}

	return *this;
}

const CBigNumbers operator+(const CBigNumbers &left, const CBigNumbers &right)
{
	CBigNumbers result = left;
	CBigNumbers operand = right;

	int carry = 0;
	for (int i = 0; i < result.GetSize() || carry; ++i)
	{
		if (operand.GetSize() < result.GetSize() && i == operand.GetSize())
		{
			operand.m_number.push_back(0);
		}
		if (i == result.GetSize())
		{
			result.m_number.push_back(0);
		}
		result.m_number[i] += carry + (i < operand.GetSize() ? operand.m_number[i] : 0);

		carry = result.m_number[i] >= 10;
		if (carry)
		{
			result.m_number[i] -= 10;
		}
	}
	result.Normalize();
	return result;
}

const CBigNumbers operator-(const CBigNumbers &left, const CBigNumbers &right)
{
	CBigNumbers result = left;
	CBigNumbers operand = right;
	int carry = 0;
	for (int i = 0; i < operand.GetSize() || carry != 0; ++i)
	{
		result.m_number[i] -= carry + (i < operand.GetSize() ? operand.m_number[i] : 0);
		carry = result.m_number[i] < 0;
		if (carry)
		{
			result.m_number[i] += 10;
		}
	}
	result.Normalize();
	return result;
}

const CBigNumbers operator*(const CBigNumbers &left, const CBigNumbers &right)
{
	CBigNumbers result;

	int length = left.GetSize() + right.GetSize();
	result.m_number.resize(length);

	for (int i = 0; i < right.GetSize(); ++i)
		for (int j = 0; j < left.GetSize(); ++j)
			result.m_number[i + j] += right.m_number[i] * left.m_number[j];

	for (int i = 0; i < length; i++)
	{
		if (i + 1 != length)
		{
			result.m_number[i + 1] += result.m_number[i] / 10;
		}
		else
		{
			result.m_number.push_back(result.m_number[i] / 10);
		}
		result.m_number[i] %= 10;
	}

	while (result.m_number[length] == 0)
		length--;
	result.Normalize();
	return result;
}

const CBigNumbers operator/(const CBigNumbers &left, const CBigNumbers &right)
{
	CBigNumbers dividend;
	CBigNumbers result;

	if (right.GetSize() == 1 && right.m_number[0] == 0)
	{
		throw std::invalid_argument("division by zero is not allowed");
	}

	for (int i = left.GetSize() - 1; i >= 0; --i)
	{
		if (!(dividend > right))
		{
			if (dividend.GetSize() == 1 && dividend.m_number[0] == 0)
			{
				dividend.m_number.pop_back();
			}
			std::reverse(std::begin(dividend.m_number), std::end(dividend.m_number));
			dividend.m_number.push_back(left.m_number[i]);
			std::reverse(std::begin(dividend.m_number), std::end(dividend.m_number));
		}

		if (dividend >= right)
		{
			CBigNumbers divider = right;

			int j = 1;
			if (dividend == divider)
			{
				++j;
			}
			else
			{
				while (dividend >= divider)
				{
					++j;
					divider = right * CBigNumbers(j);
				}
			}
			result.m_number.push_back(j - 1);
			dividend = dividend - right * CBigNumbers(j - 1);
		}
		else
		{
			if (result.GetSize() != 0)
			{
				result.m_number.push_back(0);
			}
		}
	}
	std::reverse(std::begin(result.m_number), std::end(result.m_number));
	result.Normalize();
	return result;
}

const bool operator>(const CBigNumbers &left, const CBigNumbers &right)
{
	if (left.GetSize() > right.GetSize())
	{
		return true;
	}
	else if (left.GetSize() == right.GetSize())
	{
		for (int i = left.GetSize() - 1; i >= 0; --i)
		{
			if (left.m_number[i] > right.m_number[i])
			{
				return true;
			}
			else if (left.m_number[i] < right.m_number[i])
			{
				return false;
			}
		}
	}

	return false;
}

const bool operator>=(const CBigNumbers &left, const CBigNumbers &right)
{
	if (left.GetSize() > right.GetSize())
	{
		return true;
	}
	else if (left.GetSize() == right.GetSize())
	{
		for (int i = left.GetSize() - 1; i >= 0; --i)
		{
			if (left.m_number[i] < right.m_number[i])
			{
				return false;
			}
			else if (left.m_number[i] > right.m_number[i]) {
				return true;
			}
		}
		return true;
	}

	return false;
}

const bool operator==(const CBigNumbers &left, const CBigNumbers &right)
{
	if (left.GetSize() == right.GetSize())
	{
		for (int i = left.GetSize() - 1; i >= 0; --i)
		{
			if (left.m_number[i] != right.m_number[i])
			{
				return false;
			}
		}
		return true;
	}

	return false;
}

CBigNumbers::~CBigNumbers()
{
}
