#include "stdafx.h"
#include "RenderStateDX11.h"

namespace SimpleGL
{
	RenderStateDX11::RenderStateDX11()
	{
	}


	RenderStateDX11::~RenderStateDX11()
	{
	}

	void RenderStateDX11::SetVertexShader(ID3D11VertexShader* pVertexShader)
	{
		m_VertexShader = pVertexShader;
	}

	void RenderStateDX11::SetPixelShader(ID3D11PixelShader* pPixelShader)
	{
		m_PixelShader = pPixelShader;
	}

	void RenderStateDX11::SetVertexBuffer(ID3D11Buffer* pVertexBuffer, UINT nStride, UINT nOffset)
	{
		m_VertexBuffer = pVertexBuffer;
		m_nStride = nStride;
		m_nOffset = nOffset;
	}

	void RenderStateDX11::SetIndexBuffer(ID3D11Buffer* pIndexBuffer)
	{
		m_IndexBuffer = pIndexBuffer;
	}

	void RenderStateDX11::SetConstantBuffer(ID3D11Buffer* pConstantBuffer)
	{
		m_ConstantBuffer = pConstantBuffer;
	}

	void RenderStateDX11::SetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY PrimitiveTopology)
	{
		m_PrimitiveTopology = PrimitiveTopology;
	}

	void RenderStateDX11::SetSamplerState(ID3D11SamplerState* pSamplerState)
	{
		m_SamplerState = pSamplerState;
	}

	void RenderStateDX11::AddConstantBuffer(std::pair<ID3D11Buffer*, ConstantBufferBase*> buffer)
	{
		m_ConstantBufferContainer.insert(buffer);
	}

}