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

		static bool MsgLoop();

	private:
		bool InitInstance(HINSTANCE hInstance, int nCmdShow);
		int MyRegisterClass(HINSTANCE hInstance);

		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	public:
		HWND GetHwnd() const { return m_hWnd; }

	private:
		HWND m_hWnd;
	};

}