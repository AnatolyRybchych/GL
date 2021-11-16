#include "../include/headers/ShaderProgram.h"


using std::string;
using std::vector;

namespace GL
{
	namespace Shaders
	{
		ShaderProgram::ShaderProgram() {}
		ShaderProgram::ShaderProgram(GL::Shaders::Shader* shader1) { initShader(shader1); }
		ShaderProgram::ShaderProgram(GL::Shaders::Shader* shader1, GL::Shaders::Shader* shader2) :ShaderProgram(shader1) { initShader(shader2); }
		ShaderProgram::ShaderProgram(GL::Shaders::Shader* shader1, GL::Shaders::Shader* shader2, GL::Shaders::Shader* shader3) :ShaderProgram(shader1, shader2) { initShader(shader3); }
		ShaderProgram::ShaderProgram(GL::Shaders::Shader& shader1) :ShaderProgram(&shader1) {}
		ShaderProgram::ShaderProgram(GL::Shaders::Shader& shader1, GL::Shaders::Shader& shader2) : ShaderProgram(&shader1, &shader2) {}
		ShaderProgram::ShaderProgram(GL::Shaders::Shader& shader1, GL::Shaders::Shader& shader2, GL::Shaders::Shader& shader3) :ShaderProgram(&shader1, &shader2, &shader3) {}

		void ShaderProgram::MessageErrors()
		{
			for (auto el : GetErrors())
			{
				auto str = el;
				MessageBoxA(0, str.c_str(), "Shader program linking error", 0);
			}
		}

		Shader& ShaderProgram::GetVertexShader()
		{
			return _vertex;
		}

		Shader& ShaderProgram::GetFragmentShader()
		{
			return _fragment;
		}

		Shader& ShaderProgram::GetGeometryShader()
		{
			return _geometry;
		}

		bool ShaderProgram::IsOk()
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

		void ShaderProgram::initShader(Shader* shader)
		{

			if (!HdandleIsShaderOkCondition(&_errors,shader))	return;

			if(_isComputeInit)
			{
				_errors.push_back("Error: shader program already contains compute shader\n");
				return;
			}

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
			case COMPUTE:
				if (_isVertexInit || _isFragmentInit || _isGeometryInit)	_errors.push_back("Error: shader program is already init as render shader program\n");
				else _compute = *shader;

				_isComputeInit = true;
				return;
			default:
				HandleShaderIncorrectType(&_errors, shader);
				return;
				break;
			}
		}

		bool HandleIsShaderProgramBuildError(vector<string>* log, ShaderProgram* prog)
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

		void ShaderProgram::Build()
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
			if (_isComputeInit)  glAttachShader(_id, _compute.GetId());

			glLinkProgram(_id);
			if (HandleIsShaderProgramBuildError(&_errors, this))
			{
				glDeleteProgram(_id);
				_id = 0;
			}
		}

		vector<string> ShaderProgram::GetErrors()
		{
			vector<string> res = _errors;
			_errors.clear();
			return res;
		}

		GLuint ShaderProgram::GetId()
		{
			return _id;
		}

		ShaderProgram::~ShaderProgram()
		{
			if (!_id) glDeleteProgram(_id);
		}

		void ShaderProgram::AddUniform(Uniform& uniform)
		{
			_uniforms.push_back(&uniform);
		}

		void ShaderProgram::UniformAll()
		{
			for (auto unif : _uniforms) unif->SendToShaderProgram();
		}
	}
}