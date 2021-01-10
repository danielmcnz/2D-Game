#include "OpenGL/OpenGLRenderer.h"

#include "Core/Application.h"

namespace CGR
{
	OpenGLRenderer::OpenGLRenderer()
	{}

	OpenGLRenderer::~OpenGLRenderer()
	{}

	void OpenGLRenderer::SetViewPort()
	{
		auto& window = Application::Get().GetWindow();
		glViewport(0, 0, window.GetWidth(), window.GetHeight());
	}

	void OpenGLRenderer::DrawIndexed(VertexArray*& vertexArray)
	{
		glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, 0);
	}

	void OpenGLRenderer::SwapBuffers()
	{
		const auto& window = Application::Get().GetWindow().GetNativeWindow();
		glfwSwapBuffers((GLFWwindow*)window);
		glfwPollEvents();
	}
}