#pragma once
#include "Object.h"
#include "Renderer.h"
#include <random>

#define MAX_OBJECTS_COUNT 10



class SceneMgr {
private:
	Renderer *m_Renderer;
	Object* m_objects[MAX_OBJECTS_COUNT];
	


public:
	SceneMgr();
	~SceneMgr();

	void DrawAll();
	void Update(float E_Time);
	void Collision();
	void CreateRect(float x, float y);

	int CurrentRectCount = 0;
};