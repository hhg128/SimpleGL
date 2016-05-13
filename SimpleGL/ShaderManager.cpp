#include "stdafx.h"
#include "ShaderManager.h"
#include "VertexShader.h"
#include "RHIDX11.h"

namespace SimpleGL
{
	CShaderManager::CShaderManager()
	{
	}


	CShaderManager::~CShaderManager()
	{
	}

	void CShaderManager::LoadShader(const std::wstring& fileName, ShaderType shaderType)
	{
		switch (shaderType)
		{
			case VERTEX_SHADER:
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

					ID3D11VertexShader* pShader = 0;

					hr = gRHI->GetDevice()->CreateVertexShader(
						pVSBlob->GetBufferPointer(),
						pVSBlob->GetBufferSize(),
						0, &pShader);

					IShader* pVertexShader = new VertexShader;
				}
				break;
			case PIXEL_SHADER:
				break;
		}
	}

}