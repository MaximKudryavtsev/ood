#pragma once
class CController
{
public:
	CController();
	static CBigNumbers Calculate(CBigNumbers left, CBigNumbers right, char sign);
	static void PrintToFile(CBigNumbers left, CBigNumbers right, CBigNumbers res, char sign, std::ofstream &output);
	~CController();
};

