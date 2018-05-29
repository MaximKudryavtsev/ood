#pragma once
class CVisitorPrinter : public IShapeVisitor
{
public:
	CVisitorPrinter();
	void Visit(const CCircle & circle) override;
	void Visit(const CRectangle & rectangle) override;
	void Visit(const CTriangle & triangle) override;
	void Print(std::ofstream & out, const CShape & shape);
	~CVisitorPrinter();
private:
	std::ostringstream m_strm;
	std::ofstream m_output;
};

