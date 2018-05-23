#pragma once
#include <string>
#include "CBigNumbers.h"

class CShape
{
public:
	CShape(const std::string & type);

	virtual std::string GetName() const;
	virtual CBigNumbers GetPerimeter() const = 0;
	virtual CBigNumbers GetSquare() const = 0;

	virtual ~CShape();
	
private:
	std::string m_type;
	
};