#ifndef UNIFORM_H
#define UNIFORM_H

#include<string>
#include "opengl.h"

namespace GL
{
	namespace Shaders
	{
		class Uniform
		{
		public:
			Uniform(std::string name, GLint progId);
			virtual void SendToShaderProgram() = 0;
		protected:
			GLint _uniformLocation;
		};
	}
}
#endif


