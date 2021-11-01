#ifndef TEXTUREPIXELTYPE_H
#define TEXTUREPIXELTYPE_H

#include "../opengl.h"

namespace GL
{
	namespace Textures
	{
		enum TexturePixelType
		{

			//Each element is a single red component.The GL converts it to floating pointand assembles it into an RGBA element by attaching 0 for greenand blue, and 1 for alpha.Each component is clamped to the range[0, 1].
			R = GL_RED,

			//Each element is a red / green double.The GL converts it to floating point and assembles it into an RGBA element by attaching 0 for blue, and 1 for alpha.Each component is clamped to the range[0, 1].
			RG = GL_RG,

			//Each element is an RGB triple.The GL converts it to floating pointand assembles it into an RGBA element by attaching 1 for alpha.Each component is clamped to the range[0, 1].
			RGB = GL_RGB,
			//Each element is an RGB triple.The GL converts it to floating pointand assembles it into an RGBA element by attaching 1 for alpha.Each component is clamped to the range[0, 1].
			BGR = GL_BGR,

			//Each element contains all four components.Each component is clamped to the range[0, 1].
			RGBA = GL_RGBA,

			//Each element contains all four components.Each component is clamped to the range[0, 1].
			BGRA = GL_BGRA,

			//Each element is a single depth value.The GL converts it to floating pointand clamps to the range[0, 1].
			DepthComponent = GL_DEPTH_COMPONENT,

			//Each element is a pair of depthand stencil values.The depth component of the pair is interpreted as in GL_DEPTH_COMPONENT.The stencil component is interpreted based on specified the depth + stencil internal format.
			DepthStencil = GL_DEPTH_STENCIL,
		};
	}
}

#endif