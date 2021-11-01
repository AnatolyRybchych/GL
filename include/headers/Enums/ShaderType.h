#ifndef SHADERTYPE_H
#define SHADERTYPE_H

#include"../opengl.h"

namespace GL
{
	namespace Shaders
	{
		enum ShaderType
		{
			None = 0,
			VERTEX = GL_VERTEX_SHADER,
			GEOMETRY = GL_GEOMETRY_SHADER,
			FRAGMENT = GL_FRAGMENT_SHADER,
			COMPUTE = GL_COMPUTE_SHADER,
		};
	}
}
#endif