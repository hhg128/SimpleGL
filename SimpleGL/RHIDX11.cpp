#include "stdafx.h"
#include "RHIDX11.h"

// Library imports
#pragma comment( lib, "d3d11.lib" )
#pragma comment( lib, "DXGI.lib" )

namespace SimpleGL
{
	RHIDX11::RHIDX11()
	{
	}


	RHIDX11::~RHIDX11()
	{
	}

	bool RHIDX11::Initialize()
	{
		CreateDevice();

		CreateSwapChain();

		return true;
	}

	void RHIDX11::Finalize()
	{

	}

	void RHIDX11::CreateDevice()
	{
		UINT CreateDeviceFlags = 0;
		D3D_FEATURE_LEVEL CreatedLevel;

		D3D11CreateDevice(
			nullptr,
			D3D_DRIVER_TYPE_HARDWARE,
			nullptr,
			CreateDeviceFlags,
			nullptr,
			0,
			D3D11_SDK_VERSION,
			&m_Device,
			&CreatedLevel,
			&m_DeviceContext);
	}

	void RHIDX11::CreateSwapChain()
	{
		using namespace Microsoft::WRL;
		ComPtr<IDXGIDevice> dxgiDevice;
		m_DeviceContext.As(&dxgiDevice);

		ComPtr<IDXGIAdapter> dxgiAdapter;
		dxgiDevice->GetAdapter(&dxgiAdapter);

		ComPtr<IDXGIFactory> dxgiFactory;
		dxgiAdapter->GetParent(__uuidof(IDXGIFactory), &dxgiFactory);


		DXGI_SWAP_CHAIN_DESC SwapChainDesc;
		SwapChainDesc.BufferDesc.Width = 1;
		SwapChainDesc.BufferDesc.Height = 1;
		SwapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
		SwapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		SwapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		SwapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
		SwapChainDesc.BufferDesc.RefreshRate.Denominator = 1;

		SwapChainDesc.SampleDesc.Count = 1;
		SwapChainDesc.SampleDesc.Quality = 0;

		SwapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		SwapChainDesc.BufferCount = 2;
		SwapChainDesc.OutputWindow = 0;
		SwapChainDesc.Windowed = true;
		SwapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		SwapChainDesc.Flags = 0;

		dxgiFactory->CreateSwapChain(m_Device.Get(), &SwapChainDesc, m_SwapChain.GetAddressOf());
	}

}