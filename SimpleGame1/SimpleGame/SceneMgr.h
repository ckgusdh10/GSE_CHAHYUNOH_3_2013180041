#pragma once
#include "Object.h"
#include "Renderer.h"
#include <random>

#define MAX_OBJECTS_COUNT 50



class SceneMgr {
private:
	Renderer *m_Renderer;
	Object* m_objects[MAX_OBJECTS_COUNT];
	

public:
	SceneMgr();
	~SceneMgr();

	void DrawAll();
	void Update();
	void Collision();
};