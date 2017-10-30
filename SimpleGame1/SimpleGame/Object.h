#pragma once
#include "stdafx.h"
#include "Renderer.h"
#include <time.h>



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
	
	float m_dirX = 1;
	float m_dirY = 1;

	float m_life = 100;
	float m_lifetime = 100;
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

	void setPosX(float x);
	void setPosY(float y);
	void setPosZ(float z);
	void setSize(float size);
	void setColorR(float red);
	void setColorG(float green);
	void setColorB(float blue);
	void setColorA(float a);
	void setDirX(int dirX);
	void setDirY(int dirY);

	void Update(float E_Time);
	
};