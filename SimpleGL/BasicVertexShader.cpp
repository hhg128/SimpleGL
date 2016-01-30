#include "stdafx.h"
#include "BasicVertexShader.h"
#include "RHIDX11.h"

namespace SimpleGL
{

	BasicVertexShader::BasicVertexShader()
	{
	}


	BasicVertexShader::~BasicVertexShader()
	{
	}

	void BasicVertexShader::Compile()
	{
		HRESULT hr = S_OK;

		ID3DBlob* pVSBlob = nullptr;
		hr = gRHI->CompileShaderFromFile(TEXT("Shader/basic_vs.hlsl"), TEXT("VS"), TEXT("vs_4_0"), &pVSBlob);
		if (FAILED(hr))
		{
			MessageBox(nullptr,
				TEXT("The hlsl file cannot be compiled."), TEXT("Error"), MB_OK);
			return;
		}

		hr = gRHI->GetDevice()->CreateVertexShader(pVSBlob->GetBufferPointer(), pVSBlob->GetBufferSize(), nullptr, &m_pVertexShader);
		if (FAILED(hr))
		{
			pVSBlob->Release();
			return;
		}

		D3D11_INPUT_ELEMENT_DESC Elements[2] = {
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
		};

		hr = gRHI->GetDevice()->CreateInputLayout(Elements, sizeof(Elements)/sizeof(Elements[0]), pVSBlob->GetBufferPointer(),
			pVSBlob->GetBufferSize(), &m_pVertexLayout);
		pVSBlob->Release();
		if (FAILED(hr))
		{
			assert(hr);
		}

		gRHI->GetDeviceContext()->IASetInputLayout(m_pVertexLayout);
	}

}