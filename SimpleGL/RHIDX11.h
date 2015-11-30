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
		Microsoft::WRL::ComPtr<ID3D11Device>	m_pDevice;
	};
}
