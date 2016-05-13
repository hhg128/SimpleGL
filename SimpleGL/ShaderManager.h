#pragma once
#include "IShader.h"

namespace SimpleGL
{
	class CShaderManager
	{
	public:
		CShaderManager();
		~CShaderManager();

		void LoadShader(const std::wstring& fileName, ShaderType shaderType);

	private:
		std::vector<IShader*>	m_vShaders;
	};
}