#pragma once

#include "Renderer/Texture.h"

namespace CGR
{
	class OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D(uint32_t width, uint32_t height);
		OpenGLTexture2D(std::string texturePath);
		~OpenGLTexture2D() override;

		void Bind(int slot = 0) override;
		void Unbind() override;

		void SetData(void* data) override;

		int GetWidth() override { return m_Width; }
		int GetHeight() override { return m_Height; }

	private:
		uint32_t m_TextureID;
		unsigned char* m_Data;
		int m_Width;
		int m_Height;
		int m_Channels;
		uint32_t m_InternalFormat;
		uint32_t m_DataFormat;
	};
}