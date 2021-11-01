#include"../include/headers/Uniform.h"

namespace GL
{
	namespace Shaders
	{
		Uniform::Uniform(std::string name, GLint progId)
		{
			_uniformLocation = glGetUniformLocation(progId, name.c_str());
		}
	}
}