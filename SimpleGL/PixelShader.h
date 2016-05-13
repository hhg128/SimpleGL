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

		virtual void Compile() {};
	};
}