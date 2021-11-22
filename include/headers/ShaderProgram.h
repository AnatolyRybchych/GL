#ifndef RENDERSHADERPROGRAM_H
#define RENDERSHADERPROGRAM_H

#include"Shader.h"
#include"Uniform.h"

namespace GL
{
	namespace Shaders
	{

		class ShaderProgram
		{
		public:
			ShaderProgram();
			ShaderProgram(GL::Shaders::Shader* shader1);
			ShaderProgram(GL::Shaders::Shader* shader1, GL::Shaders::Shader* shader2);
			ShaderProgram(GL::Shaders::Shader* shader1, GL::Shaders::Shader* shader2, GL::Shaders::Shader* shader3);
			ShaderProgram(GL::Shaders::Shader& shader1);
			ShaderProgram(GL::Shaders::Shader& shader1, GL::Shaders::Shader& shader2);
			ShaderProgram(GL::Shaders::Shader& shader1, GL::Shaders::Shader& shader2, GL::Shaders::Shader& shader3);
			~ShaderProgram();
			GL::Shaders::Shader& GetVertexShader();
			GL::Shaders::Shader& GetFragmentShader(); 
			GL::Shaders::Shader& GetGeometryShader();
			void MessageErrors();
			void Build();
			//for compute shader program
			void DispatchCompute(int groupsX, int groupsY, int groupsZ);
			bool IsOk();
			std::vector<std::string> GetErrors();
			void Use();
			GLuint GetId();
		protected:
			void initShader(GL::Shaders::Shader* shader);
			bool _isVertexInit = false;
			bool _isFragmentInit = false;
			bool _isGeometryInit = false;
			bool _isComputeInit = false;
			GL::Shaders::Shader _compute;
			GL::Shaders::Shader _vertex;
			GL::Shaders::Shader _geometry;
			GL::Shaders::Shader _fragment;
			std::vector<std::string> _errors;
			GLuint _id = 0;
		};
	}
}
#endif