#include "stdafx.h"
#include "SceneMgr.h"

SceneMgr::SceneMgr()
{
	m_Renderer = new Renderer(500, 500);

	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
		m_objects[i] = NULL;
	}
	CreateRect(0, 0, 1);
	/*for (int i = 0; i < 50; ++i)
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
	}*/
}

SceneMgr::~SceneMgr()
{
	
}

void SceneMgr::DrawAll()
{

	for(int i = 0;i<MAX_OBJECTS_COUNT;++i)
	{ 
		if (m_objects[i] != NULL)
		{
			m_Renderer->DrawSolidRect(m_objects[i]->getPosX(), m_objects[i]->getPosY(), m_objects[i]->getPosZ(), m_objects[i]->getPosSize(),
				m_objects[i]->getPosR(), m_objects[i]->getPosG(), m_objects[i]->getPosB(), m_objects[i]->getPosA());
		}

	}
}


void SceneMgr::Update(float E_Time)
{
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
		if (m_objects[i] != NULL)
		{
			if (CheckLifeTime(m_objects[i]) == false || CheckLife(m_objects[i]) == false)
			{
				delete m_objects[i];	
				m_objects[i] = NULL;
				--CurrentRectCount;
			}
			else
				m_objects[i]->Update(E_Time);

		}
	}
	
	
}

void SceneMgr::Collision()
{
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
		if (m_objects[i] != NULL)
		{
			for (int j = 0; j < MAX_OBJECTS_COUNT; ++j)
			{
				if (i == j)
					continue;
				if (m_objects[j] != NULL)
				{
					if (m_objects[j]->getPosX() - m_objects[j]->getPosSize() / 2 <= m_objects[i]->getPosX() + m_objects[i]->getPosSize() / 2
						&& m_objects[j]->getPosY() - m_objects[j]->getPosSize() / 2 <= m_objects[i]->getPosY() + m_objects[i]->getPosSize() / 2
						&& m_objects[j]->getPosX() + m_objects[j]->getPosSize() / 2 >= m_objects[i]->getPosX() - m_objects[i]->getPosSize() / 2
						&& m_objects[j]->getPosY() + m_objects[j]->getPosSize() / 2 >= m_objects[i]->getPosY() - m_objects[i]->getPosSize() / 2)
					{
						if (m_objects[i]->getType() == 1 && m_objects[j]->getType() == 2)
						{

							/*m_objects[i]->setColorG(0.0f);
							m_objects[i]->setColorB(0.0f);*/
							m_objects[i]->setLife(m_objects[i]->getLife() - m_objects[j]->getLife());
							delete m_objects[j];
							m_objects[j] = NULL;
						}
						else if (m_objects[i]->getType() == 2 && m_objects[j]->getType() == 1)
						{

							/*m_objects[j]->setColorG(0.0f);
							m_objects[j]->setColorB(0.0f);*/
							m_objects[j]->setLife(m_objects[j]->getLife() - m_objects[i]->getLife());
							delete m_objects[i];
							m_objects[i] = NULL;
						}
						/*m_objects[i]->setColorG(0.0f);
						m_objects[i]->setColorB(0.0f);
						m_objects[j]->setColorG(0.0f);
						m_objects[j]->setColorB(0.0f);*/
						break;
					}
					
					else
					{
						if (m_objects[i]->getType() == 1)
						{
							m_objects[i]->setColorG(1.0f);
							m_objects[i]->setColorR(1.0f);
							m_objects[i]->setColorB(0.0f);
							break;
						}
						m_objects[i]->setColorG(1.0f);
						m_objects[i]->setColorB(1.0f);
						/*m_objects[j]->setColorG(1.0f);
						m_objects[j]->setColorB(1.0f);*/
					}
				}

			}
		}
	}
	
}

