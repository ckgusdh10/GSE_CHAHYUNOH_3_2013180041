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
};