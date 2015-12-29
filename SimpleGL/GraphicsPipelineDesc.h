#pragma once

namespace SimpleGL
{
	class VertexShader;
	class PixelShader;

	class GraphicsPipelineDesc
	{
	public:
		GraphicsPipelineDesc();
		~GraphicsPipelineDesc();

	private:
		VertexShader*		m_pVertexShader = nullptr;
		PixelShader*		m_pPixelShader	= nullptr;
	};
}