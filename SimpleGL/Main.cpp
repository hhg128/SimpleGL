// SimpleGL.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "SimpleGL.h"
#include "Engine.h"

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpCmdLine, _In_ int nCmdShow)
{
	SimpleGL::Engine engine;
	engine.Initialize();	
	engine.Tick();
	engine.Finalize();
	return 0;
}