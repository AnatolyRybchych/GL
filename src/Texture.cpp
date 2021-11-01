#include"../include/headers/Texture.h"



void f()
{

}

namespace GL
{
	namespace Textures
	{
		Texture::Texture(TextureType type)
		{
			glGenTextures(1, &_textureId);
			_type = type;
		}

		Texture::~Texture()
		{
			glDeleteTextures(1, &_textureId);
		}

		void Texture::Bind()
		{
			glBindTexture(_type, _textureId);
		}

		void Texture::UnBind() 
		{
			glBindTexture(_type, 0);
		}


		void Texture::BindTextureWithBlock(unsigned int texBlock)
		{
			glActiveTexture(GL_TEXTURE0 + texBlock);
			Bind();
		}

		GLuint Texture::GetId()
		{
			return _textureId;
		}
	}
}