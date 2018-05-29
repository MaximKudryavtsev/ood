#pragma once
class CircleCreator;

class CircleCreatorDestroyer
{
public:
	~CircleCreatorDestroyer();
	void initialize(CircleCreator* m);
private:
	CircleCreator* m_instance;
};



class CircleCreator
{
public:
	static CircleCreator& GetInstance();
	CCircle * Create(Point point, std::string radius);
protected:
	CircleCreator() {};
	~CircleCreator() {};
	friend class CircleCreatorDestroyer;
private:
	static CircleCreator * m_instance;
	static CircleCreatorDestroyer destroyer;
};

