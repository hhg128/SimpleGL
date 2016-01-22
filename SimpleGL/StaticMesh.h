#pragma once
#include "ConstantBufferBase.h"

namespace SimpleGL
{
	using namespace DirectX;

	class RenderStateDX11;

	class StaticMeshVertex
	{
	public:
	 	struct Vertex
	 	{
			XMFLOAT3 Pos;
			XMFLOAT4 Color;
	 	};

		Vertex vertex;
	 
	 	static unsigned int GetElementCount() { return(sizeof(Elements) / sizeof(Elements[0])); }
	 	static D3D11_INPUT_ELEMENT_DESC Elements[2];
	};

	class StaticMeshRenderData
	{
	private:
		std::vector<StaticMeshVertex> VertexData;
	};

	class StaticMeshVertexBuffer
	{

	};

	//struct CBNeverChanges
	//{
	//	XMMATRIX mView;
	//	XMMATRIX mProjection;
	//	XMMATRIX mWorld;
	//};

	//struct ConstantBufferStruct
	//{
	//	XMFLOAT4 vMeshColor;
	//};

	class StaticMesh
	{
	public:
		StaticMesh();
		virtual ~StaticMesh();

		void AddVertex(StaticMeshVertex vertex);
		void AddIndices(unsigned int i1, unsigned int i2, unsigned int i3);

		void PrepareRendering();
		void Render();
		void Tick();

	private:
		std::vector<StaticMeshVertex> Vertices;
		std::vector<unsigned int> Indices;
		ID3D11Buffer* VertexBuffer;
		ID3D11Buffer* IndexBuffer;
		ID3D11Buffer* ConstantBuffer;
		ID3D11Buffer* PSConstantBuffer;
		ID3D11SamplerState* SamplerLinear;

		CBNeverChanges* cbNeverChanges;
		ConstantBufferStruct* color;

		RenderStateDX11* m_pRenderState;
	};
}