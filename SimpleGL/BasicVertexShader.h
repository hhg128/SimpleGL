#pragma once
#include "VertexShader.h"

namespace SimpleGL
{
	class BasicVertexShader : public VertexShader
	{
	public:
		BasicVertexShader();
		virtual ~BasicVertexShader();

		virtual void Compile() override;

	private:
		ID3D11VertexShader*     m_pVertexShader;
		ID3D11InputLayout*      m_pVertexLayout;
	};

	//REGISTR_VERTEX_SHADER(BasicVertexShader);
}