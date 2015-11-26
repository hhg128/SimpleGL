#pragma once
#include "Window.h"

namespace SimpleGL
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow();
		virtual ~WindowsWindow();

		virtual void Initialize() override;
		virtual void Finalize() override;
		virtual void Update() override;

		static void MsgLoop();

	private:
		bool InitInstance(HINSTANCE hInstance, int nCmdShow);
		int MyRegisterClass(HINSTANCE hInstance);

		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	};

}