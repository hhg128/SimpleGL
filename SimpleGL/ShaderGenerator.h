#pragma once

namespace SimpleGL
{
	class VertexShader;
	class PixelShader;

	class ShaderGenerator
	{
	public:
		ShaderGenerator();
		~ShaderGenerator();

		static void RegisterVertexShader(TCHAR* name, VertexShader* pVertexShader);

	private:
		std::map<TCHAR*, VertexShader*> VertexShaderMap;
	};

	extern ShaderGenerator* gShaderGenerator;

	template<typename type>
	class ShaderRegisterClass
	{
	public:
		ShaderRegisterClass(TCHAR* name)
		{
			type* vertexShader = new type;
			ShaderGenerator::RegisterVertexShader(name, vertexShader);
		}
	};

#define REGISTR_VERTEX_SHADER(type)\
	ShaderRegisterClass<type> _shader_register_##type(TEXT(#type));
}