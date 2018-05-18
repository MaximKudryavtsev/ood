#include "stdafx.h"
#include "CController.h"


CController::CController()
{
}

void CController::PrintToFile(CBigNumbers left, CBigNumbers right, CBigNumbers* res, char sign, std::ofstream &output)
{
	std::reverse(left.Digits.begin(), left.Digits.end());
	std::reverse(right.Digits.begin(), right.Digits.end());
	output << left.ToString() << " " << sign << " " << right.ToString() << " = " << res->ToString() << std::endl;
}

CController::~CController()
{
}
