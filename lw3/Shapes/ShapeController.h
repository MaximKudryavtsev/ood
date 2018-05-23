#pragma once
class ShapeController
{
public:
	ShapeController();
	~ShapeController();
	static CShape* CreateShape(const std::string & type, std::vector<std::string> & parts);
	static void PrintShapes(CShape * shape, std::ofstream &output);
private:
	std::string m_type;
};

