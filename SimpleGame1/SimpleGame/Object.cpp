#include "stdafx.h"
#include "Object.h"

Object::Object()
{
	
	m_x = 0;
	m_y = 0;
	m_z = 0;
	m_size = 10;
	m_r = 1.0f;
	m_g = 0.0f;
	m_b = 0.0f;
	m_a = 1.0f;
	accumETime = 0;
}

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

float Object::getLife()
{
	return m_life;
}

float Object::getLifeTime()
{
	return m_lifetime;
}

int Object::getType()
{
	return m_type;
}

float Object::getAccumTime()
{
	return accumETime;
}

int Object::getArr()
{
	return arr;
}

int Object::getTeam()
{
	return team;
}

float Object::getLevel()
{
	return level;
}

int Object::getmaxLife()
{
	return m_maxLife;
}

float Object::getCookie()
{
	return m_cookie;
}

float Object::getCat()
{
	return m_cat;
}

float Object::getCat1()
{
	return m_cat1;
}

float Object::getTs()
{
	return m_ts;
}

float Object::getDirx()
{
	return m_dirX;
}

float Object::getDiry()
{
	return m_dirY;
}

void Object::setPosX(float x)
{
	m_x = x;
}

void Object::setPosY(float y)
{
	m_y = y;
}

void Object::setPosZ(float z)
{
	m_z = z;
}

void Object::setSize(float size)
{
	m_size = size;
}

void Object::setColorR(float red)
{
	m_r = red;
}

void Object::setColorG(float green)
{
	m_g = green;
}

void Object::setColorB(float blue)
{
	m_b = blue;
}

void Object::setColorA(float a)
{
	m_a = a;
}

void Object::setDirX(float dirX)
{
	m_dirX = dirX;
}

void Object::setDirY(float dirY)
{
	m_dirY = dirY;
}

void Object::setType(int type)
{
	m_type = type;
}

void Object::setLife(int life)
{
	m_life = life;
}

void Object::setSpeed(float speed)
{
	m_speed = speed;
}

void Object::setAccumTime(float accumTime)
{
	accumETime = accumTime;
}

void Object::setArr(int Arr)
{
	arr = Arr;
}

void Object::setTeam(int t)
{
	team = t;
}

void Object::setLevel(float l)
{
	level = l;
}

void Object::setmaxLife(float ml)
{
	m_maxLife = ml;
}

void Object::setCookie(float c)
{
	m_cookie = c;
}

void Object::setCat(float c)
{
	m_cat = c;
}

void Object::setCat1(float c)
{
	m_cat1 = c;
}

void Object::setTs(float t)
{
	m_ts = t;
}

void Object::Update(float E_Time)
{
	accumETime += E_Time * 0.001;

	m_x = m_x + m_dirX * m_speed * E_Time * 0.001;
	m_y = m_y + m_dirY * m_speed * E_Time * 0.001;
	
	if (m_lifetime >= 0)
	{
		m_lifetime -= 0.5;
	}

		
	if (m_y > 400)
	{
		m_dirY = -m_dirY;
	}
	if(m_x > 250)
	{
		m_dirX = -m_dirX;
	}
	if (m_y < -400)
	{
		m_dirY = -m_dirY;
	}
	if(m_x < -250)
	{
		m_dirX = -m_dirX;
	}
	
}

void Object::BulletArrowUpdate(float E_Time)
{
	m_x = m_x + m_dirX * m_speed * E_Time * 0.001;
	m_y = m_y + m_dirY * m_speed * E_Time * 0.001;
	if (m_lifetime >= 0)
	{
		m_lifetime -= 0.5;
	}
}

void Object::CharacterUpdate(float E_Time)
{
	
}


