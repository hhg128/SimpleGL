#include "stdafx.h"
#include "Engine.h"
#include "WindowsWindow.h"
#include "RHIDX11.h"

namespace SimpleGL
{
	Engine::Engine() : RenderWindow(nullptr)
	{
	}


	Engine::~Engine()
	{
	}

	void Engine::Initialize()
	{
		RHIDevice = new RHIDX11;
		RHIDevice->Initialize();

		RenderWindow = new WindowsWindow;
		if (RenderWindow)
			RenderWindow->Initialize();
	}

	void Engine::Finalize()
	{
		if (RenderWindow)
		{
			RenderWindow->Finalize();

			delete RenderWindow;
			RenderWindow = nullptr;
		}
	}

	void Engine::Tick()
	{
		while (true)
		{
			if (!WindowsWindow::MsgLoop())
			{
				return;
			}
		}
	}
}