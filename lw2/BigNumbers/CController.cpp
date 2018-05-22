#include "stdafx.h"
#include "CController.h"


CController::CController()
{
}

CBigNumbers CController::Calculate(CBigNumbers left, CBigNumbers right, char sign)
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

void CController::PrintToFile(CBigNumbers left, CBigNumbers right, CBigNumbers res, char sign, std::ofstream &output)
{
	if (sign == '/' && right.ToString() == "0")
	{
		output << left.ToString() << " " << sign << " " << right.ToString() << " = " << "can not be divided by zero" << std::endl;
	}
	else
	{
		output << left.ToString() << " " << sign << " " << right.ToString() << " = " << res.ToString() << std::endl;
	}
		
}

CController::~CController()
{
}
