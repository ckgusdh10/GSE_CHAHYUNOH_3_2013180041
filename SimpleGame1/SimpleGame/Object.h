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

	int m_dirX = 1;
	int m_dirY = 1;

public:
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

	void setPosX(float x);
	void setPosY(float y);
	void setPosZ(float z);
	

	void Update();
};