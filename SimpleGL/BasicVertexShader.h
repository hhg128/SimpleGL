#pragma once
#include "VertexShader.h"

namespace SimpleGL
{
	class BasicVertexShader : public VertexShader
	{
	public:
		BasicVertexShader();
		virtual ~BasicVertexShader();
	};

	REGISTR_VERTEX_SHADER(BasicVertexShader);
}