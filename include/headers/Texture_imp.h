#ifndef TEXTURE_IMP_H
#define TEXTURE_IMP_H

#include<vector>
#include"Texture.h"
#include"Enums/TexturePixelType.h"
#include"Enums/TextureSubPixelFormat.h"

namespace GL
{
	namespace Textures
	{
		class Texture2D :public Texture
		{
		public:
			//data is pixel[][] array (ptr on ptr array on pixels)
			Texture2D(void* data,int cx, int cy, TextureSubPixelFormat type = UByte,TexturePixelType srcFormat = RGBA, TexturePixelType dstFormat = RGBA);
			//cx = 0 and cy = 0 to use prev size
			void SetTextureData(void* data, int cx = 0, int cy = 0);
			void GetTextureData(void* data);
		protected:
			int _cx;
			int _cy;
			TexturePixelType _srcFormat;
			TexturePixelType _dstFormat;
			TextureSubPixelFormat _subPixelFormat;
		};
	}
}
#endif