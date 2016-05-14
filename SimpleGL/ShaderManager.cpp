#include "stdafx.h"
#include "ShaderManager.h"
#include "VertexShader.h"
#include "PixelShader.h"
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
		IShader* pIShader;

		switch (shaderType)
		{
			case VERTEX_SHADER:
				{
					HRESULT hr = S_OK;

					ID3DBlob* pVSBlob = nullptr;
					hr = gRHI->CompileShaderFromFile(fileName.c_str(), TEXT("VS"), TEXT("vs_4_0"), &pVSBlob);
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

					pIShader = new VertexShader(pShader);
				}
				break;
			case PIXEL_SHADER:
				{
					HRESULT hr = S_OK;

					ID3DBlob* pPSBlob = nullptr;
					hr = gRHI->CompileShaderFromFile(fileName.c_str(), TEXT("PS"), TEXT("ps_4_0"), &pPSBlob);
					if (FAILED(hr))
					{
						MessageBox(nullptr,
							TEXT("The hlsl file cannot be compiled."), TEXT("Error"), MB_OK);
						return;
					}

					ID3D11PixelShader* pShader = 0;

					hr = gRHI->GetDevice()->CreatePixelShader(
						pPSBlob->GetBufferPointer(),
						pPSBlob->GetBufferSize(),
						0, &pShader);

					pIShader = new PixelShader;
				}
				break;
		}

		m_vShaders.push_back(pIShader);
	}

}