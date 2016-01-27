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
				TEXT("The hlsl file cannot be compiled.  Please run this executable from the directory that contains the FX file."), TEXT("Error"), MB_OK);
			return;
		}

		hr = gRHI->GetDevice()->CreateVertexShader(pVSBlob->GetBufferPointer(), pVSBlob->GetBufferSize(), nullptr, &m_pVertexShader);
		if (FAILED(hr))
		{
			pVSBlob->Release();
			return;
		}

		D3D11_INPUT_ELEMENT_DESC* pLayout = nullptr; 
		UINT numElements = 0;
		hr = gRHI->GetDevice()->CreateInputLayout(pLayout, numElements, pVSBlob->GetBufferPointer(),
			pVSBlob->GetBufferSize(), &m_pVertexLayout);
		pVSBlob->Release();
		if (FAILED(hr))
		{
			assert(hr);
		}

		gRHI->GetDeviceContext()->IASetInputLayout(m_pVertexLayout);
	}

}