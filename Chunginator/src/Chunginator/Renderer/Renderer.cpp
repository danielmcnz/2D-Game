#include "Renderer/Renderer.h"

#ifdef CGR_OPENGL
	#include "OpenGL/OpenGLRenderer.h"
#endif

namespace CGR
{
	Renderer* Renderer::Create()
	{
	#ifdef CGR_OPENGL
		return new OpenGLRenderer();
	#endif
	}
}