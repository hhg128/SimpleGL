#pragma once

namespace SimpleGL
{
	using namespace DirectX;

	class ConstantBufferBase
	{
	public:
		ConstantBufferBase() {}
		virtual ~ConstantBufferBase() {}

		struct Data
		{
		} data;
	};

	class CBNeverChanges : public ConstantBufferBase
	{
	public:
		struct Data
		{
			XMMATRIX mView;
			XMMATRIX mProjection;
			XMMATRIX mWorld;
		} data;
	};

	class ConstantBufferStruct : public ConstantBufferBase
	{
	public:
		struct Data
		{
			XMFLOAT4 vMeshColor;
		} data;
	};
}