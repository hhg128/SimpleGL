#pragma once

namespace SimpleGL
{
	class RenderStateDX11;

	class RenderExecutor
	{
	public:
		RenderExecutor();
		~RenderExecutor();
		
		static void Execute(RenderStateDX11* pRenderState);
	};
}