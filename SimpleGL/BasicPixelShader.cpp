#include "stdafx.h"
#include "BasicPixelShader.h"
#include "RHIDX11.h"

namespace SimpleGL
{
	BasicPixelShader::BasicPixelShader()
	{
	}


	BasicPixelShader::~BasicPixelShader()
	{
	}

	void BasicPixelShader::Compile()
	{
		HRESULT hr = S_OK;

		ID3DBlob* pPSBlob = nullptr;
		hr = gRHI->CompileShaderFromFile(TEXT("Shader/basic_ps.hlsl"), TEXT("PS"), TEXT("ps_4_0"), &pPSBlob);
		if (FAILED(hr))
		{
			MessageBox(nullptr,
				TEXT("The hlsl file cannot be compiled."), TEXT("Error"), MB_OK);
			return;
		}
	}

}