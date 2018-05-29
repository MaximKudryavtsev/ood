#include "stdafx.h"
#include "CircleCreator.h"

CircleCreator * CircleCreator::m_instance = 0;
CircleCreatorDestroyer CircleCreator::destroyer;

CircleCreatorDestroyer::~CircleCreatorDestroyer()
{
	delete m_instance;
}

void CircleCreatorDestroyer::initialize(CircleCreator* m)
{
	m_instance = m;
}

CCircle * CircleCreator::Create(Point point, std::string radius)
{
	return new CCircle(point, radius);
}

CircleCreator& CircleCreator::GetInstance()
{
	if (!m_instance)
	{
		m_instance = new CircleCreator();
		destroyer.initialize(m_instance);
	}
	return *m_instance;
}