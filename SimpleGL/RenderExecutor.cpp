#include "stdafx.h"
#include "RenderExecutor.h"

#include "RHIDX11.h"
#include "RenderStateDX11.h"

namespace SimpleGL
{
	RenderExecutor::RenderExecutor()
	{
	}


	RenderExecutor::~RenderExecutor()
	{
	}

	void RenderExecutor::Execute(RenderStateDX11* pRenderState)
	{
		if (!pRenderState)
			return;

		// Set Vertex buffer
		gRHI->GetDeviceContext()->IASetVertexBuffers(0, 1, &pRenderState->m_VertexBuffer, &pRenderState->m_nStride, &pRenderState->m_nOffset);

		// Set index buffer
		gRHI->GetDeviceContext()->IASetIndexBuffer(pRenderState->m_IndexBuffer.Get(), DXGI_FORMAT_R32_UINT, 0);

		// Set primitive topology
		gRHI->GetDeviceContext()->IASetPrimitiveTopology(pRenderState->m_PrimitiveTopology);

		// Set Shader Params
		struct None {/* 앞으로 채워 넣을 것*/} none;
		gRHI->GetDeviceContext()->UpdateSubresource(pRenderState->m_ConstantBuffer.Get(), 0, nullptr, &none, 0, 0);


		gRHI->ClearRenterTargetView();


		gRHI->GetDeviceContext()->VSSetShader(gRHI->GetVertexShader(), nullptr, 0);
		gRHI->GetDeviceContext()->VSSetConstantBuffers(0, 1, &pRenderState->m_ConstantBuffer);

		gRHI->GetDeviceContext()->PSSetShader(gRHI->GetPixelShader(), nullptr, 0);
		gRHI->GetDeviceContext()->PSSetConstantBuffers(1, 1, &pRenderState->m_ConstantBuffer);
		gRHI->GetDeviceContext()->PSSetShaderResources(0, 1, nullptr);
		gRHI->GetDeviceContext()->PSSetSamplers(0, 1, &pRenderState->m_SamplerState);

		// 더 나은 방법이 있을텐데 찾아보자
		switch (pRenderState->m_eMethod)
		{
		case RenderStateDX11::Draw:
			gRHI->GetDeviceContext()->Draw(pRenderState->m_nVertexSize, 0);
			break;
		case RenderStateDX11::Draw_Index:
			gRHI->GetDeviceContext()->DrawIndexed(pRenderState->m_nIndexSize, 0, 0);
			break;
		default:
			break;
		}
	}
}