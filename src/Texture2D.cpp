#include"../include/headers/Texture_imp.h"

namespace GL
{
	namespace Textures
	{
		Texture2D::Texture2D(void* data, int cx, int cy, TextureSubPixelFormat type, TexturePixelType srcFormat, TexturePixelType dstFormat):Texture(Texture_2D)
		{
			_subPixelFormat = type;
			_srcFormat = srcFormat;
			_dstFormat = dstFormat;
			_cx = cx;
			_cy = cy;
			SetTextureData(data);
		}

		void Texture2D::SetTextureData(void* data, int cx, int cy)
		{
			Bind();
			glTexParameteri(_type, GL_TEXTURE_WRAP_S, GL_CLAMP);
			glTexParameteri(_type, GL_TEXTURE_WRAP_T, GL_CLAMP);
			glTexParameteri(_type, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
			glTexParameteri(_type, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glTexImage2D(_type, 0, _dstFormat, cx == 0? _cx:cx, cy == 0?_cy:cy, 0, _srcFormat, _subPixelFormat, data);
			UnBind();

		}

		void Texture2D::GetTextureData(void* data)
		{
			Bind();
			glGetTexImage(TextureType::Texture_2D, 0, _dstFormat, _subPixelFormat, data);
		}
	}
}