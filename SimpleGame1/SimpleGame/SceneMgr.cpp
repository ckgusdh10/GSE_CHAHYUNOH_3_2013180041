#include "stdafx.h"
#include "SceneMgr.h"

SceneMgr::SceneMgr()
{
	m_Renderer = new Renderer(500, 500);

	for (int i = 0; i < 50; ++i)
	{
		m_objects[i] = new Object;
		m_objects[i]->setPosX((rand() % 500) - 250);
		m_objects[i]->setPosY((rand() % 500) - 250);
		m_objects[i]->setPosZ(0);
		m_objects[i]->setSize(20);
		m_objects[i]->setColorR(1.0f);
		m_objects[i]->setColorG(1.0f);
		m_objects[i]->setColorB(1.0f);
		m_objects[i]->setColorA(1.0f);
		if (rand() % 2 == 0)
			m_objects[i]->setDirX(1);
		else
			m_objects[i]->setDirX(-1);
		if (rand() % 2 == 0)
			m_objects[i]->setDirY(1);
		else
			m_objects[i]->setDirY(-1);
	}
}

SceneMgr::~SceneMgr()
{
}

void SceneMgr::DrawAll()
{

	for(int i = 0;i<50;++i)
	{ 
		m_Renderer->DrawSolidRect(m_objects[i]->getPosX(), m_objects[i]->getPosY(), m_objects[i]->getPosZ(), m_objects[i]->getPosSize(),
			m_objects[i]->getPosR(), m_objects[i]->getPosG(), m_objects[i]->getPosB(), m_objects[i]->getPosA());
	}
}


void SceneMgr::Update()
{
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
		m_objects[i]->Update();
	}
}

void SceneMgr::Collision()
{
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
		for (int j = 0; j < MAX_OBJECTS_COUNT; ++j)
		{
			if (i == j)
				continue;

			if (abs(m_objects[j]->getPosX() - m_objects[i]->getPosX()) <= 20 && abs(m_objects[j]->getPosY() - m_objects[i]->getPosY()) <= 20)
			{ 
				m_objects[i]->setColorG(0.0f);
				m_objects[i]->setColorB(0.0f);
				m_objects[j]->setColorG(0.0f);
				m_objects[j]->setColorB(0.0f);
				break;
			}
			else
			{
				m_objects[i]->setColorG(1.0f);
				m_objects[i]->setColorB(1.0f);
				/*m_objects[j]->setColorG(1.0f);
				m_objects[j]->setColorB(1.0f);*/
			}

		}
	}
	
}
