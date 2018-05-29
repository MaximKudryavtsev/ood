#pragma once
class TriangleCreator;

class TriangleCreatorDestroyer
{
public:
	~TriangleCreatorDestroyer();
	void initialize(TriangleCreator* m);
private:
	TriangleCreator * m_instance;
};


class TriangleCreator
{
public:
	static TriangleCreator& GetInstance();
	CTriangle * Create(Point p1, Point p2, Point p3);
protected:
	TriangleCreator() {};
	~TriangleCreator() {};
	friend class TriangleCreatorDestroyer;
private:
	static TriangleCreator * m_instance;
	static TriangleCreatorDestroyer destroyer;
};

