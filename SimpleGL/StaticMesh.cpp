#include "stdafx.h"
#include "StaticMesh.h"
#include "RHIDX11.h"

namespace SimpleGL
{
	D3D11_INPUT_ELEMENT_DESC StaticMeshVertex::Elements[2] = {
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};

	StaticMesh::StaticMesh()
	{
		gRHI->CreateVertexShader(StaticMeshVertex::Elements, StaticMeshVertex::GetElementCount());
		gRHI->CreatePixelShader();
	}


	StaticMesh::~StaticMesh()
	{
	}

	void StaticMesh::AddVertex(StaticMeshVertex vertex)
	{
		Vertices.push_back(vertex);
	}

	void StaticMesh::AddIndices(unsigned int i1, unsigned int i2, unsigned int i3)
	{
		Indices.push_back(i1);
		Indices.push_back(i2);
		Indices.push_back(i3);
	}

}