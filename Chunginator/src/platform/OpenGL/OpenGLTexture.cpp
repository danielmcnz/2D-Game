#include "OpenGL/OpenGLTexture.h"

namespace CGR
{
	OpenGLTexture2D::OpenGLTexture2D(uint32_t width, uint32_t height)
		:
		m_Width(width), m_Height(height), m_InternalFormat(0), m_DataFormat(0)
	{
		glCreateTextures(GL_TEXTURE_2D, 1, &m_TextureID);

		//glBindTexture(GL_TEXTURE_2D, m_TextureID);

		m_InternalFormat = GL_RGBA8;
		m_DataFormat = GL_RGBA;

		glTextureStorage2D(m_TextureID, 1, m_InternalFormat, width, height);

		glTextureParameteri(m_TextureID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(m_TextureID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTextureParameteri(m_TextureID, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(m_TextureID, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}

	OpenGLTexture2D::OpenGLTexture2D(std::string texturePath)
		:
		m_InternalFormat(0), m_DataFormat(0)
	{
		glCreateTextures(GL_TEXTURE_2D, 1, &m_TextureID);

		stbi_set_flip_vertically_on_load(1);
		
		m_Data = stbi_load(texturePath.c_str(), &m_Width, &m_Height, &m_Channels, 0);
		if (m_Data == 0)
		{
			std::cout << "Failed to load texture" << std::endl;
		}

		if (m_Channels == 4)
		{
			m_InternalFormat = GL_RGBA8;
			m_DataFormat = GL_RGBA;
		}
		else if (m_Channels == 3)
		{
			m_InternalFormat = GL_RGB8;
			m_DataFormat = GL_RGB;
		}

		auto temp = m_Channels;

		glTextureStorage2D(m_TextureID, 1, m_InternalFormat, m_Width, m_Height);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTextureSubImage2D(m_TextureID, 0, 0, 0, m_Width, m_Height, m_DataFormat, GL_UNSIGNED_BYTE, m_Data);

		stbi_image_free(m_Data);
	}

	OpenGLTexture2D::~OpenGLTexture2D()
	{
		glDeleteTextures(1, &m_TextureID);
	}

	void OpenGLTexture2D::Bind(int slot)
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, m_TextureID);
	}

	void OpenGLTexture2D::Unbind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void OpenGLTexture2D::SetData(void* data)
	{
		glTextureSubImage2D(m_TextureID, 0, 0, 0, m_Width, m_Height, m_DataFormat, GL_UNSIGNED_BYTE, data);
	}
}