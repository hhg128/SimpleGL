#pragma once

namespace SimpleGL
{
	class WindowsWindow;

	class RHIDX11
	{
	public:
		RHIDX11();
		~RHIDX11();

		void Initialize(WindowsWindow* pWindow);
		void Finalize();

		void Present();

		void CreateVertexBuffer();
		void CreateIndexBuffer();
		void CreateRenderTargetView();
		void CreateDepthStencilView();

	protected:
		void CreateDevice();
		void CreateSwapChain();

		void SetViewport();
		void ApplyRenderTargetView();
		void ClearRenterTargetView();

	protected:
		Microsoft::WRL::ComPtr<ID3D11Device>	m_Device;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext>	m_DeviceContext;
		Microsoft::WRL::ComPtr<IDXGISwapChain>	m_SwapChain;

		ID3D11RenderTargetView* m_pRenderTargetView;
		ID3D11DepthStencilView* m_pDepthStencilView;

		WindowsWindow*	m_pWindow;
	};
}
