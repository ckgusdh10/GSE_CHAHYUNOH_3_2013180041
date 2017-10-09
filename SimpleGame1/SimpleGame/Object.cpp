#include "stdafx.h"
#include "Object.h"

Object::Object(float x, float y, float z, float size, float r, float g, float b, float a)
{
	m_x = x;
	m_y = y;
	m_z = z;
	m_size = size;
	m_r = r;
	m_g = g;
	m_b = b;
	m_a = a;

}

Object::~Object()
{
}


float Object::getPosX()
{

	return m_x;
}

float Object::getPosY()
{
	return m_y;
}

float Object::getPosZ()
{
	return m_z;
}

float Object::getPosSize()
{
	return m_size;
}

float Object::getPosR()
{
	return m_r;
}

float Object::getPosG()
{
	return m_g;
}

float Object::getPosB()
{
	return m_b;
}

float Object::getPosA()
{
	return m_a;
}
