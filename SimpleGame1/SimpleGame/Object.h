#pragma once
#include "stdafx.h"
#include "Renderer.h"




class Object {
	float m_x;
	float m_y;
	float m_z;
	float m_size;
	float m_r;
	float m_g;
	float m_b;
	float m_a;
	float m_speed;
	int m_type;
	float accumETime;

	float m_dirX = 1;
	float m_dirY = 1;

	float m_life;
	float m_maxLife;
	float m_lifetime = 1000000;

	int arr = -1;

	int team = 0;
	float level;

public:
	Object();
	Object(float x, float y, float z, float size, float r, float g, float b, float a);
	~Object();

	float getPosX();
	float getPosY();
	float getPosZ();
	float getPosSize();
	float getPosR();
	float getPosG();
	float getPosB();
	float getPosA();
	float getLife();
	float getLifeTime();
	int getType();
	float getAccumTime();
	int getArr();
	int getTeam();
	int getLevel();
	int getmaxLife();

	void setPosX(float x);
	void setPosY(float y);
	void setPosZ(float z);
	void setSize(float size);
	void setColorR(float red);
	void setColorG(float green);
	void setColorB(float blue);
	void setColorA(float a);
	void setDirX(float dirX);
	void setDirY(float dirY);
	void setType(int type);
	void setLife(int life);
	void setSpeed(float speed);
	void setAccumTime(float accumTime);
	void setArr(int arr);
	void setTeam(int t);
	void setLevel(float l);
	void setmaxLife(float ml);

	void Update(float E_Time);
	void BulletArrowUpdate(float E_Time);
};