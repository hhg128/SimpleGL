#pragma once
#include "ConstantBufferBase.h"

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

		void AddConstantBuffer(ID3D11Buffer* Buffer);

	public:
		ComPtr<ID3D11DeviceContext>		m_DeviceContext;

		ComPtr<ID3D11VertexShader>		m_VertexShader;
		ComPtr<ID3D11PixelShader>		m_PixelShader;

		UINT							m_nStride = 0;
		UINT							m_nOffset = 0;
		UINT							m_nVertexSize = 0;
		ID3D11Buffer*					m_VertexBuffer;

		UINT							m_nIndexSize = 0;
		ID3D11Buffer*					m_IndexBuffer;
		ID3D11Buffer*					m_ConstantBuffer;
		UINT							m_ConstantBufferSize;
		unsigned char*					m_ConstantBufferRaw;

		struct ConstantBufferState
		{
			ID3D11Buffer* Buffer;
			UINT FirstConstant;
			UINT NumConstants;
		};
		std::vector<ConstantBufferState> m_ConstantBufferList;



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