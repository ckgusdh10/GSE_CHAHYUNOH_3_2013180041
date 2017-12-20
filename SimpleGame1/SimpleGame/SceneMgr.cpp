#include "stdafx.h"
#include <Windows.h>
#include "SceneMgr.h"
#include "Global.h"

SceneMgr::SceneMgr()
{
	m_Renderer = new Renderer(500, 800);
	m_texCharacter = m_Renderer->CreatePngTexture("./resourse/킹타워1.png");
	m_texCharacter2 = m_Renderer->CreatePngTexture("./resourse/킹타워.png");
	m_texBackGround = m_Renderer->CreatePngTexture("./resourse/배경1.png");
	m_texCookie = m_Renderer->CreatePngTexture("./resourse/쿠키.png");
	m_texCat = m_Renderer->CreatePngTexture("./resourse/고양이.png");
	m_texPar = m_Renderer->CreatePngTexture("./resourse/파티클5.png");

	//m_Renderer->DrawTexturedRect(0, 0, 0, 800, 1, 1, 1, 1, m_texBackGround, 0.1);
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
		m_objects[i] = NULL;
	}

	m_sound = new Sound();
	backsound = m_sound->CreateSound("./Dependencies/SoundSamples/MF-W-90.XM");
	m_sound->PlaySound1(backsound, true, 0.2f);
	
	CreateRect(10, 10, 5, 0, 1);

	CreateRect(0, -250, 1, 0, 2);
	CreateRect(150, -200, 1, 0, 2);
	CreateRect(-150, -200, 1, 0, 2);

	CreateRect(0, 250, 1, 0, 1);
	CreateRect(150, 200, 1, 0, 1);
	CreateRect(-150, 200, 1, 0, 1);
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
			if (m_objects[i]->getType() == 5)
			{
				
				m_Renderer->DrawTexturedRect(m_objects[i]->getPosX(), m_objects[i]->getPosY(), m_objects[i]->getPosZ(), m_objects[i]->getPosSize(), 1, 1, 1, 1, m_texBackGround, 0.9);
			}
			else if (m_objects[i]->getType() == 1)
			{
				if (m_objects[i]->getTeam() == 2)
				{
					m_Renderer->DrawTexturedRect(m_objects[i]->getPosX(), m_objects[i]->getPosY(), m_objects[i]->getPosZ(), m_objects[i]->getPosSize(), 1, 1, 1, 1, m_texCharacter, m_objects[i]->getLevel());
					m_Renderer->DrawSolidRectGauge(m_objects[i]->getPosX(), m_objects[i]->getPosY() + 70, m_objects[i]->getPosZ(), 100, 10, 0.0, 0.0, 1.0, 1.0, (m_objects[i]->getLife() / m_objects[i]->getmaxLife()), LEVEL_BUILDING);
				}
					
				else
				{
					m_Renderer->DrawTexturedRect(m_objects[i]->getPosX(), m_objects[i]->getPosY(), m_objects[i]->getPosZ(), m_objects[i]->getPosSize(), 1, 1, 1, 1, m_texCharacter2, m_objects[i]->getLevel());
					m_Renderer->DrawSolidRectGauge(m_objects[i]->getPosX(), m_objects[i]->getPosY() + 70, m_objects[i]->getPosZ(), 100, 10, 1.0, 0.0, 0.0, 1.0, (m_objects[i]->getLife() / m_objects[i]->getmaxLife()), LEVEL_BUILDING);
				}
					
			}
			else if (m_objects[i]->getType() == 2)
			{
				if (m_objects[i]->getTeam() == 2)
				{
					if (m_objects[i]->getCookie() >= 5)
						m_objects[i]->setCookie(0);
					m_Renderer->DrawTexturedRectSeq(m_objects[i]->getPosX(), m_objects[i]->getPosY(), m_objects[i]->getPosZ(), m_objects[i]->getPosSize(), 1, 1, 1, 1, m_texCookie, m_objects[i]->getCookie(), 0, 6, 1, m_objects[i]->getLevel());
					m_objects[i]->setCookie(m_objects[i]->getCookie() + 0.03);
					m_Renderer->DrawSolidRectGauge(m_objects[i]->getPosX(), m_objects[i]->getPosY() + 30, m_objects[i]->getPosZ(), 30, 10, 0.0, 0.0, 1.0, 1.0, (m_objects[i]->getLife() / m_objects[i]->getmaxLife()), LEVEL_CHARACTER);
					
				}

				else
				{
					
					m_Renderer->DrawTexturedRectSeq(m_objects[i]->getPosX(), m_objects[i]->getPosY(), m_objects[i]->getPosZ(), m_objects[i]->getPosSize(), 1, 1, 1, 1, m_texCat, m_objects[i]->getCat(), m_objects[i]->getCat1(), 10, 10, m_objects[i]->getLevel());
					m_objects[i]->setCat(m_objects[i]->getCat() + 0.03);
					if (m_objects[i]->getCat() > 9)
					{
						m_objects[i]->setCat(0);
						m_objects[i]->setCat1(m_objects[i]->getCat1() + 1);
					}
					if (m_objects[i]->getCat1() > 5)
					{
						m_objects[i]->setCat1(0);
					}
					//m_Renderer->DrawSolidRect(m_objects[i]->getPosX(), m_objects[i]->getPosY(), m_objects[i]->getPosZ(), m_objects[i]->getPosSize(),
					//	m_objects[i]->getPosR(), m_objects[i]->getPosG(), m_objects[i]->getPosB(), m_objects[i]->getPosA(), m_objects[i]->getLevel());
					m_Renderer->DrawSolidRectGauge(m_objects[i]->getPosX(), m_objects[i]->getPosY() + 30, m_objects[i]->getPosZ(), 30, 10, 1.0, 0.0, 0.0, 1.0, (m_objects[i]->getLife() / m_objects[i]->getmaxLife()), LEVEL_CHARACTER);
				}
			}
			else if (m_objects[i]->getType() == 3)
			{
				if (m_objects[i]->getTeam() == 1)
				{
					m_Renderer->DrawParticle(m_objects[i]->getPosX(), m_objects[i]->getPosY(), m_objects[i]->getPosZ(), m_objects[i]->getPosSize(), m_objects[i]->getPosR(), m_objects[i]->getPosG(), m_objects[i]->getPosB(),
						m_objects[i]->getPosA(), -m_objects[i]->getDirx(), -m_objects[i]->getDiry(), m_texPar, m_objects[i]->getTs(), 0.1);
				}
				else
					m_Renderer->DrawParticle(m_objects[i]->getPosX(), m_objects[i]->getPosY(), m_objects[i]->getPosZ(), m_objects[i]->getPosSize(), m_objects[i]->getPosR(), m_objects[i]->getPosG(), m_objects[i]->getPosB(),
						m_objects[i]->getPosA(), -m_objects[i]->getDirx(), -m_objects[i]->getDiry(), m_texPar, m_objects[i]->getTs(), 0.1);//LEVEL_PARTICLE);
				//ts += 0.1;
				m_objects[i]->setTs(m_objects[i]->getTs() + 0.005);
			}
			else
			{
				m_Renderer->DrawSolidRect(m_objects[i]->getPosX(), m_objects[i]->getPosY(), m_objects[i]->getPosZ(), m_objects[i]->getPosSize(),
					m_objects[i]->getPosR(), m_objects[i]->getPosG(), m_objects[i]->getPosB(), m_objects[i]->getPosA(), m_objects[i]->getLevel());
			}
		}

	}
	m_Renderer->DrawParticleClimate(0, 0, 0, 1, 1, 1, 1, 1, -0.1, -0.1, m_texPar, accel, 0.1);
	accel += 0.01;

	m_Renderer->DrawText(-20, 0, GLUT_BITMAP_HELVETICA_18, 1, 0, 0, "Game");
	
}


