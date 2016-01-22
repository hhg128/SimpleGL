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

		void RegisterVertexShader(TCHAR* name, VertexShader* pVertexShader);

	private:
		std::map<TCHAR*, VertexShader*> VertexShaderMap;
	};

	extern ShaderGenerator* gShaderGenerator;

#define REGISTR_VERTEX_SHADER(name, type)\
	class ShaderRegisterClass_##name\
	{\
		public:\
			ShaderRegisterClass_##name()\
			{\
				type* vertexshader = new type;\
				TCHAR* vertexname = TEXT(#name);\
				gShaderGenerator->RegisterVertexShader(vertexname, vertexshader);\
			}\
	};\
	static ShaderRegisterClass_##name registershader;
}