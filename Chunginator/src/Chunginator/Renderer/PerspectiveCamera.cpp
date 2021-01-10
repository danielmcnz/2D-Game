#include "Renderer/PerspectiveCamera.h"

#include "Core/Application.h"

namespace CGR
{
	PerspectiveCamera::PerspectiveCamera()
		:
		m_CameraSpeed(0.1f), m_ZoomSpeed(0.1f), m_FOV(45.0f), m_NearPlane(0.1f), m_FarPlane(100.0f), m_CameraPos(Vec3f(0.0f, 0.0f, -2.0f)),
		m_View(glm::mat4(1.0f)), m_Projection(glm::mat4(1.0f))
	{}

	PerspectiveCamera::~PerspectiveCamera()
	{}

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

		/*if (int mouseWheel = Input::MouseButtonPressed())
		{
			std::cout << mouseWheel << std::endl;
		}*/

		m_View = glm::translate(glm::mat4(1.0f), glm::vec3(m_CameraPos.x, m_CameraPos.y, m_CameraPos.z));

		m_Projection = glm::perspective(glm::radians(m_FOV), (float)window.GetWidth() / (float)window.GetHeight(), m_NearPlane, m_FarPlane);
	}

	void PerspectiveCamera::OnGuiUpdate()
	{
		GuiWidgets::SliderFloat("Camera Speed", &m_CameraSpeed, 0.0f, 0.5f);
		GuiWidgets::SliderFloat("Zoom Speed", &m_ZoomSpeed, 0.0f, 0.5f);
		GuiWidgets::SliderFloat3("Camera Position", &m_CameraPos.x, -100.0f, 100.0f);
	}

	void PerspectiveCamera::OnRender()
	{

	}
}