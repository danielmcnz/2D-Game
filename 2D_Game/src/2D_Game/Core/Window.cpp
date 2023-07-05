#include "Core/Window.h"

#ifdef CGR_OPENGL
	#include "OpenGL/OpenGLWindow.h"
#endif

namespace CGR
{
	Window* Window::Create(std::string title, uint32_t width, uint32_t height)
	{
	#ifdef CGR_OPENGL
		return new OpenGLWindow(title, width, height);
	#endif
	}
}