#include "stdafx.h"
#include "StaticMesh.h"
#include "RHIDX11.h"

namespace SimpleGL
{
	D3D11_INPUT_ELEMENT_DESC StaticMeshVertex::Elements[2] = {
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
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
		XMMATRIX View;
		CBNeverChanges cbNeverChanges;
 		//XMVECTOR Eye = XMVectorSet(0.0f, 0.0f, -6.0f, 0.0f);
 		//XMVECTOR At = XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
 		//XMVECTOR Up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
 		//View = XMMatrixLookAtLH(Eye, At, Up);
		View = XMMatrixIdentity();
		cbNeverChanges.mView = XMMatrixTranspose(View);

		INT width, height;
		gRHI->GetWindowSize(width, height);

		XMMATRIX Projection;
		//Projection = XMMatrixPerspectiveFovLH(XM_PIDIV4, static_cast<float>(width / height), 0.001f, 1000.0f);
		Projection = XMMatrixIdentity();
		cbNeverChanges.mProjection = XMMatrixTranspose(Projection);

		XMMATRIX World;
		World = XMMatrixIdentity();
		cbNeverChanges.mWorld = XMMatrixTranspose(World);

		gRHI->GetDeviceContext()->UpdateSubresource(ConstantBuffer, 0, nullptr, &cbNeverChanges, 0, 0);

	
		ConstantBufferStruct color;
		color.vMeshColor = XMFLOAT4(1.f, 1.f, 1.f, 1.f);
		gRHI->GetDeviceContext()->UpdateSubresource(PSConstantBuffer, 0, nullptr, &color, 0, 0);

		// CB Input
		//////////////////////////////////////////////////////////////////////////
		// Render
		
		// Set vertex buffer
		UINT stride = sizeof(StaticMeshVertex::Vertex);
		UINT offset = 0;
		gRHI->GetDeviceContext()->IASetVertexBuffers(0, 1, &VertexBuffer, &stride, &offset);

		// Set index buffer
		gRHI->GetDeviceContext()->IASetIndexBuffer(IndexBuffer, DXGI_FORMAT_R32_UINT, 0);

		// Set primitive topology
		gRHI->GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

		gRHI->ClearRenterTargetView();
		gRHI->GetDeviceContext()->VSSetShader(gRHI->GetVertexShader(), nullptr, 0);
		gRHI->GetDeviceContext()->VSSetConstantBuffers(0, 1, &ConstantBuffer);
		gRHI->GetDeviceContext()->PSSetShader(gRHI->GetPixelShader(), nullptr, 0);
		gRHI->GetDeviceContext()->PSSetConstantBuffers(1, 1, &PSConstantBuffer);
		//gRHI->GetDeviceContext()->PSSetShaderResources(0, 1, &g_pTextureRV);
		gRHI->GetDeviceContext()->PSSetSamplers(0, 1, &SamplerLinear);
		gRHI->GetDeviceContext()->DrawIndexed(static_cast<UINT>(Indices.size()), 0, 0);
	}

	void StaticMesh::PrepareRendering()
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

		// Create Index Buffer
		D3D11_BUFFER_DESC indexBufferDesc;
		ZeroMemory(&indexBufferDesc, sizeof(indexBufferDesc));
		indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		indexBufferDesc.ByteWidth = sizeof(UINT) * static_cast<UINT>(Indices.size());
		indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		indexBufferDesc.CPUAccessFlags = 0;
		InitData.pSysMem = Indices.data();
		gRHI->GetDevice()->CreateBuffer(&indexBufferDesc, &InitData, &IndexBuffer);

		// Create the constant buffers
		D3D11_BUFFER_DESC constantBufferDesc;
		ZeroMemory(&constantBufferDesc, sizeof(constantBufferDesc));
		constantBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		constantBufferDesc.ByteWidth = sizeof(CBNeverChanges);
		constantBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		constantBufferDesc.CPUAccessFlags = 0;
		hr = gRHI->GetDevice()->CreateBuffer(&constantBufferDesc, nullptr, &ConstantBuffer);

		D3D11_BUFFER_DESC PSconstantBufferDesc;
		ZeroMemory(&PSconstantBufferDesc, sizeof(constantBufferDesc));
		PSconstantBufferDesc.Usage = D3D11_USAGE_DEFAULT;
		PSconstantBufferDesc.ByteWidth = sizeof(ConstantBufferStruct);
		PSconstantBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		PSconstantBufferDesc.CPUAccessFlags = 0;
		hr = gRHI->GetDevice()->CreateBuffer(&PSconstantBufferDesc, nullptr, &PSConstantBuffer);

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
	}

}