#ifndef UNIFORMSAMPLER2D_H
#define UNIFORMSAMPLER2D_H

#include"Uniform.h"
#include"Texture_imp.h"

using GL::Textures::TexturePixelType;
using GL::Textures::TextureSubPixelFormat;
using GL::Textures::Texture2D;

namespace GL
{
	namespace Shaders
	{
		class UniformSampler2D :public Uniform
		{
		public:
			//for glsl uniform sampler2D "std::string name"; //variable to use function "vec4 texture2D(sampler2D sampler, vec2 coord)"
			UniformSampler2D(std::string name, GLint progId, void* data, int cx, int cy, unsigned int texBlock = 0,
				TextureSubPixelFormat type = TextureSubPixelFormat::UByte, TexturePixelType srcFormat = TexturePixelType::RGBA, TexturePixelType dstFormat = TexturePixelType::RGBA);
			virtual void SendToShaderProgram();
			//cx = 0 and cy = 0 to use prev values
			void SetValue(void* data, int cx = 0, int cy = 0);
			Texture2D* GetTexture();
			void GetValue(void* data);
			~UniformSampler2D();
		protected:
			unsigned int _textBlock;
			Texture2D* _texture;
		};
	}
}
#endif