#include "Renderer/Texture.h"

#ifdef CGR_OPENGL
	#include "OpenGL/OpenGLTexture.h"
#endif

namespace CGR
{
	Texture2D* Texture2D::Create(uint32_t width, uint32_t height)
	{
	#ifdef CGR_OPENGL
		return new OpenGLTexture2D(width, height);
	#endif
	}

	Texture2D* Texture2D::Create(std::string texturePath)
	{
	#ifdef CGR_OPENGL
		return new OpenGLTexture2D(texturePath);
	#endif
	}
}