#include "OpenGL/OpenGLWindow.h"

namespace CGR
{
	OpenGLWindow::OpenGLWindow(std::string title, uint32_t width, uint32_t height)
		:
		m_Title(title), m_WindowSize(width, height), m_WindowedWindowSize(width, height), m_Vsync(false), m_Window(nullptr), 
		m_State(WindowState::Windowed)
	{
		if (!glfwInit())
		{
			std::cout << "Failed to init glfw" << std::endl;
			exit(1);
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_Window = glfwCreateWindow(m_WindowSize.x, m_WindowSize.y, m_Title.c_str(), 0, 0);

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

		glEnable(GL_DEPTH_TEST);

		glfwGetWindowPos(m_Window, &m_WindowPos.x, &m_WindowPos.y);

		m_Renderer = Renderer::Create();

		/*glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			
		});*/
	}

	OpenGLWindow::~OpenGLWindow()
	{
		glfwDestroyWindow(m_Window);
		glfwTerminate();
	}

	void OpenGLWindow::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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

	void OpenGLWindow::OnEvent()
	{

	}

	void OpenGLWindow::SetClearColor(Vec4f clearColor)
	{
		glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
	}

	bool OpenGLWindow::IsRunning()
	{
		int width, height;
		glfwGetWindowSize(m_Window, &width, &height);
		if (m_State == WindowState::Windowed)
		{
			//glfwGetWindowPos(m_Window, &m_WindowPos.x, &m_WindowPos.y);
			m_WindowedWindowSize = Vec2i(width, height);
			m_WindowSize = m_WindowedWindowSize;
		}
		else
		{
			m_WindowSize = Vec2i(width, height);
		}

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

	void OpenGLWindow::SetIcon(std::string iconPath)
	{
		stbi_set_flip_vertically_on_load(1);

		int x, y, channels;
		unsigned char* pixels = stbi_load(iconPath.c_str(), &x, &y, &channels, 4);

		if (pixels == 0)
		{
			std::cout << "Failed to load icon" << std::endl;
		}

		GLFWimage icon = { x, y, pixels };

		glfwSetWindowIcon(m_Window, 1, &icon);

		stbi_image_free(pixels);
	}

	void OpenGLWindow::SetFullScreen()
	{
		if (m_State != WindowState::Fullscreen)
		{
			m_State = WindowState::Fullscreen;
			GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
			const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);
			glfwSetWindowMonitor(m_Window, primaryMonitor, 0, 0, mode->width, mode->height, mode->refreshRate);
		}
	}

	void OpenGLWindow::SetWindowed()
	{
		if (m_State != WindowState::Windowed)
		{
			m_State = WindowState::Windowed;
			GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
			const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);
			glfwSetWindowMonitor(m_Window, nullptr, m_WindowPos.x, m_WindowPos.y, m_WindowSize.x, m_WindowSize.y, mode->refreshRate);
		}
	}

	void OpenGLWindow::SetWindowed(uint32_t x_Pos, uint32_t y_Pos, uint32_t width, uint32_t height)
	{
		if (m_State != WindowState::Windowed)
		{
			m_State = WindowState::Windowed;
			GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
			const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);
			m_WindowPos.x = x_Pos;
			m_WindowPos.y = y_Pos;
			m_WindowSize.x = width; 
			m_WindowSize.y = height;
			glfwSetWindowMonitor(m_Window, nullptr, m_WindowPos.x, m_WindowPos.y, m_WindowSize.x, m_WindowSize.y, mode->refreshRate);
		}
	}

	void OpenGLWindow::SetWindowedBorderless()
	{
		if (m_State != WindowState::WindowedBorderless)
		{
			m_State = WindowState::WindowedBorderless;
			GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
			const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);
			glfwSetWindowMonitor(m_Window, nullptr, 0, 0, mode->width, mode->height, mode->refreshRate);
		}
	}

	void OpenGLWindow::SetWindowedFullscreen()
	{
		bool usable = false;
		if (usable)
		{
			GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
			const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);

			glfwWindowHint(GLFW_RED_BITS, mode->redBits);
			glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
			glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
			glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

			glfwSetWindowMonitor(m_Window, nullptr, 0, 0, mode->width, mode->height, mode->refreshRate);
		}
	}
}