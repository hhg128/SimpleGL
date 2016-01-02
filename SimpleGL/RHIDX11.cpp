#include "stdafx.h"
#include "RHIDX11.h"
#include "WindowsWindow.h"

// Library imports
#pragma comment( lib, "d3d11.lib" )
#pragma comment( lib, "DXGI.lib" )

namespace SimpleGL
{
	using namespace Microsoft::WRL;

	RHIDX11::RHIDX11()
	{
	}


	RHIDX11::~RHIDX11()
	{
	}

	void RHIDX11::Initialize(WindowsWindow* pWindow)
	{
		m_pWindow = pWindow;

		CreateDevice();
		CreateSwapChain();
		CreateRenderTargetView();
		CreateDepthStencilView();
		ApplyRenderTargetView();
		ClearRenterTargetView();
		SetViewport();
	}

	void RHIDX11::Finalize()
	{

	}

	void RHIDX11::CreateDevice()
	{
		HRESULT hr = S_OK;
		
		UINT CreateDeviceFlags = 0;
		D3D_FEATURE_LEVEL CreatedLevel;

		hr = D3D11CreateDevice( nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, CreateDeviceFlags, nullptr, 0, 
			D3D11_SDK_VERSION, &m_Device, &CreatedLevel, &m_DeviceContext);

		if (FAILED(hr))
		{
			assert(hr);
		}
	}

	void RHIDX11::CreateSwapChain()
	{
		
		ComPtr<IDXGIDevice> dxgiDevice;
		m_Device.CopyTo(dxgiDevice.GetAddressOf());
		//m_Device.As(&dxgiDevice);

		ComPtr<IDXGIAdapter> dxgiAdapter;
		dxgiDevice->GetParent(__uuidof(IDXGIAdapter), reinterpret_cast<void **>(dxgiAdapter.GetAddressOf()));
		//dxgiDevice->GetAdapter(&dxgiAdapter);

		ComPtr<IDXGIFactory> dxgiFactory;
		dxgiAdapter->GetParent(__uuidof(IDXGIFactory), reinterpret_cast<void **>(dxgiFactory.GetAddressOf()));
		//dxgiAdapter->GetParent(__uuidof(IDXGIFactory), &dxgiFactory);

		RECT rect;
		GetClientRect(m_pWindow->GetHwnd(), &rect);

		DXGI_SWAP_CHAIN_DESC SwapChainDesc;
		SwapChainDesc.BufferDesc.Width = rect.right - rect.left;
		SwapChainDesc.BufferDesc.Height = rect.bottom - rect.top;
		SwapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
		SwapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		SwapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		SwapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
		SwapChainDesc.BufferDesc.RefreshRate.Denominator = 1;

		SwapChainDesc.SampleDesc.Count = 1;
		SwapChainDesc.SampleDesc.Quality = 0;

		SwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		SwapChainDesc.BufferCount = 2;
		SwapChainDesc.OutputWindow = m_pWindow->GetHwnd();
		SwapChainDesc.Windowed = true;
		SwapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		SwapChainDesc.Flags = 0;

		HRESULT hr = S_OK;
		hr = dxgiFactory->CreateSwapChain(m_Device.Get(), &SwapChainDesc, m_SwapChain.GetAddressOf());
	}

	void RHIDX11::SetViewport()
	{
		RECT rect;
		GetClientRect(m_pWindow->GetHwnd(), &rect);

		D3D11_VIEWPORT vp;
		vp.Width = static_cast<FLOAT>(rect.right - rect.left);
		vp.Height = static_cast<FLOAT>(rect.bottom - rect.top);
		vp.MinDepth = 0.0f;
		vp.MaxDepth = 1.0f;
		vp.TopLeftX = 0;
		vp.TopLeftY = 0;
		m_DeviceContext->RSSetViewports(1, &vp);
	}

	void RHIDX11::ApplyRenderTargetView()
	{
		m_DeviceContext->OMSetRenderTargets(1, &m_pRenderTargetView, m_pDepthStencilView);
	}

	void RHIDX11::ClearRenterTargetView()
	{
		m_DeviceContext->ClearRenderTargetView(m_pRenderTargetView, DirectX::Colors::MidnightBlue);
		m_DeviceContext->ClearDepthStencilView(m_pDepthStencilView, D3D11_CLEAR_DEPTH, 1.0f, 0);
	}

	void RHIDX11::Present()
	{
		UINT SyncInterval = 0;
		UINT PresentFlags = 0;

		m_SwapChain->Present(SyncInterval, PresentFlags);
	}

	void RHIDX11::CreateVertexBuffer()
	{

	}

	void RHIDX11::CreateIndexBuffer()
	{

	}

	void RHIDX11::CreateRenderTargetView()
	{
		HRESULT hr = S_OK;

		ComPtr<ID3D11Texture2D> BackBuffer;
		hr = m_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void **>(BackBuffer.GetAddressOf()));
		if (FAILED(hr))
		{
			assert(hr);
		}

		hr = m_Device->CreateRenderTargetView(BackBuffer.Get(), nullptr, &m_pRenderTargetView);
		if (FAILED(hr))
		{
			assert(hr);
		}
	}

	void RHIDX11::CreateDepthStencilView()
	{
		HRESULT hr = S_OK;

		RECT rect;
		GetClientRect(m_pWindow->GetHwnd(), &rect);

		D3D11_TEXTURE2D_DESC descDepth;
		ZeroMemory(&descDepth, sizeof(descDepth));
		descDepth.Width = rect.right - rect.left;
		descDepth.Height = rect.bottom - rect.top;
		descDepth.MipLevels = 1;
		descDepth.ArraySize = 1;
		descDepth.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
		descDepth.SampleDesc.Count = 1;
		descDepth.SampleDesc.Quality = 0;
		descDepth.Usage = D3D11_USAGE_DEFAULT;
		descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
		descDepth.CPUAccessFlags = 0;
		descDepth.MiscFlags = 0;

		ID3D11Texture2D* g_pDepthStencil;
		hr = m_Device->CreateTexture2D(&descDepth, nullptr, &g_pDepthStencil);
		if (FAILED(hr))
		{
			assert(hr);
		}

		D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
		ZeroMemory(&descDSV, sizeof(descDSV));
		descDSV.Format = descDepth.Format;
		descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
		descDSV.Texture2D.MipSlice = 0;

		hr = m_Device->CreateDepthStencilView(g_pDepthStencil, &descDSV, &m_pDepthStencilView);
		if (FAILED(hr))
		{
			assert(hr);
		}
	}

}