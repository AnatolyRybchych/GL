#include"../include/headers/Shader.h"

using std::string;
using std::vector;

namespace GL
{
	namespace Shaders
	{
		Shader::Shader() 
		{ 
			_type = None; 
		};

		//moves file cursor to the start of file
		int GetFileSize(std::ifstream* fs)
		{
			int res;
			fs->seekg(0, std::ios_base::end);
			res = fs->tellg();
			fs->seekg(0, std::ios_base::beg);
			return res;
		}

		string ReadFromFile(std::ifstream* fs, int count)
		{
			string result;
			char* text;

			text = new char[count+1];
			ZeroMemory(text, count+1);
			fs->read(text, count);
			result = text;
			delete[] text;
			return result;
		}

		string ReadAllTextFromFile(string path)
		{
			string res;
			std::ifstream fs(path);
			int fileSize = GetFileSize(&fs);

			if (fileSize == -1)
			{
				fs.close();
				return "";
			}
			res = ReadFromFile(&fs, fileSize);
			fs.close();

			return res;
		}

		bool HandleShaderCompileIsError(vector<string>* log, Shader* shader)
		{
			const int bufferSize = 10000;
			bool res = false;
			int ok = 0;

			glGetShaderiv(shader->GetId(), GL_COMPILE_STATUS, &ok);
			if (!ok)
			{
				char* buffer = new char[bufferSize];
				ZeroMemory(buffer, bufferSize);
				glGetShaderInfoLog(shader->GetId(), bufferSize, 0, buffer);
				log->push_back(string("glCreateShader Error:\n") + buffer);
				res = true;
				delete[] buffer;
			}
			return res;
		}

		bool HandleShaderCreateIsError(vector<string>* log, Shader* shader)
		{
			bool res = false;
			if (shader->GetId() == 0)
			{
				log->push_back(
					string("glCreateShader Error: ShaderType=") +
					std::to_string((int)shader->GetType())
				);
				res = true;
			}
			return res;
		}

		Shader::Shader(GL::Shaders::ShaderType type, std::string text)
		{
			_type = type;
			_id = glCreateShader(type);
			if (HandleShaderCreateIsError(&_errors, this)) return;

			char* txt = const_cast<char*>(text.c_str());
			glShaderSource(_id, 1, &txt, NULL);
			glCompileShader(_id);

			if (HandleShaderCompileIsError(&_errors, this))
			{
				glDeleteShader(_id);
				_id = 0;
			}
		}

		Shader::Shader(string path, ShaderType type)
		{
			_type = type;
			_id = glCreateShader(type);
			if (HandleShaderCreateIsError(&_errors,this)) return;


			string shaderText = ReadAllTextFromFile(path);
			char* shaderText_c = const_cast<char*>(shaderText.c_str());
			glShaderSource(_id, 1, &shaderText_c, NULL);
			glCompileShader(_id);

			if (HandleShaderCompileIsError(&_errors, this))
			{
				glDeleteShader(_id);
				_id = 0;
			}
		}

		GLuint Shader::GetId()
		{
			return _id;
		}

		Shader::~Shader()
		{
			if (!_id) glDeleteShader(_id);
		}

		vector<std::string> Shader::GetErrors()
		{
			auto res = _errors;
			_errors.clear();
			return res;
		}

		bool Shader::IsOk()
		{
			return _id != 0;
		}

		ShaderType Shader::GetType()
		{
			return _type;
		}

		void Shader::MessageErrors()
		{
			for (auto el : GetErrors())
			{
				auto str = el;
				MessageBoxA(0, str.c_str(), _type == GEOMETRY?"Geometry shader error":_type == FRAGMENT? "Fragment shader error":"Vertex shader error", 0);
			}
		}

	}
}



