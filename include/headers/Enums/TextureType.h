#ifndef TEXTURETYPE_H
#define TEXTURETYPE_H
#include "../opengl.h"

namespace GL
{
	namespace Textures
	{
		enum TextureType
		{
			Texture_1D						= GL_TEXTURE_1D,
			Texture_2D						= GL_TEXTURE_2D,
			Texture_3D						= GL_TEXTURE_3D,
			Texture_1D_Array				= GL_TEXTURE_1D_ARRAY,
			Texture_2D_Array				= GL_TEXTURE_2D_ARRAY,
			Texture_Rectangle				= GL_TEXTURE_RECTANGLE,
			Texture_CubeMap					= GL_TEXTURE_CUBE_MAP,
			Texture_CubeMap_Array			= GL_TEXTURE_CUBE_MAP_ARRAY,
			Texture_Buffer					= GL_TEXTURE_BUFFER,
			Texture_2D_Multisample			= GL_TEXTURE_2D_MULTISAMPLE,
			Texture_2D_Multisample_Array	= GL_TEXTURE_2D_MULTISAMPLE_ARRAY
		};
	}
}
#endif

