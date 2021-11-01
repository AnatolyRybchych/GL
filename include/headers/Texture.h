#ifndef TEXTURE_H
#define TEXTURE_H

#include<assert.h>
#include"Enums/TextureType.h"



namespace GL
{
	namespace Textures
	{

		class Texture
		{
		public:
			Texture(TextureType type);
			~Texture();
			void Bind();
			void UnBind();
			//use uniform1i with value texBlock to send texture to your Sempler variable in shader
			void BindTextureWithBlock(unsigned int texBlock);
			GLuint GetId();
		protected:
			TextureType _type;
			GLuint _textureId;
		};
	}
}
#endif