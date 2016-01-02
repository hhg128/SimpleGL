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
		m_hWnd = CreateWindowEx(NULL, TEXT("SimpleEngine"), TEXT("Engine"), WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, NULL, NULL, NULL, NULL);

		if (!m_hWnd)
		{
			return false;
		}

		::ShowWindow(m_hWnd, nCmdShow);
		::UpdateWindow(m_hWnd);

		return true;
	}

	int WindowsWindow::MyRegisterClass(HINSTANCE hInstance)
	{
		WNDCLASSEX wcex;

		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;;
		wcex.lpfnWndProc = WndProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = 0;
		wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);;
		wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		wcex.lpszMenuName = nullptr;
		wcex.lpszClassName = TEXT("SimpleEngine");
		wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

		return ::RegisterClassEx(&wcex);
	}

	bool WindowsWindow::MsgLoop()
	{
		MSG msg;
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				return false;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return true;
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