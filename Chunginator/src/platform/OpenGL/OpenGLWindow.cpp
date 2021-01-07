#include "OpenGL/OpenGLWindow.h"

namespace CGR
{
	OpenGLWindow::OpenGLWindow(std::string title, uint32_t width, uint32_t height)
		:
		m_Title(title), m_Width(width), m_Height(height), m_Vsync(false), m_Window(nullptr)
	{
		if (!glfwInit())
		{
			std::cout << "Failed to init glfw" << std::endl;
			exit(1);
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), 0, 0);

		if (!m_Window)
		{
			std::cout << "Failed to create glfw window" << std::endl;
			glfwTerminate();
			exit(1);
		}

		glfwMakeContextCurrent(m_Window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to init glad" << std::endl;
			glfwDestroyWindow(m_Window);
			glfwTerminate();
			exit(1);
		}

		m_Renderer = Renderer::Create();
	}

	OpenGLWindow::~OpenGLWindow()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	void OpenGLWindow::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void OpenGLWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	void OpenGLWindow::OnUpdate()
	{
		m_Renderer->SwapBuffers();
	}

	void OpenGLWindow::SetClearColor(Vec4f clearColor)
	{
		glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
	}

	bool OpenGLWindow::IsRunning()
	{
		return !glfwWindowShouldClose(m_Window);
	}

	void OpenGLWindow::SetVsync(bool enabled)
	{
		switch (enabled)
		{
		case true:
			if (m_Vsync)
			{
				std::cout << "Vsync already enabled" << std::endl;
				break;
			}
			glfwSwapInterval(1);
			break;
		case false:
			if (!m_Vsync)
			{
				std::cout << "Vsync already disabled" << std::endl;
				break;
			}
			glfwSwapInterval(0);
			break;
		}
	}

	void OpenGLWindow::SetResizable(bool enabled)
	{
		switch (enabled)
		{
		case true:
			break;
		case false:
			break;
		}
	}

	void OpenGLWindow::SetFullScreen()
	{
		GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
		const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);
		glfwSetWindowMonitor(m_Window, primaryMonitor, 0, 0, mode->width, mode->height, mode->refreshRate);
	}

	void OpenGLWindow::SetBorderless()
	{

	}
}