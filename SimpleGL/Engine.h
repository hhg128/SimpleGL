#pragma once

namespace SimpleGL
{
	class Window;
	class WindowsWindow;
	class RHIDX11;
	class ObjectManager;

	class Engine
	{
	public:
		Engine();
		virtual ~Engine();

		virtual void Initialize();
		virtual void Finalize();
		virtual void Tick();

	private:
		WindowsWindow*	RenderWindow;
		RHIDX11*		RHIDevice;
		ObjectManager*	m_pObjectManager;
	};
}