void SceneMgr::Update(float E_Time)
{
	cout << CurrentRectCount << endl;
	accuTime += E_Time * 0.001;
	CharacterCool += E_Time * 0.001;
	if (CharacterCool >= 7)
	{
		cout << "7초" << endl;
		//CharacterRespawn = true;
		CharacterCool = 0;
	}
	if (accuTime >= 5)
	{
		cout << "5초 " << endl;
		for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
		{
			if (m_objects[i] != NULL)
			{
				float posX = rand() % 500 - 250;
				float posY = rand() % 400;
				CreateRect(posX, posY, 2, 0, 1);
				accuTime = 0;
				break;
			}
		}
	}
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
		if (m_objects[i] != NULL && m_objects[i]->getType() != 5)
		{
			if (CheckLifeTime(m_objects[i]) == false || CheckLife(m_objects[i]) == false)
			{
				delete m_objects[i];
				m_objects[i] = NULL;
				--CurrentRectCount;
			}
			else
			{
				if (m_objects[i]->getType() == 3 || m_objects[i]->getType() == 4)
				{
					m_objects[i]->BulletArrowUpdate(E_Time);
					if (m_objects[i]->getPosX() >= 250 || m_objects[i]->getPosX() <= -250 || m_objects[i]->getPosY() >= 400 || m_objects[i]->getPosY() <= -400)
					{
						delete m_objects[i];
						m_objects[i] = NULL;
						--CurrentRectCount;
					}
				}

				else
					m_objects[i]->Update(E_Time);
			}


		

		}
		
	}
	for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
	{
		if (m_objects[i] != NULL && m_objects[i]->getType() == 1)
		{
			if (m_objects[i]->getAccumTime() >= 10)
			{

				CreateRect(m_objects[i]->getPosX(), m_objects[i]->getPosY(), 3, i, m_objects[i]->getTeam());
				cout << m_objects[i]->getAccumTime() << endl;
				m_objects[i]->setAccumTime(0);
			}
		}
		else if (m_objects[i] != NULL && m_objects[i]->getType() == 2)
		{
			if (m_objects[i]->getAccumTime() >= 3)
			{
				CreateRect(m_objects[i]->getPosX(), m_objects[i]->getPosY(), 4, i, m_objects[i]->getTeam());
				cout << m_objects[i]->getAccumTime() << endl;
				m_objects[i]->setAccumTime(0);
			}
		}
	
	}
	if (bCollision == true)
	{
		m_Renderer->SetSceneTransform(scaleX, scaleY, 1, 1);

		if (Scale == true)
		{
			scaleX += 0.2;
		}
		else
		{
			scaleX -= 0.2;
		}

		if (scaleX >= 10)
		{
			Scale = false;
		}

		if (scaleX <= 0)
		{
			Scale = true;
			bCollision = false;
		}
	}
	
	
}

