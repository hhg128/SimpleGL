#pragma once

namespace SimpleGL
{
	using namespace DirectX;

	class StaticMesh;

	class TriangleModel
	{
	public:
		TriangleModel();
		~TriangleModel();

		void Initialize();
		void Finalize();

		void Tick();
		void Render();

	private:
		StaticMesh*		Mesh;
	};

	class CubeModel
	{
	public:
		CubeModel();
		~CubeModel();
	};
}