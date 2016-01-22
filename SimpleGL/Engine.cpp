#include "stdafx.h"
#include "Engine.h"
#include "WindowsWindow.h"
#include "RHIDX11.h"
#include "ObjectManager.h"

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
		RenderWindow = new WindowsWindow;
		if (RenderWindow)
			RenderWindow->Initialize();

		RHIDX11::Create();
		gRHI->Initialize(RenderWindow);

		m_pObjectManager = new ObjectManager;
		m_pObjectManager->CreateObject();
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

			//Update & Rendering
			m_pObjectManager->Tick();
			m_pObjectManager->Render();

			gRHI->Draw();

			gRHI->Present();
		}
	}
}