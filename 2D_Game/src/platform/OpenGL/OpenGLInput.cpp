#include "Core/Input.h"

#include "Core/Application.h"

namespace CGR
{
	int Input::KeyPressed(int keyCode)
	{
		const auto& window = Application::Get().GetWindow().GetNativeWindow();
		return glfwGetKey((GLFWwindow*)window, (int)keyCode) == GLFW_PRESS;
	}

	int Input::KeyDown(int keyCode)
	{
		bool ret = false;
		static int prev_state = GLFW_RELEASE;
		const auto& window = Application::Get().GetWindow().GetNativeWindow();
		
		int key = glfwGetKey((GLFWwindow*)window, (int)keyCode);

		if (key == GLFW_PRESS && prev_state == GLFW_RELEASE)
		{
			ret = true;
		}
		prev_state = key;

		return ret;
	}

	int Input::MouseButtonPressed(int button)
	{
		const auto& window = Application::Get().GetWindow().GetNativeWindow();
		return glfwGetMouseButton((GLFWwindow*)window, button);
	}
}