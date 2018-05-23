#pragma once
class RectangleCreator;

class RectangleCreatorDestroyer
{
public:
	~RectangleCreatorDestroyer();
	void initialize(RectangleCreator* m);
private:
	RectangleCreator * m_instance;
};



class RectangleCreator
{
public:
	static RectangleCreator& GetInstance();
	CRectangle * Create(Point p1, Point p2);
protected:
	RectangleCreator() {};
	~RectangleCreator() {};
	friend class RectangleCreatorDestroyer;
private:
	static RectangleCreator * m_instance;
	static RectangleCreatorDestroyer destroyer;
};

