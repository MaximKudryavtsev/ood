#include "stdafx.h"
#include "TriangleCreator.h"

TriangleCreator * TriangleCreator::m_instance = 0;
TriangleCreatorDestroyer TriangleCreator::destroyer;

TriangleCreatorDestroyer::~TriangleCreatorDestroyer()
{
	delete m_instance;
}

void TriangleCreatorDestroyer::initialize(TriangleCreator* m)
{
	m_instance = m;
}

CTriangle * TriangleCreator::Create(Point p1, Point p2, Point p3)
{
	return  new CTriangle(p1, p2, p3);
}

TriangleCreator& TriangleCreator::GetInstance()
{
	if (!m_instance)
	{
		m_instance = new TriangleCreator();
		destroyer.initialize(m_instance);
	}
	return *m_instance;
}
