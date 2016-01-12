#pragma once

namespace SimpleGL
{
	using namespace DirectX;

	class StaticMeshVertex
	{
	public:
	 	struct Vertex
	 	{
	 		XMFLOAT3 Pos;
			XMFLOAT4 Color;
	 		//XMFLOAT2 Tex;
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

	class StaticMesh
	{
	public:
		StaticMesh();
		virtual ~StaticMesh();

		void AddVertex(StaticMeshVertex vertex);
		void AddIndices(unsigned int i1, unsigned int i2, unsigned int i3);

	private:
		std::vector<StaticMeshVertex> Vertices;
		std::vector<unsigned int> Indices;
	};
}