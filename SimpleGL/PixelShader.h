#pragma once
#include "IShader.h"
#include "ShaderGenerator.h"

namespace SimpleGL
{
	class PixelShader : public IShader
	{
	public:
		PixelShader();
		virtual ~PixelShader();

		virtual std::wstring GetShaderName() override {
			return shaderName;
		}

		virtual ShaderType GetShaderType() override {
			return VERTEX_SHADER;
		}

	private:
		std::wstring  shaderName;
	};
}