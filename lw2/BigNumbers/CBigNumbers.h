#pragma once
class CBigNumbers
{
public:
	CBigNumbers();
	CBigNumbers(std::vector<int> number);
	CBigNumbers(std::vector<int> number, bool isPositive);
	
	std::vector<int> Digits;
	bool IsPositice = true;
	std::string ToString();
	static std::vector<int> StringToVector(const std::string &str);
	~CBigNumbers();
private:
	std::vector<int> m_number;
};

CBigNumbers* const operator+(CBigNumbers &left, CBigNumbers &right);
CBigNumbers* const operator-(CBigNumbers &left, CBigNumbers &right);
CBigNumbers* const operator*(CBigNumbers &left, CBigNumbers &right);
CBigNumbers* const operator/(CBigNumbers &left, CBigNumbers &right);

bool operator>(CBigNumbers &left, CBigNumbers &right);
bool operator<(CBigNumbers &left, CBigNumbers &right);
bool operator==(CBigNumbers &left, CBigNumbers &right);
bool operator!=(CBigNumbers &left, CBigNumbers &right);



