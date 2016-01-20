#pragma once

namespace SimpleGL
{
	using namespace Microsoft::WRL;

	class RenderStateDX11
	{
	public:
		RenderStateDX11();
		~RenderStateDX11();

		void SetVertexShader(ID3D11VertexShader* pVertexShader);
		void SetPixelShader(ID3D11PixelShader* pPixelShader);
		void SetVertexBuffer(ID3D11Buffer* pVertexBuffer, UINT nStride, UINT nOffset);
		void SetIndexBuffer(ID3D11Buffer* pIndexBuffer);
		void SetConstantBuffer(ID3D11Buffer* pConstantBuffer);
		void SetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY PrimitiveTopology);
		void SetSamplerState(ID3D11SamplerState* pSamplerState);

	public:
		ComPtr<ID3D11DeviceContext>		m_DeviceContext;

		ComPtr<ID3D11VertexShader>		m_VertexShader;
		ComPtr<ID3D11PixelShader>		m_PixelShader;

		UINT							m_nStride = 0;
		UINT							m_nOffset = 0;
		UINT							m_nVertexSize = 0;
		ComPtr<ID3D11Buffer>			m_VertexBuffer;

		UINT							m_nIndexSize = 0;
		ComPtr<ID3D11Buffer>			m_IndexBuffer;
		ComPtr<ID3D11Buffer>			m_ConstantBuffer;

		D3D11_PRIMITIVE_TOPOLOGY		m_PrimitiveTopology;

		ComPtr<ID3D11SamplerState>		m_SamplerState;

		enum DrawMethod
		{
			NONE,
			Draw,
			Draw_Index,
		} m_eMethod = NONE;
	};
}