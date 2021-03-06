#include "stdafx.h"
#include "ShaderGenerator.h"
#include "VertexShader.h"

namespace SimpleGL
{
	ShaderGenerator* gShaderGenerator = nullptr;
	ShaderGenerator::VertexShaderItem ShaderGenerator::VertexShaderMap[ShaderEnum_Max];
	ShaderGenerator::PixelShaderItem ShaderGenerator::PixelShaderMap[ShaderEnum_Max];

	ShaderGenerator::ShaderGenerator()
	{
	}


	ShaderGenerator::~ShaderGenerator()
	{
	}

	void ShaderGenerator::Initialize()
	{
		for (auto shader : VertexShaderMap)
		{
			shader.vertexshader->Compile();
		}
	}

	void ShaderGenerator::RegisterVertexShader(TCHAR* name, VertexShader* pVertexShader, ShaderEnum id)
	{
		VertexShaderItem item{name, pVertexShader};
		VertexShaderMap[id] = item;
	}

	void ShaderGenerator::RegisterPixelShader(TCHAR* name, PixelShader* pVertexShader, ShaderEnum id)
	{
		PixelShaderItem item{ name, pVertexShader };
		PixelShaderMap[id] = item;
	}

}