// SimpleGL.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "SimpleGL.h"
#include "WindowsWindow.h"

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPTSTR lpCmdLine, _In_ int nCmdShow)
{
	SimpleGL::WindowsWindow Win;

	Win.Initialize();
	SimpleGL::WindowsWindow::MsgLoop();
	Win.Finalize();

	return 0;
}