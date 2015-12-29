#pragma once

namespace SimpleGL
{
	class RHIDX11
	{
	public:
		RHIDX11();
		~RHIDX11();

		bool Initialize();
		void Finalize();

	protected:
		void CreateDevice();
		void CreateSwapChain();

	protected:
		Microsoft::WRL::ComPtr<ID3D11Device>	m_Device;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext>	m_DeviceContext;
		Microsoft::WRL::ComPtr<IDXGISwapChain>	m_SwapChain;
	};
}
