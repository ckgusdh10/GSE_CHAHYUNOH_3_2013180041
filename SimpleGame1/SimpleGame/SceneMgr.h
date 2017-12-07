#pragma once
#include "Object.h"
#include "Renderer.h"
#include "Sound.h"
#include <random>

#define MAX_OBJECTS_COUNT 500



class SceneMgr {
private:
	Renderer *m_Renderer;
	Object* m_objects[MAX_OBJECTS_COUNT];
	GLint m_texCharacter;
	GLint m_texCharacter2;
	GLint m_texBackGround;
	GLint m_texCookie;
	GLint m_texCat;
	GLint m_texPar;
	Sound* m_sound = NULL;
	
	float accuTime = 0;
	float CharacterCool = 0;
	bool CharacterRespawn = true;
	float cookie = 0;
	float cat = 0;
	float cat1 = 0;
	float ts = 0;
	float scaleX = 0;
	float scaleY = 0;
	bool Scale = true;
	bool bCollision = false;
	GLint backsound;

public:
	SceneMgr();
	~SceneMgr();

	void DrawAll();
	void Update(float E_Time);
	void Collision();
	void CreateRect(float x, float y, int type, int arr, int team);
	bool CheckLifeTime(Object* o);
	bool CheckLife(Object* o);
	int CurrentRectCount = 0;

	void CreateBullet(float E_Time);
};