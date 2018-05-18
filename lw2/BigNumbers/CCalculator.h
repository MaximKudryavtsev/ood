#pragma once
class CCalculator
{
public:
	CCalculator();
	static CBigNumbers* Plus(CBigNumbers &left, CBigNumbers &right);
	static CBigNumbers* Minus(CBigNumbers &left, CBigNumbers &right);
	static CBigNumbers* Multiply(CBigNumbers &left, CBigNumbers &right);
	CBigNumbers Division(CBigNumbers &left, CBigNumbers &right);
	static bool AreEqual(CBigNumbers &left, CBigNumbers &right);
	static bool IsMore(CBigNumbers &left, CBigNumbers &right);
	static CBigNumbers* Calculate(CBigNumbers left, CBigNumbers right, char sign);
	~CCalculator();
};

