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

	void StaticMesh::Render()
	{
		/*
		* VertexShaer -> PixelShader -> Vertex Buffer -> Index Buffer -> Constant Buffer -> Sampler State
		*/
		HRESULT hr = 0;

		// Create Vertex Buffer
		D3D11_BUFFER_DESC vertexBufferDesc;
		ZeroMemory(&vertexBufferDesc, sizeof(vertexBufferDesc));
		vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		vertexBufferDesc.ByteWidth = sizeof(StaticMeshVertex::Vertex) * static_cast<UINT>(Vertices.size());
		vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		vertexBufferDesc.CPUAccessFlags = 0;

		D3D11_SUBRESOURCE_DATA InitData;
		ZeroMemory(&InitData, sizeof(InitData));
		InitData.pSysMem = Vertices.data();

		gRHI->GetDevice()->CreateBuffer(&vertexBufferDesc, &InitData, &VertexBuffer);

		// Set vertex buffer
		UINT stride = sizeof(StaticMeshVertex::Vertex);
		UINT offset = 0;
		gRHI->GetDeviceContext()->IASetVertexBuffers(0, 1, &VertexBuffer, &stride, &offset);

		// Create Index Buffer
		D3D11_BUFFER_DESC indexBufferDesc;
		ZeroMemory(&indexBufferDesc, sizeof(indexBufferDesc));
		indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		indexBufferDesc.ByteWidth = sizeof(WORD) * static_cast<UINT>(Indices.size());
		indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		indexBufferDesc.CPUAccessFlags = 0;
		InitData.pSysMem = Indices.data();
		gRHI->GetDevice()->CreateBuffer(&indexBufferDesc, &InitData, &IndexBuffer);

		// Set index buffer
		gRHI->GetDeviceContext()->IASetIndexBuffer(IndexBuffer, DXGI_FORMAT_R16_UINT, 0);

		// Set primitive topology
		gRHI->GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		// Create the constant buffers
		struct ConstantBufferStruct
		{
			XMMATRIX mView;
		};
		D3D11_BUFFER_DESC constantBufferDesc;
		ZeroMemory(&constantBufferDesc, sizeof(constantBufferDesc));
		constantBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		constantBufferDesc.ByteWidth = sizeof(ConstantBufferStruct);
		constantBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		constantBufferDesc.CPUAccessFlags = 0;
		hr = gRHI->GetDevice()->CreateBuffer(&constantBufferDesc, nullptr, &ConstantBuffer);

		ConstantBufferStruct cbNeverChanges;
		gRHI->GetDeviceContext()->UpdateSubresource(ConstantBuffer, 0, nullptr, &cbNeverChanges, 0, 0);

		// Create the sample state
		D3D11_SAMPLER_DESC sampDesc;
		ZeroMemory(&sampDesc, sizeof(sampDesc));
		sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
		sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
		sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
		sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
		sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
		sampDesc.MinLOD = 0;
		sampDesc.MaxLOD = D3D11_FLOAT32_MAX;
		gRHI->GetDevice()->CreateSamplerState(&sampDesc, &SamplerLinear);

		// prepare rendering
		//////////////////////////////////////////////////////////////////////////
		// Rendering

		gRHI->ClearRenterTargetView();

		gRHI->GetDeviceContext()->VSSetShader(gRHI->GetVertexShader(), nullptr, 0);
		//gRHI->GetDeviceContext()->VSSetConstantBuffers(0, 1, &g_pCBNeverChanges);
		gRHI->GetDeviceContext()->PSSetShader(gRHI->GetPixelShader(), nullptr, 0);
		//gRHI->GetDeviceContext()->PSSetConstantBuffers(2, 1, &g_pCBChangesEveryFrame);
		//gRHI->GetDeviceContext()->PSSetShaderResources(0, 1, &g_pTextureRV);
		gRHI->GetDeviceContext()->PSSetSamplers(0, 1, &SamplerLinear);
		gRHI->GetDeviceContext()->DrawIndexed(static_cast<UINT>(Indices.size()), 0, 0);

	}

}