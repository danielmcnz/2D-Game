#include "Core/Application.h"

namespace CGR
{
	Application* Application::s_Instance = nullptr;

	Application::Application(int argc, char** argv)
	{
		s_Instance = this;
		m_Window = Window::Create("Game", 1350, 750);
		m_Window->SetFullScreen();
	}

	Application::~Application()
	{}

	void Application::Run()
	{
		
		

		while (m_Window->IsRunning())
		{
			m_Window->SetClearColor(Vec4f( 0.0f, 0.0f, 0.0f, 1.0f ));
			m_Window->Clear();
			

			if (Input::KeyPressed(KeyCode::Escape))
			{
				m_Window->Shutdown();
				break;
			}


			m_Window->OnUpdate();
		}
	}
}