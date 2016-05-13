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
		static void RegisterPixelShader(TCHAR* name, PixelShader* pVertexShader, ShaderEnum id);

	private:		
		struct VertexShaderItem
		{	
			TCHAR* name;
			VertexShader* vertexshader;
		};
		static VertexShaderItem VertexShaderMap[ShaderEnum_Max];

		struct PixelShaderItem
		{
			TCHAR* name;
			PixelShader* pixelshader;
		};
		static PixelShaderItem PixelShaderMap[ShaderEnum_Max];
	};

//	extern ShaderGenerator* gShaderGenerator;
//
//	template<typename type>
//	class VShaderRegisterClass
//	{
//	public:
//		VShaderRegisterClass(TCHAR* name, ShaderEnum id)
//		{
//			type* vertexShader = new type;
//			ShaderGenerator::RegisterVertexShader(name, vertexShader, id);
//		}
//	};
//
//	template<typename type>
//	class PShaderRegisterClass
//	{
//	public:
//		PShaderRegisterClass(TCHAR* name, ShaderEnum id)
//		{
//			type* vertexShader = new type;
//			ShaderGenerator::RegisterPixelShader(name, vertexShader, id);
//		}
//	};
//
//#define REGISTR_VERTEX_SHADER(type)\
//	VShaderRegisterClass<type> _shader_register_##type(TEXT(#type), ShaderEnum::##type);
//
//#define REGISTR_PIXEL_SHADER(type)\
//	PShaderRegisterClass<type> _shader_register_##type(TEXT(#type), ShaderEnum::##type);
}