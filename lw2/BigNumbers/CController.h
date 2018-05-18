#pragma once
class CController
{
public:
	CController();
	static void PrintToFile(CBigNumbers left, CBigNumbers right, CBigNumbers* res, char sign, std::ofstream &output);
	~CController();
};

