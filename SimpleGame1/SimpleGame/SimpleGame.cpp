/*
Copyright 2017 Lee Taek Hee (Korea Polytech University)

This program is free software: you can redistribute it and/or modify
it under the terms of the What The Hell License. Do it plz.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY.
*/

#include "stdafx.h"
#include <Windows.h>
#include <chrono>
#include <iostream>
#include "Dependencies\glew.h"
#include "Dependencies\freeglut.h"

#include "Renderer.h"
#include "Object.h"
#include "SceneMgr.h"
using namespace std;

Renderer *g_Renderer = NULL;

SceneMgr* g_SceneMgr = NULL;

auto g_start = 0;
float CharacterCool = 0;
bool CharacterRespawn = true;

void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
	glClearDepth(1.f);

	auto CurTime = timeGetTime();
	auto ETime = CurTime - g_start;
	g_start = CurTime;

	//CharacterCool += ETime * 0.001;
	//if (CharacterCool >= 0)
	//{
	//	CharacterRespawn = true;
	//}
	

	g_SceneMgr->Update((float)ETime);
	g_SceneMgr->Collision();
	g_SceneMgr->DrawAll((float)ETime);
	

	glutSwapBuffers();
}

void Idle(void)
{
	RenderScene();
}

void MouseInput(int button, int state, int x, int y)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
			
		if (x > 250)
		{
			g_SceneMgr->CreateRect(60, -250, 2, 0, 2);
			
		}
		else
		{
			g_SceneMgr->CreateRect(-60, -250, 2, 0, 2);
		
		}
		
		
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
	{
		
		if (x > 250)
		{
			g_SceneMgr->CreateRect(60, -250, 6, 0, 2);
			
		}
		else
		{
			g_SceneMgr->CreateRect(-60, -250, 6, 0, 2);
			
		}
		
		
	}
	RenderScene();
}

void KeyInput(unsigned char key, int x, int y)
{
	RenderScene();
}

void SpecialKeyInput(int key, int x, int y)
{
	RenderScene();
}

int main(int argc, char **argv)
{
	srand((unsigned)time(NULL));
	// Initialize GL things
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 800);
	glutCreateWindow("Game Software Engineering KPU");

	glewInit();
	if (glewIsSupported("GL_VERSION_3_0"))
	{
		std::cout << " GLEW Version is 3.0\n ";
	}
	else
	{
		std::cout << "GLEW 3.0 not supported\n ";
	}

	glutDisplayFunc(RenderScene);
	
	glutIdleFunc(Idle);
	glutKeyboardFunc(KeyInput);
	glutMouseFunc(MouseInput);
	glutSpecialFunc(SpecialKeyInput);
	g_SceneMgr = new SceneMgr;

	g_start = timeGetTime();
	glutMainLoop();
	
	delete g_SceneMgr;

    return 0;
}

