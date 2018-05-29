#include "stdafx.h"
#include "CVisitorPrinter.h"


CVisitorPrinter::CVisitorPrinter()
{
}

void CVisitorPrinter::Visit(const CCircle & shape)
{
	m_strm << shape.GetName() << std::endl;
	m_strm << "Square =  " << std::fixed << std::setprecision(2) << shape.GetSquare().ToString() << std::endl;
	m_strm << "Perimeter = " << shape.GetPerimeter().ToString() << std::endl << std::endl;
}

void CVisitorPrinter::Visit(const CRectangle & shape)
{
	m_strm << shape.GetName() << std::endl;
	m_strm << "Square =  " << std::fixed << std::setprecision(2) << shape.GetSquare().ToString() << std::endl;
	m_strm << "Perimeter = " << shape.GetPerimeter().ToString() << std::endl << std::endl;
}

void CVisitorPrinter::Visit(const CTriangle & shape)
{
	m_strm << shape.GetName() << std::endl;
	m_strm << "Square =  " << std::fixed << std::setprecision(2) << shape.GetSquare().ToString() << std::endl;
	m_strm << "Perimeter = " << shape.GetPerimeter().ToString() << std::endl << std::endl;
}

void CVisitorPrinter::Print(std::ofstream & out, const CShape & shape)
{
	shape.Accept(*this);
	out << m_strm.str();
}

CVisitorPrinter::~CVisitorPrinter()
{
}
