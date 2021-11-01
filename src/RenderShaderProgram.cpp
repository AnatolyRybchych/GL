#include "../include/headers/RenderShaderProgram.h"


using std::string;
using std::vector;

namespace GL
{
	namespace Shaders
	{
		RenderShaderProgram::RenderShaderProgram() {}
		RenderShaderProgram::RenderShaderProgram(GL::Shaders::Shader* shader1) { initShader(shader1); }
		RenderShaderProgram::RenderShaderProgram(GL::Shaders::Shader* shader1, GL::Shaders::Shader* shader2) :RenderShaderProgram(shader1) { initShader(shader2); }
		RenderShaderProgram::RenderShaderProgram(GL::Shaders::Shader* shader1, GL::Shaders::Shader* shader2, GL::Shaders::Shader* shader3) :RenderShaderProgram(shader1, shader2) { initShader(shader3); }
		RenderShaderProgram::RenderShaderProgram(GL::Shaders::Shader& shader1) :RenderShaderProgram(&shader1) {}
		RenderShaderProgram::RenderShaderProgram(GL::Shaders::Shader& shader1, GL::Shaders::Shader& shader2) : RenderShaderProgram(&shader1, &shader2) {}
		RenderShaderProgram::RenderShaderProgram(GL::Shaders::Shader& shader1, GL::Shaders::Shader& shader2, GL::Shaders::Shader& shader3) :RenderShaderProgram(&shader1, &shader2, &shader3) {}

		void RenderShaderProgram::MessageErrors()
		{
			for (auto el : GetErrors())
			{
				auto str = el;
				MessageBox(0, str.c_str(), "Shader program linking error", 0);
			}
		}

		Shader& RenderShaderProgram::GetVertexShader()
		{
			return _vertex;
		}

		Shader& RenderShaderProgram::GetFragmentShader()
		{
			return _fragment;
		}

		Shader& RenderShaderProgram::GetGeometryShader()
		{
			return _geometry;
		}

		bool RenderShaderProgram::IsOk()
		{
			return _id != 0;
		}

		bool HdandleIsShaderOkCondition(vector<string>* log, Shader*shader)
		{
			if(shader->IsOk() == false)
			{
				log->push_back("Error bad Shader: shader has id == 0:");
				return false;
			}
			return true;
		}

		void HandleIsShaderInitCase(vector<string> *log,Shader* shader)
		{
			log->push_back(
				string("Error Shader Type: same is already in programm. type:" + 
					std::to_string(shader->GetType())
				));
		}

		void HandleShaderIncorrectType(vector<string>* log, Shader* shader)
		{
			log->push_back(
				string("Error Shader Type: same is already in programm. type:" + 
					std::to_string(shader->GetType())
				));
		}

		void RenderShaderProgram::initShader(Shader* shader)
		{

			if (!HdandleIsShaderOkCondition(&_errors,shader))	return;
		
			switch (shader->GetType())
			{
			case FRAGMENT:
				if (_isFragmentInit)	HandleIsShaderInitCase(&_errors, shader);
				else _fragment = *shader;

				_isFragmentInit = true;
				return;
			case GEOMETRY:
				if (_isGeometryInit)	HandleIsShaderInitCase(&_errors, shader);
				else _geometry = *shader;

				_isGeometryInit = true;
				return;
			case VERTEX:
				if (_isVertexInit)	HandleIsShaderInitCase(&_errors, shader);
				else _vertex = *shader;

				_isVertexInit = true;
				return;
			default:
				HandleShaderIncorrectType(&_errors, shader);
				return;
				break;
			}
		}

		bool HandleIsShaderProgramBuildError(vector<string>* log, RenderShaderProgram* prog)
		{
			bool isError = false;
			char* buffer;
			const int bufferSize = 10000;
			GLint ok = 0;

			glGetProgramiv(prog->GetId(), GL_LINK_STATUS, &ok);
			if (!ok)
			{
				buffer = new char[bufferSize];
				ZeroMemory(buffer, bufferSize);
				glGetProgramInfoLog(prog->GetId(), bufferSize, 0, buffer);
				glDeleteProgram(prog->GetId());
				isError = true;
				log->push_back(string("glLinkProgram Error:\n") + buffer);
				delete[] buffer;
			}
			return isError;
		}

		void RenderShaderProgram::Build()
		{
			_id = _isVertexInit || _isGeometryInit || _isFragmentInit ? glCreateProgram() : 0;
			if (!_id)
			{
				_errors.push_back(string("there are 0 shaders satisfy the condition"));
				return;
			}

			if (_isVertexInit)	glAttachShader(_id, _vertex.GetId());
			if (_isGeometryInit)  glAttachShader(_id, _geometry.GetId());
			if (_isFragmentInit)  glAttachShader(_id, _fragment.GetId());

			glLinkProgram(_id);
			if (HandleIsShaderProgramBuildError(&_errors, this))
			{
				glDeleteProgram(_id);
				_id = 0;
			}
		}

		vector<string> RenderShaderProgram::GetErrors()
		{
			vector<string> res = _errors;
			_errors.clear();
			return res;
		}

		GLuint RenderShaderProgram::GetId()
		{
			return _id;
		}

		RenderShaderProgram::~RenderShaderProgram()
		{
			if (!_id) glDeleteProgram(_id);
		}

		void RenderShaderProgram::AddUniform(Uniform& uniform)
		{
			_uniforms.push_back(&uniform);
		}

		void RenderShaderProgram::UniformAll()
		{
			for (auto unif : _uniforms) unif->SendToShaderProgram();
		}
	}
}