void SceneMgr::Collision()
{
	for (int i = 1; i < MAX_OBJECTS_COUNT; ++i)
	{
		if (m_objects[i] != NULL )
		{
			for (int j = 1; j < MAX_OBJECTS_COUNT; ++j)
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
						if (m_objects[i]->getTeam() != m_objects[j]->getTeam())
						{
							if (m_objects[i]->getType() == 1 && m_objects[j]->getType() == 2)
							{
								bCollision = true;
								m_objects[i]->setColorR(1.0f);
								m_objects[i]->setColorG(0.0f);
								m_objects[i]->setColorB(0.0f);

								m_objects[i]->setLife(m_objects[i]->getLife() - m_objects[j]->getLife());
								delete m_objects[j];
								m_objects[j] = NULL;
								--CurrentRectCount;
							}
							else if (m_objects[i]->getType() == 2 && m_objects[j]->getType() == 1)
							{
								
								m_objects[j]->setColorR(1.0f);
								m_objects[j]->setColorG(0.0f);
								m_objects[j]->setColorB(0.0f);
								m_objects[j]->setLife(m_objects[j]->getLife() - m_objects[i]->getLife());
								delete m_objects[i];
								m_objects[i] = NULL;
								--CurrentRectCount;

							}
							else if (m_objects[i]->getType() == 2 && m_objects[j]->getType() == 3)
							{
								m_objects[i]->setLife(m_objects[i]->getLife() - m_objects[j]->getLife());
								delete m_objects[j];
								m_objects[j] = NULL;
								--CurrentRectCount;
							}
							else if (m_objects[i]->getType() == 3 && m_objects[j]->getType() == 2)
							{
								m_objects[j]->setLife(m_objects[j]->getLife() - m_objects[i]->getLife());
								delete m_objects[i];
								m_objects[i] = NULL;
								--CurrentRectCount;
							}

							else if (m_objects[i]->getType() == 1 && m_objects[j]->getType() == 4)
							{
								m_objects[i]->setColorR(1.0f);
								m_objects[i]->setColorG(0.0f);
								m_objects[i]->setColorB(0.0f);
								m_objects[i]->setLife(m_objects[i]->getLife() - m_objects[j]->getLife());
								delete m_objects[j];
								m_objects[j] = NULL;
								--CurrentRectCount;
							}
							else if (m_objects[i]->getType() == 2 && m_objects[j]->getType() == 4)
							{

								if (i != m_objects[j]->getArr())
								{

									m_objects[i]->setLife(m_objects[i]->getLife() - m_objects[j]->getLife());
									delete m_objects[j];
									m_objects[j] = NULL;
									--CurrentRectCount;
								}
							}
							else if (m_objects[i]->getType() == 1 && m_objects[j]->getType() == 3)
							{
								
								m_objects[i]->setLife(m_objects[i]->getLife() - m_objects[j]->getLife());
								delete m_objects[j];
								m_objects[j] = NULL;
								--CurrentRectCount;
							}
						}
						break;
					}
				
				}

			}
		}

	}
	
}

