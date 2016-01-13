#pragma once

namespace SimpleGL
{
	using namespace DirectX;

	class RHIDX11;

	class TriangleModel;

	class Object
	{
	public:
		Object();
		virtual ~Object();

		void Initialize();
		void Finalize();

		void Tick();
		void Render();

	private:
		TriangleModel* Model;
	};
}