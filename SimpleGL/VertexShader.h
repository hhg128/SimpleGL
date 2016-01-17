#pragma once
#include "ShaderBase.h"

namespace SimpleGL
{
	using namespace Microsoft::WRL;
	class VertexShader : public ShaderBase
	{
	public:
		VertexShader();
		virtual ~VertexShader();

		void Init();

	private:
		ComPtr<ID3D11VertexShader>     m_VertexShader;
	};
}