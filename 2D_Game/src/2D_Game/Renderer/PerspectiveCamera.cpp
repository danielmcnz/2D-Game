#include "Renderer/PerspectiveCamera.h"

#include "Core/Application.h"

namespace CGR
{
	static float m_Fov;

	PerspectiveCamera::PerspectiveCamera()
		:
		m_CameraSpeed(2.0f), m_ZoomSpeed(4.0f), /*m_Fov(45.0f),*/ m_NearPlane(0.1f), m_FarPlane(100.0f), 
		m_CameraPos(Vec3f(0.0f, 0.0f, -2.0f)), m_View(glm::mat4(1.0f)), m_Projection(glm::mat4(1.0f))
	{
		m_Fov = 45.0f;
	}

	PerspectiveCamera::~PerspectiveCamera()
	{}

	void tempScrollCallback(GLFWwindow* window, double xOffset, double yOffset)
	{
		if (m_Fov >= 1.0f && m_Fov <= 45.0f)
		{
			m_Fov -= (float)yOffset * 2.0f;
		}
		if (m_Fov <= 1.0f)
		{
			m_Fov = 1.0f;
		}
		if (m_Fov >= 45.0f)
		{
			m_Fov = 45.0f;
		}
	}

	void PerspectiveCamera::OnUpdate(float deltaTime)
	{
		auto& window = Application::Get().GetWindow();

		if (Input::KeyPressed(KeyCode::W))
		{
			m_CameraPos.y -= m_CameraSpeed * deltaTime;
		}
		else if (Input::KeyPressed(KeyCode::S))
		{
			m_CameraPos.y += m_CameraSpeed * deltaTime;
		}
		if (Input::KeyPressed(KeyCode::A))
		{
			m_CameraPos.x += m_CameraSpeed * deltaTime;
		}
		else if (Input::KeyPressed(KeyCode::D))
		{
			m_CameraPos.x -= m_CameraSpeed * deltaTime;
		}
		if (Input::KeyPressed(KeyCode::Q))
		{
			m_CameraPos.z += m_ZoomSpeed * deltaTime;
		}
		else if (Input::KeyPressed(KeyCode::E))
		{
			m_CameraPos.z -= m_ZoomSpeed * deltaTime;
		}

		m_View = glm::translate(glm::mat4(1.0f), glm::vec3(m_CameraPos.x, m_CameraPos.y, m_CameraPos.z));

		glfwSetScrollCallback((GLFWwindow*)Application::Get().GetWindow().GetNativeWindow(),
			tempScrollCallback);

		m_Projection = glm::perspective(glm::radians(m_Fov), (float)window.GetWidth() / (float)window.GetHeight(), m_NearPlane, m_FarPlane);
	}

	void PerspectiveCamera::OnGuiUpdate()
	{
		GuiWidgets::SliderFloat("Camera Speed", &m_CameraSpeed, 0.0f, 100.0f);
		GuiWidgets::SliderFloat("Zoom Speed", &m_ZoomSpeed, 0.0f, 100.0f);
		GuiWidgets::SliderFloat3("Camera Position", &m_CameraPos.x, -99.0f, -0.101f);
	}

	void PerspectiveCamera::OnEvent()
	{

	}

	void PerspectiveCamera::OnRender()
	{
		
	}
}