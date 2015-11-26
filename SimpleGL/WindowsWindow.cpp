#include "stdafx.h"
#include "WindowsWindow.h"

namespace SimpleGL
{
	WindowsWindow::WindowsWindow()
	{
	}


	WindowsWindow::~WindowsWindow()
	{
	}

	void WindowsWindow::Initialize()
	{
		HINSTANCE hInstance = (HINSTANCE)GetModuleHandle(NULL);

		MyRegisterClass(hInstance);

		if (!InitInstance(hInstance, SW_SHOW))
		{
			assert(false);
			return;
		}
	}
	
	void WindowsWindow::Finalize()
	{
	}

	void WindowsWindow::Update()
	{
	}

	bool WindowsWindow::InitInstance(HINSTANCE hInstance, int nCmdShow)
	{
		HWND hWnd;
		hWnd = CreateWindow(TEXT("SimpleEngine"), TEXT("Engine"), WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, NULL, hInstance, NULL);

		if (!hWnd)
		{
			return false;
		}

		::ShowWindow(hWnd, nCmdShow);
		::UpdateWindow(hWnd);

		return true;
	}

	int WindowsWindow::MyRegisterClass(HINSTANCE hInstance)
	{
		WNDCLASS wc;

		wc.style = CS_DBLCLKS;
		wc.lpfnWndProc = WndProc;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hInstance = hInstance;
		wc.hIcon = nullptr;
		wc.hCursor = nullptr;
		wc.hbrBackground = nullptr;
		wc.lpszMenuName = nullptr;
		wc.lpszClassName = TEXT("SimpleEngine");

		return ::RegisterClass(&wc);
	}

	void WindowsWindow::MsgLoop()
	{
		MSG msg;
		while (GetMessage(&msg, NULL, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	LRESULT CALLBACK WindowsWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
			case WM_PAINT:
			{
				PAINTSTRUCT ps;
				HDC hdc = BeginPaint(hWnd, &ps);
				EndPaint(hWnd, &ps);
			}
			break;

			case WM_DESTROY:
				PostQuitMessage(0);
				break;

			default:
				return DefWindowProc(hWnd, message, wParam, lParam);
		}
		return 0;
	}
}