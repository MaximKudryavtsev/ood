#pragma once
class CBigNumbers final
{
public:
	CBigNumbers();
	CBigNumbers(std::string &number);
	CBigNumbers(int number);
	void Normalize();
	int GetSize() const;
	std::string ToString();
	const CBigNumbers& operator=(const CBigNumbers &number);

	friend const CBigNumbers sqrt(const CBigNumbers &number);
	friend const CBigNumbers operator+(const CBigNumbers &left, const CBigNumbers &right);
	friend const CBigNumbers operator-(const CBigNumbers &left, const CBigNumbers &right);
	friend const CBigNumbers operator*(const CBigNumbers &left, const CBigNumbers &right);
	friend const CBigNumbers operator/(const CBigNumbers &left, const CBigNumbers &right);

	friend const bool operator>(const CBigNumbers &left, const CBigNumbers &right);
	friend const bool operator>=(const CBigNumbers &left, const CBigNumbers &right);
	friend const bool operator<=(const CBigNumbers & lValue, const CBigNumbers & rValue);
	friend const bool operator==(const CBigNumbers &left, const CBigNumbers &right);
	~CBigNumbers();
private:
	std::vector<int> m_number;
};



