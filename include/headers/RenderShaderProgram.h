#ifndef RENDERSHADERPROGRAM_H
#define RENDERSHADERPROGRAM_H

#include"Shader.h"
#include"Uniform.h"

namespace GL
{
	namespace Shaders
	{

		class RenderShaderProgram
		{
		public:
			RenderShaderProgram();
			RenderShaderProgram(GL::Shaders::Shader* shader1);
			RenderShaderProgram(GL::Shaders::Shader* shader1, GL::Shaders::Shader* shader2);
			RenderShaderProgram(GL::Shaders::Shader* shader1, GL::Shaders::Shader* shader2, GL::Shaders::Shader* shader3);
			RenderShaderProgram(GL::Shaders::Shader& shader1);
			RenderShaderProgram(GL::Shaders::Shader& shader1, GL::Shaders::Shader& shader2);
			RenderShaderProgram(GL::Shaders::Shader& shader1, GL::Shaders::Shader& shader2, GL::Shaders::Shader& shader3);
			~RenderShaderProgram();
			GL::Shaders::Shader& GetVertexShader();
			GL::Shaders::Shader& GetFragmentShader();
			GL::Shaders::Shader& GetGeometryShader();
			void MessageErrors();
			void Build();
			bool IsOk();
			std::vector<std::string> GetErrors();
			void AddUniform(Uniform& uniform);
			void UniformAll();
			GLuint GetId();
		protected:
			std::vector<Uniform*> _uniforms;
			void initShader(GL::Shaders::Shader* shader);
			bool _isVertexInit = false;
			bool _isFragmentInit = false;
			bool _isGeometryInit = false;
			GL::Shaders::Shader _vertex;
			GL::Shaders::Shader _geometry;
			GL::Shaders::Shader _fragment;
			std::vector<std::string> _errors;
			GLuint _id = 0;
		};
	}
}
#endif