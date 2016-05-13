#pragma once

namespace SimpleGL
{
	enum ShaderType
	{
		VERTEX_SHADER = 0,
		PIXEL_SHADER = 1,
	};

	class IShader
	{
	public:
		IShader();
		virtual ~IShader();

		virtual ShaderType		GetShaderType() = 0;
		virtual std::wstring	GetShaderName() = 0;
	};
}