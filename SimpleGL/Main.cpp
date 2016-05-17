// SimpleGL.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "SimpleGL.h"
#include "Engine.h"
#include "Application.h"

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpCmdLine, _In_ int nCmdShow)
{
	Application App;
	App.Initialize();
	App.Update();
	App.Shutdown();

	return 0;
}