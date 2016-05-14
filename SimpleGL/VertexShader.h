#pragma once
#include "IShader.h"
#include "ShaderGenerator.h"

namespace SimpleGL
{
	using namespace Microsoft::WRL;
	class VertexShader : public IShader
	{
	public:
		VertexShader(ID3D11VertexShader* pShader);
		virtual ~VertexShader();

		virtual void Compile();

		virtual std::wstring GetShaderName() override {
			return shaderName;
		}

		virtual ShaderType GetShaderType() override {
			return VERTEX_SHADER;
		}

	private:
		ComPtr<ID3D11VertexShader>     m_VertexShader;
		std::wstring  shaderName;
	};
}