void SceneMgr::CreateRect(float x, float y, int type)
{
	if (CurrentRectCount < MAX_OBJECTS_COUNT)
	{
		for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
		{
			if (m_objects[i] == NULL)
			{
				if (type == 1)
				{
					cout << "持失 " << endl;
					m_objects[i] = new Object;
					m_objects[i]->setPosX(x);
					m_objects[i]->setPosY(y);
					m_objects[i]->setPosZ(0);
					m_objects[i]->setSize(50);
					m_objects[i]->setColorR(1.0f);
					m_objects[i]->setColorG(1.0f);
					m_objects[i]->setColorB(0.0f);
					m_objects[i]->setColorA(1.0f);
					m_objects[i]->setType(1);
					m_objects[i]->setDirX(0);
					m_objects[i]->setLife(500);
					m_objects[i]->setDirX(0);
					m_objects[i]->setSpeed(0);
					
					m_objects[i]->setDirY(0);
					
					m_objects[i]->setDirY(0);
					++CurrentRectCount;

					break;
				}
				else if (type == 2)
				{
					cout << "持失 " << endl;
					m_objects[i] = new Object;
					m_objects[i]->setPosX(x);
					m_objects[i]->setPosY(y);
					m_objects[i]->setPosZ(0);
					m_objects[i]->setSize(10);
					m_objects[i]->setColorR(1.0f);
					m_objects[i]->setColorG(1.0f);
					m_objects[i]->setColorB(1.0f);
					m_objects[i]->setColorA(1.0f);
					m_objects[i]->setLife(10);
					m_objects[i]->setType(2);
					m_objects[i]->setSpeed(300);
					if (rand() % 2 == 0)
						m_objects[i]->setDirX(1);
					else
						m_objects[i]->setDirX(-1);
					if (rand() % 2 == 0)
						m_objects[i]->setDirY(1);
					else
						m_objects[i]->setDirY(-1);
					++CurrentRectCount;
					break;
				}
				else if (type == 3)
				{
					cout << "持失 " << endl;
					m_objects[i] = new Object;
					m_objects[i]->setPosX(x);
					m_objects[i]->setPosY(y);
					m_objects[i]->setPosZ(0);
					m_objects[i]->setSize(2);
					m_objects[i]->setColorR(1.0f);
					m_objects[i]->setColorG(0.0f);
					m_objects[i]->setColorB(0.0f);
					m_objects[i]->setColorA(1.0f);
					m_objects[i]->setLife(20);
					m_objects[i]->setType(3);
					m_objects[i]->setSpeed(600);
					if (rand() % 2 == 0)
						m_objects[i]->setDirX(1);
					else
						m_objects[i]->setDirX(-1);
					if (rand() % 2 == 0)
						m_objects[i]->setDirY(1);
					else
						m_objects[i]->setDirY(-1);
					++CurrentRectCount;
					break;
				}
				else if (type == 4)
				{
					cout << "持失 " << endl;
					m_objects[i] = new Object;
					m_objects[i]->setPosX(x);
					m_objects[i]->setPosY(y);
					m_objects[i]->setPosZ(0);
					m_objects[i]->setSize(2);
					m_objects[i]->setColorR(0.0f);
					m_objects[i]->setColorG(1.0f);
					m_objects[i]->setColorB(0.0f);
					m_objects[i]->setColorA(1.0f);
					m_objects[i]->setLife(10);
					m_objects[i]->setType(4);
					m_objects[i]->setSpeed(100);
					if (rand() % 2 == 0)
						m_objects[i]->setDirX(1);
					else
						m_objects[i]->setDirX(-1);
					if (rand() % 2 == 0)
						m_objects[i]->setDirY(1);
					else
						m_objects[i]->setDirY(-1);
					++CurrentRectCount;
					break;
				}
			}
		}
		

		
	}
}

bool SceneMgr::CheckLifeTime(Object* o)
{
	if (o->getLifeTime() <= 0)
		return false;
	return true;
}

bool SceneMgr::CheckLife(Object * o)
{
	if (o->getLife() <= 0)
		return false;
	return true;
}

void SceneMgr::CreateBullet(float E_Time)
{
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
		if (m_objects[i]->getType() == 1)
		{
			CreateRect(m_objects[i]->getPosX(), m_objects[i]->getPosY(), 3);
		}
	}
}
