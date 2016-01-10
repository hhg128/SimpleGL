#pragma once

namespace SimpleGL
{
	using namespace DirectX;

	class TriangleVertex
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

	class TriangleModel
	{
	public:
		TriangleModel();
		~TriangleModel();
	};


	class CubeVertex
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

	class CubeModel
	{
	public:
		CubeModel();
		~CubeModel();
	};
}