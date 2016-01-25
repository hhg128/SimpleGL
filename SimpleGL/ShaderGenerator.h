#pragma once
#include "ShaderEnum.h"

namespace SimpleGL
{
	class VertexShader;
	class PixelShader;

	class ShaderGenerator
	{
	public:
		ShaderGenerator();
		~ShaderGenerator();

		void Initialize();

		static void RegisterVertexShader(TCHAR* name, VertexShader* pVertexShader, ShaderEnum id);

	private:		
		struct VertexShaderItem
		{	
			TCHAR* name;
			VertexShader* vertexshader;
		};
		static VertexShaderItem VertexShaderMap[ShaderEnum_Max];
	};

	extern ShaderGenerator* gShaderGenerator;

	template<typename type>
	class ShaderRegisterClass
	{
	public:
		ShaderRegisterClass(TCHAR* name, ShaderEnum id)
		{
			type* vertexShader = new type;
			ShaderGenerator::RegisterVertexShader(name, vertexShader, id);
		}
	};

#define REGISTR_VERTEX_SHADER(type)\
	ShaderRegisterClass<type> _shader_register_##type(TEXT(#type), ShaderEnum::##type);
}