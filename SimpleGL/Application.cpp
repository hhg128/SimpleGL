#include "stdafx.h"
#include "Application.h"
#include "Engine.h"

Application::Application()
	: m_pEngine(nullptr)
{
}


Application::~Application()
{
}

void Application::Initialize()
{
	m_pEngine = new SimpleGL::Engine;
}

void Application::Shutdown()
{
	if (m_pEngine)
	{
		m_pEngine->Finalize();
		delete m_pEngine;
	}
}

void Application::Update()
{
	if (m_pEngine)
	{
		m_pEngine->Update();
	}
}
