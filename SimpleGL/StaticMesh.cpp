#include "stdafx.h"
#include "StaticMesh.h"

namespace SimpleGL
{
	StaticMesh::StaticMesh()
	{
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