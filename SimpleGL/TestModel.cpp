#include "stdafx.h"
#include "TestModel.h"
#include "StaticMesh.h"

namespace SimpleGL
{
	TriangleModel::TriangleModel()
	{

	}

	TriangleModel::~TriangleModel()
	{

	}

	void TriangleModel::Initialize()
	{
		Mesh = new StaticMesh;
		
		StaticMeshVertex vertex;

		// Vertex 0
		vertex.vertex.Pos = XMFLOAT3(0.f, 1.f, 0.f);
		vertex.vertex.Color = XMFLOAT4(1.f, 0.f, 0.f, 0.f);
		Mesh->AddVertex(vertex);

		// Vertex 1
		vertex.vertex.Pos = XMFLOAT3(1.f, 0.f, 0.f);
		vertex.vertex.Color = XMFLOAT4(0.f, 1.f, 0.f, 0.f);
		Mesh->AddVertex(vertex);

		// Vertex 2
		vertex.vertex.Pos = XMFLOAT3(-1.f, 0.f, 0.f);
		vertex.vertex.Color = XMFLOAT4(0.f, 0.f, 1.f, 0.f);
		Mesh->AddVertex(vertex);

		// Indices 0 - 1 - 2
		Mesh->AddIndices(0, 1, 2);
	}

	void TriangleModel::Finalize()
	{
		delete Mesh;
	}

	void TriangleModel::Render()
	{
		Mesh->Render();
	}

	CubeModel::CubeModel()
	{

	}

	CubeModel::~CubeModel()
	{

	}
}