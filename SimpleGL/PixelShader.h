#pragma once
#include "ShaderBase.h"
#include "ShaderGenerator.h"

namespace SimpleGL
{
	class PixelShader : public ShaderBase
	{
	public:
		PixelShader();
		virtual ~PixelShader();

		virtual void Compile() {};
	};
}