#pragma once

namespace SimpleGL
{
	class ResourceView
	{
	public:
		ResourceView();
		virtual ~ResourceView();
	};

	class RenderTargetView : public ResourceView
	{
	public:
		RenderTargetView();
		virtual ~RenderTargetView();
	};

	class DepthStencilView : public ResourceView
	{
	public:
		DepthStencilView();
		virtual ~DepthStencilView();
	};

	class UnorderedAccessView : public ResourceView
	{
	public:
		UnorderedAccessView();
		virtual ~UnorderedAccessView();
	};

	class ShaderResourceView : public ResourceView
	{
	public:
		ShaderResourceView();
		virtual ~ShaderResourceView();
	};

}