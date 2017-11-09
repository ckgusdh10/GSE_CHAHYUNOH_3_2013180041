#pragma once
#include "Object.h"
#include "Renderer.h"
#include <random>

#define MAX_OBJECTS_COUNT 500



class SceneMgr {
private:
	Renderer *m_Renderer;
	Object* m_objects[MAX_OBJECTS_COUNT];
	GLint m_texCharacter;


public:
	SceneMgr();
	~SceneMgr();

	void DrawAll();
	void Update(float E_Time);
	void Collision();
	void CreateRect(float x, float y, int type, int arr);
	bool CheckLifeTime(Object* o);
	bool CheckLife(Object* o);
	int CurrentRectCount = 0;

	void CreateBullet(float E_Time);
};