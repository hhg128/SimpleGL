#pragma once
#include "VertexShader.h"

namespace SimpleGL
{
	class BasicVertexShader : public VertexShader
	{
	public:
		BasicVertexShader();
		virtual ~BasicVertexShader();

		void Register();
	};

	REGISTR_VERTEX_SHADER(BasicVertexShader);
}