#include"../include/headers/UniformSampler2D.h"

namespace GL
{
	namespace Shaders
	{
		
		UniformSampler2D::UniformSampler2D(std::string name, GLint progId,void* data, int cx, int cy, unsigned int texBlock,
			TextureSubPixelFormat type,TexturePixelType srcFormat, TexturePixelType dstFormat) :Uniform(name, progId)
		{
			_texture = new GL::Textures::Texture2D(data, cx, cy, type, srcFormat, dstFormat);
			_textBlock = texBlock;
		}

		void UniformSampler2D::SendToShaderProgram()
		{
			_texture->BindTextureWithBlock(_textBlock);
			glUniform1i(_uniformLocation, _textBlock);
		}

		Texture2D* UniformSampler2D::GetTexture()
		{
			return _texture;
		}

		void UniformSampler2D::SetValue(void* data, int cx, int cy)
		{
			_texture->SetTextureData(data, cx, cy);
		}

		UniformSampler2D::~UniformSampler2D()
		{
			delete _texture;
		}

		void UniformSampler2D::GetValue(void* data)
		{
			_texture->GetTextureData(data);
		}
	}
}