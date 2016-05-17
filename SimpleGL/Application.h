#pragma once

namespace SimpleGL
{
	class Engine;
}

class Application
{
public:
	Application();
	~Application();

	void Initialize();
	void Shutdown();
	void Update();

private:
	SimpleGL::Engine*		m_pEngine;
};

