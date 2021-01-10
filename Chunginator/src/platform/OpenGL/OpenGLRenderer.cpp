#include "OpenGL/OpenGLRenderer.h"

#include "Core/Application.h"

namespace CGR
{
	OpenGLRenderer::OpenGLRenderer()
	{}

	OpenGLRenderer::~OpenGLRenderer()
	{}

	void OpenGLRenderer::SwapBuffers()
	{
		const auto& window = Application::Get().GetWindow().GetNativeWindow();
		glfwSwapBuffers((GLFWwindow*)window);
		glfwPollEvents();
	}
}