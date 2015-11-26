#pragma once

namespace SimpleGL
{
	class Window
	{
	public:
		Window();
		virtual ~Window();

		virtual void Initialize() = 0;
		virtual void Finalize() = 0;
		virtual void Update() = 0;
	};
}