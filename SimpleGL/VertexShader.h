#pragma once
#include "ShaderBase.h"
#include "ShaderGenerator.h"

namespace SimpleGL
{
	using namespace Microsoft::WRL;
	class VertexShader : public ShaderBase
	{
	public:
		VertexShader();
		virtual ~VertexShader();

	private:
		ComPtr<ID3D11VertexShader>     m_VertexShader;
	};
}