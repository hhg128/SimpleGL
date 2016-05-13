#pragma once
#include "PixelShader.h"

namespace SimpleGL
{
	class BasicPixelShader : public PixelShader
	{
	public:
		BasicPixelShader();
		virtual ~BasicPixelShader();

		virtual void Compile() override;
	};

	//REGISTR_PIXEL_SHADER(BasicPixelShader);
}