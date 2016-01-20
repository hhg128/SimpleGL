#pragma once

namespace SimpleGL
{
	class RenderStateDX11;

	class RenderExecutor
	{
	public:
		RenderExecutor();
		~RenderExecutor();
		
		void Execute(RenderStateDX11* pRenderState);
	};
}