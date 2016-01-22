#include "stdafx.h"
#include "ShaderGenerator.h"

namespace SimpleGL
{
	ShaderGenerator* gShaderGenerator = nullptr;

	ShaderGenerator::ShaderGenerator()
	{
	}


	ShaderGenerator::~ShaderGenerator()
	{
	}

	void ShaderGenerator::RegisterVertexShader(TCHAR* name, VertexShader* pVertexShader)
	{
		//VertexShaderMap[name] = pVertexShader;
	}

}