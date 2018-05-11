#pragma once
#include <string>

class CShape
{
public:
	CShape(const std::string & type);

	virtual std::string GetName() const;
	virtual double GetPerimeter() const = 0;
	virtual double GetSquare() const = 0;

	virtual ~CShape();
	static CShape* CreateShape(const std::string & type, std::vector<std::string> & parts);
private:
	std::string m_type;
	double m_perimeter;
	double m_square;
	
};