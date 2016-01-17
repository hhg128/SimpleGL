#pragma once

namespace SimpleGL
{
	using namespace Microsoft::WRL;

	class RenderStateDX11
	{
	public:
		RenderStateDX11();
		~RenderStateDX11();

	protected:
		ComPtr<ID3D11DeviceContext>		m_DeviceContext;

		ComPtr<ID3D11VertexShader>		m_VertexShader;
		ComPtr<ID3D11PixelShader>		m_PixelShader;

		UINT							m_nStride = 0;
		UINT							m_nOffset = 0;
		ComPtr<ID3D11Buffer>			m_VertexBuffer;
		ComPtr<ID3D11Buffer>			m_IndexBuffer;
		ComPtr<ID3D11Buffer>			m_ConstantBuffer;

		D3D11_PRIMITIVE_TOPOLOGY		m_PrimitiveTopology;

		ComPtr<ID3D11SamplerState>		m_SamplerState;


	};
}