#pragma once

namespace SimpleGL
{
	using namespace DirectX;

	class RHIDX11;

	class ObjectVertex
	{
	public:
		struct Vertex
		{
			XMFLOAT3 Pos;
			XMFLOAT2 Tex;
		};

		static unsigned int GetElementCount() { return(sizeof(Elements) / sizeof(Elements[0])); }
		static D3D11_INPUT_ELEMENT_DESC Elements[2];
	};

	class Object
	{
	public:
		Object();
		virtual ~Object();

		void Initialize();
		void Finalize();

		void Tick();
		void Render();
	};
}