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

		Microsoft::WRL::ComPtr<ID3D11Device>&	GetDevice() { return m_Device; }
		Microsoft::WRL::ComPtr<ID3D11DeviceContext>& GetDeviceContext() { return m_DeviceContext; }

		ID3D11VertexShader* GetVertexShader() { return m_pVertexShader; }
		ID3D11PixelShader* GetPixelShader() { return m_pPixelShader; }

		void GetWindowSize(int& width, int& height);

		void Present();

		static void Create();

		void CreateVertexShader(D3D11_INPUT_ELEMENT_DESC* pLayout, UINT numElements);
		void CreatePixelShader();
		void CreateRenderTargetView();
		void CreateDepthStencilView();
		void CreateVertexBuffer();
		void CreateIndexBuffer();

		void ClearRenterTargetView();

		void Draw();

	protected:
		void CreateDevice();
		void CreateSwapChain();

		void SetViewport();
		void ApplyRenderTargetView();

		HRESULT CompileShaderFromFile(WCHAR* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut);

	protected:
		Microsoft::WRL::ComPtr<ID3D11Device>	m_Device;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext>	m_DeviceContext;
		Microsoft::WRL::ComPtr<IDXGISwapChain>	m_SwapChain;

		ID3D11RenderTargetView* m_pRenderTargetView;
		ID3D11DepthStencilView* m_pDepthStencilView;
		ID3D11VertexShader*     m_pVertexShader;
		ID3D11PixelShader*      m_pPixelShader;
		ID3D11InputLayout*      m_pVertexLayout;

		WindowsWindow*	m_pWindow;
	};

	extern RHIDX11* gRHI;
}
