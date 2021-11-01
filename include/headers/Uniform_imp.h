#ifndef UNIFORM_IMPL_H
#define UNIFORM_IMPL_H

#include "Uniform.h"

#define GenVectors(type, typePrefix,volume)\
struct Vec##volume##typePrefix\
{\
public:\
	type value[volume];\
}

#define GenVectorUniforms(type, typePrefix,volume)\
class UniformVec##volume##typePrefix : Uniform\
{\
public:\
	UniformVec##volume##typePrefix(std::string name, GLint prog) : Uniform(name,prog)\
	{\
	}\
	virtual void SendToShaderProgram()\
	{\
		glUniform##volume##typePrefix##v(_uniformLocation,1,(type*)&value);\
	}\
	void SetValue(Vec##volume##typePrefix val)\
	{\
		value = val;\
	}\
protected:\
	Vec##volume##typePrefix value = {0};\
}


#define INIT_UNIFORM_FOR_VECTOR(type, typePrefix,volume)\
GenVectors(type, typePrefix,volume);\
GenVectorUniforms(type, typePrefix,volume)

namespace GL
{
	namespace Shaders
	{
		INIT_UNIFORM_FOR_VECTOR(GLint, i, 1);
		INIT_UNIFORM_FOR_VECTOR(GLint, i, 2);
		INIT_UNIFORM_FOR_VECTOR(GLint, i, 3);
		INIT_UNIFORM_FOR_VECTOR(GLint, i, 4);

		INIT_UNIFORM_FOR_VECTOR(GLuint, ui, 1);
		INIT_UNIFORM_FOR_VECTOR(GLuint, ui, 2);
		INIT_UNIFORM_FOR_VECTOR(GLuint, ui, 3);
		INIT_UNIFORM_FOR_VECTOR(GLuint, ui, 4);

		INIT_UNIFORM_FOR_VECTOR(GLfloat, f, 1);
		INIT_UNIFORM_FOR_VECTOR(GLfloat, f, 2);
		INIT_UNIFORM_FOR_VECTOR(GLfloat, f, 3);
		INIT_UNIFORM_FOR_VECTOR(GLfloat, f, 4);

		INIT_UNIFORM_FOR_VECTOR(GLdouble, d, 1);
		INIT_UNIFORM_FOR_VECTOR(GLdouble, d, 2);
		INIT_UNIFORM_FOR_VECTOR(GLdouble, d, 3);
		INIT_UNIFORM_FOR_VECTOR(GLdouble, d, 4);
	}
}
#endif