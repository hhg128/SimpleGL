#pragma once

namespace SimpleGL
{
	class Window;
	class WindowsWindow;

	class Engine
	{
	public:
		Engine();
		virtual ~Engine();

		virtual void Initialize();
		virtual void Finalize();
		virtual void Tick();

	private:
		WindowsWindow* RenderWindow;
	};
}