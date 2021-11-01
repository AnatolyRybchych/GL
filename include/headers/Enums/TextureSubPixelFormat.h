#ifndef TEXTURESUBPIXELFORMAT_H
#define TEXTURESUBPIXELFORMAT_H
#include"../opengl.h"

namespace GL
{
	namespace Textures
	{
		enum TextureSubPixelFormat
		{
			UByte = GL_UNSIGNED_BYTE,
			Byte = GL_BYTE,
			UShort = GL_UNSIGNED_SHORT,
			Short = GL_SHORT,
			UInt = GL_UNSIGNED_INT,
			Int = GL_INT,
			HalfFloat = GL_HALF_FLOAT,
			Float = GL_FLOAT,
			UByte_3_3_2 = GL_UNSIGNED_BYTE_3_3_2,
			UByte_2_3_3 = GL_UNSIGNED_BYTE_2_3_3_REV,
			UShort_5_6_5 = GL_UNSIGNED_SHORT_5_6_5,
			UShort_5_6_5_Rev = GL_UNSIGNED_SHORT_5_6_5_REV,
			UShort_4_4_4_4 = GL_UNSIGNED_SHORT_4_4_4_4,
			Ushort_4_4_4_4_Rev = GL_UNSIGNED_SHORT_4_4_4_4_REV,
			UShort_5_5_5_1 = GL_UNSIGNED_SHORT_5_5_5_1,
			UShort_1_5_5_5_Rev = GL_UNSIGNED_SHORT_1_5_5_5_REV,
			UInt_8_8_8_8 = GL_UNSIGNED_INT_8_8_8_8,
			UInt_8_8_8_8_Rev = GL_UNSIGNED_INT_8_8_8_8_REV,
			UInt_10_10_10_2 = GL_UNSIGNED_INT_10_10_10_2,
			UInt_10_10_10_2_Rev = GL_UNSIGNED_INT_2_10_10_10_REV,
		};
	}
}
#endif