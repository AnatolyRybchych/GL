#ifndef SHADER_H
#define SHADER_H

#include<fstream>
#include<vector>
#include<string>
#include<map>

#include"Enums/ShaderType.h"


namespace GL
{
	namespace Shaders
	{
		std::string ReadAllTextFromFile(std::string path);

		//#version 450
		class Shader
		{
		public:
			Shader();
			Shader(std::string path, GL::Shaders::ShaderType type);
			Shader(char* text, GL::Shaders::ShaderType type);
			void MessageErrors();
			GL::Shaders::ShaderType GetType();
			bool IsOk();
			GLuint GetId();
			std::vector<std::string> GetErrors();
			~Shader();
		protected:
			GLuint _id = 0;
			std::vector<std::string> _errors;
			ShaderType _type;
		};
	}
}
#endif