void SceneMgr::CreateRect(float x, float y, int type, int arr, int team)
{
	
	if (CurrentRectCount < MAX_OBJECTS_COUNT)
	{
		for (int i = 0; i < MAX_OBJECTS_COUNT; ++i)
		{
			if (m_objects[i] == NULL)
			{
				if (type == 1)
				{
				
					//cout << "생성 " << endl;
					m_objects[i] = new Object;
					m_objects[i]->setPosX(x);
					m_objects[i]->setPosY(y);
					m_objects[i]->setPosZ(0);
					m_objects[i]->setSize(100);
					/*if (m_objects[i]->getTeam() == 1)
					{
						m_objects[i]->setColorR(1.0f);
						m_objects[i]->setColorG(0.0f);
						m_objects[i]->setColorB(0.0f);
						m_objects[i]->setColorA(1.0f);
					}
					else
					{
						m_objects[i]->setColorR(0.0f);
						m_objects[i]->setColorG(0.0f);
						m_objects[i]->setColorB(1.0f);
						m_objects[i]->setColorA(1.0f);
					}*/
					
					m_objects[i]->setType(1);
					m_objects[i]->setDirX(0);
					m_objects[i]->setLife(500);
					m_objects[i]->setmaxLife(500);
					m_objects[i]->setDirX(0);
					m_objects[i]->setSpeed(0);
					
					m_objects[i]->setDirY(0);
					
					m_objects[i]->setDirY(0);
					m_objects[i]->setTeam(team);
					m_objects[i]->setLevel(LEVEL_BUILDING);
					++CurrentRectCount;

					break;
				}
				else if (type == 2)
				{
					/*if (team == 2)
					{
						if (CharacterRespawn == false)
							break;
					}*/
					//cout << "생성 " << endl;
					m_objects[i] = new Object;
					m_objects[i]->setPosX(x);
					m_objects[i]->setPosY(y);
					m_objects[i]->setPosZ(0);
					m_objects[i]->setSize(30);
					if (team == 1)
					{
						m_objects[i]->setColorR(1.0f);
						m_objects[i]->setColorG(0.0f);
						m_objects[i]->setColorB(0.0f);
						m_objects[i]->setColorA(1.0f);
						m_objects[i]->setSize(50);
						m_objects[i]->setDirX(rand() % 20 * 0.1 - 1);
						m_objects[i]->setDirY(rand() % 20 * 0.1 - 2);
					}
					else
					{
						m_objects[i]->setColorR(0.0f);
						m_objects[i]->setColorG(0.0f);
						m_objects[i]->setColorB(1.0f);
						m_objects[i]->setColorA(1.0f);
						m_objects[i]->setDirX(rand() % 20 * 0.1 - 1);
						m_objects[i]->setDirY(rand() % 20 * 0.1 + 0.1);
					}
					m_objects[i]->setLife(100);
					m_objects[i]->setmaxLife(100);
					m_objects[i]->setType(2);
					m_objects[i]->setSpeed(100);
					
					m_objects[i]->setTeam(team);
					m_objects[i]->setLevel(LEVEL_CHARACTER);
					++CurrentRectCount;
					if (team == 2)
						CharacterRespawn = false;
					CharacterCool = 0;
					break;
				}
				else if (type == 3)
				{
					//cout << "생성 " << endl;
					m_objects[i] = new Object;
					m_objects[i]->setPosX(x);
					m_objects[i]->setPosY(y);
					m_objects[i]->setPosZ(0);
					m_objects[i]->setSize(4);
					if (team == 1)
					{
						m_objects[i]->setColorR(1.0f);
						m_objects[i]->setColorG(0.0f);
						m_objects[i]->setColorB(0.0f);
						m_objects[i]->setColorA(1.0f);
						m_objects[i]->setDirX(rand() % 20 * 0.1 - 1);
						m_objects[i]->setDirY(rand() % 20 * 0.1 - 2);
					}
					else
					{
						m_objects[i]->setColorR(0.0f);
						m_objects[i]->setColorG(0.0f);
						m_objects[i]->setColorB(1.0f);
						m_objects[i]->setColorA(1.0f);
						m_objects[i]->setDirX(rand() % 20 * 0.1 - 1);
						m_objects[i]->setDirY(rand() % 20 * 0.1 + 0.1);
					}
					m_objects[i]->setLife(15);
					m_objects[i]->setmaxLife(15);
					m_objects[i]->setType(3);
					m_objects[i]->setSpeed(100);
					
					m_objects[i]->setTeam(team);
					m_objects[i]->setLevel(LEVEL_BULLET);
					++CurrentRectCount;
					break;
				}
				else if (type == 4)
				{
					//cout << "생성 " << endl;
					m_objects[i] = new Object;
					m_objects[i]->setPosX(x);
					m_objects[i]->setPosY(y);
					m_objects[i]->setPosZ(0);
					m_objects[i]->setSize(4);
					if (team == 1)
					{
						m_objects[i]->setColorR(0.5f);
						m_objects[i]->setColorG(0.2f);
						m_objects[i]->setColorB(0.7f);
						m_objects[i]->setColorA(1.0f);
						m_objects[i]->setDirX(rand() % 20 * 0.1 - 1);
						m_objects[i]->setDirY(rand() % 20 * 0.1 - 2);
					}
					else
					{
						m_objects[i]->setColorR(1.0f);
						m_objects[i]->setColorG(1.0f);
						m_objects[i]->setColorB(0.0f);
						m_objects[i]->setColorA(1.0f);
						m_objects[i]->setDirX(rand() % 20 * 0.1 - 1);
						m_objects[i]->setDirY(rand() % 20 * 0.1 + 0.1);
					}
					m_objects[i]->setLife(10);
					m_objects[i]->setmaxLife(10);
					m_objects[i]->setType(4);
					m_objects[i]->setSpeed(50);
					m_objects[i]->setArr(arr);
					m_objects[i]->setTeam(team);
					m_objects[i]->setLevel(LEVEL_ARROW);
					++CurrentRectCount;
					break;
				}
				else if (type == 5)
				{
					m_objects[i] = new Object;
					m_objects[i]->setPosX(0);
					m_objects[i]->setPosY(0);
					m_objects[i]->setPosZ(0);
					m_objects[i]->setSize(800);
					m_objects[i]->setType(5);
					m_objects[i]->setLife(190000);
					m_objects[i]->setmaxLife(1000);
					m_objects[i]->setLevel(LEVEL_BACKGROUND);
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
			CreateRect(m_objects[i]->getPosX(), m_objects[i]->getPosY(), 3, i, m_objects[i]->getTeam());
		}
	}
}
