#ifndef UNIFORM_IMPL_H
#define UNIFORM_IMPL_H

#include "Uniform.h"

#define GenVector(type, typePrefix,volume)\
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

#define GenMatrix(type, typePrefix,volumeX,volumeY)\
struct Mat##volumeX##x##volumeY##typePrefix\
{\
public:\
	type value[volumeX][volumeY];\
}


#define GenMatrixUniforms(type, typePrefix,volumeX,volumeY)\
class UniformMat##volumeX##x##volumeY##typePrefix : Uniform\
{\
public:\
	UniformMat##volumeX##x##volumeY##typePrefix(std::string name, GLint prog) : Uniform(name,prog)\
	{\
	}\
	virtual void SendToShaderProgram()\
	{\
		glUniformMatrix##volumeX##x##volumeY##typePrefix##v(_uniformLocation,1,false,(type*)&value);\
	}\
	void SetValue(Mat##volumeX##x##volumeY##typePrefix val)\
	{\
		value = val;\
	}\
protected:\
	Mat##volumeX##x##volumeY##typePrefix value = {0};\
}

#define GenSquareMatrixUniforms(type, typePrefix,volume)\
class UniformMat##volume##x##volume##typePrefix : Uniform\
{\
public:\
	UniformMat##volume##x##volume##typePrefix(std::string name, GLint prog) : Uniform(name,prog)\
	{\
	}\
	virtual void SendToShaderProgram()\
	{\
		glUniformMatrix##volume##typePrefix##v(_uniformLocation,1,false,(type*)&value);\
	}\
	void SetValue(Mat##volume##x##volume##typePrefix val)\
	{\
		value = val;\
	}\
protected:\
	Mat##volume##x##volume##typePrefix value = {0};\
}

#define GenMatrixSet(type,typePrefix)\
GenMatrix(type,typePrefix,2,2);\
GenMatrix(type,typePrefix,2,3);\
GenMatrix(type,typePrefix,2,4);\
GenMatrix(type,typePrefix,3,2);\
GenMatrix(type,typePrefix,3,3);\
GenMatrix(type,typePrefix,3,4);\
GenMatrix(type,typePrefix,4,2);\
GenMatrix(type,typePrefix,4,3);\
GenMatrix(type,typePrefix,4,4)


#define GenMatrixUniformSet(type, typePrefix)\
GenMatrixUniforms(type, typePrefix,2,3);\
GenMatrixUniforms(type, typePrefix,3,2);\
GenMatrixUniforms(type, typePrefix,4,3);\
GenMatrixUniforms(type, typePrefix,3,4);\
GenMatrixUniforms(type, typePrefix,2,4);\
GenMatrixUniforms(type, typePrefix,4,2);\
GenSquareMatrixUniforms(type,typePrefix,2);\
GenSquareMatrixUniforms(type,typePrefix,3);\
GenSquareMatrixUniforms(type,typePrefix,4)

#define GenMatrixesForType(type,typePrefix) GenMatrixSet(type,typePrefix)
#define GenMatrixUniformsForType(type,typePrefix) GenMatrixUniformSet(type,typePrefix)

#define INIT_VECTOR_UNIFORM(type, typePrefix,volume)\
GenVector(type, typePrefix,volume);\
GenVectorUniforms(type, typePrefix,volume)

#define INIT_MATRIX_UNIFORMS(type,typePrefix)\
GenMatrixesForType(type,typePrefix);\
GenMatrixUniformsForType(type,typePrefix)

namespace GL
{
	namespace Shaders
	{
		INIT_VECTOR_UNIFORM(GLint, i, 1);
		INIT_VECTOR_UNIFORM(GLint, i, 2);
		INIT_VECTOR_UNIFORM(GLint, i, 3);
		INIT_VECTOR_UNIFORM(GLint, i, 4);

		INIT_VECTOR_UNIFORM(GLuint, ui, 1);
		INIT_VECTOR_UNIFORM(GLuint, ui, 2);
		INIT_VECTOR_UNIFORM(GLuint, ui, 3);
		INIT_VECTOR_UNIFORM(GLuint, ui, 4);

		INIT_VECTOR_UNIFORM(GLfloat, f, 1);
		INIT_VECTOR_UNIFORM(GLfloat, f, 2);
		INIT_VECTOR_UNIFORM(GLfloat, f, 3);
		INIT_VECTOR_UNIFORM(GLfloat, f, 4);

		INIT_VECTOR_UNIFORM(GLdouble, d, 1);
		INIT_VECTOR_UNIFORM(GLdouble, d, 2);
		INIT_VECTOR_UNIFORM(GLdouble, d, 3);
		INIT_VECTOR_UNIFORM(GLdouble, d, 4);

		INIT_MATRIX_UNIFORMS(GLfloat,f);
		INIT_MATRIX_UNIFORMS(GLdouble,d);
	}
}
#endif