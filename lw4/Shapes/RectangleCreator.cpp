#include "stdafx.h"
#include "RectangleCreator.h"

RectangleCreator * RectangleCreator::m_instance = 0;
RectangleCreatorDestroyer RectangleCreator::destroyer;

RectangleCreatorDestroyer::~RectangleCreatorDestroyer()
{
	delete m_instance;
}

void RectangleCreatorDestroyer::initialize(RectangleCreator* m)
{
	m_instance = m;
}

CRectangle * RectangleCreator::Create(Point p1, Point p2)
{
	return new CRectangle(p1, p2);
}

RectangleCreator& RectangleCreator::GetInstance()
{
	if (!m_instance)
	{
		m_instance = new RectangleCreator();
		destroyer.initialize(m_instance);
	}
	return *m_instance;
}
