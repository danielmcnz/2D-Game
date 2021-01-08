#include "Core/Application.h"

namespace CGR
{
	Application* Application::s_Instance = nullptr;

	Application::Application(int argc, char** argv)
	{
		s_Instance = this;
		m_Window = Window::Create("Game", 1350, 750);
	}

	Application::~Application()
	{}

	void Application::Run()
	{
		float vertices[] = {
			// position				// color					// texcoords	// texindex
			-0.5f,  0.5f, 0.0f,		0.0f, 0.0f, 1.0f, 1.0f,		0.0f, 0.0f,		0.0f,	// top left
			 0.5f,  0.5f, 0.0f,		0.0f, 0.0f, 1.0f, 1.0f,		1.0f, 0.0f,		0.0f,	// top right
			 0.5f, -0.5f, 0.0f,		0.0f, 0.0f, 1.0f, 1.0f,		1.0f, 1.0f,		0.0f,	// bottom right
			-0.5f, -0.5f, 0.0f,		0.0f, 0.0f, 1.0f, 1.0f,		0.0f, 1.0f,		0.0f 	// bottom left
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		Shader* shader = Shader::Create("assets/shaders/vert.glsl", "assets/shaders/frag.glsl");
		shader->Bind();

		shader->SetUniformMat4fv("u_Projection", glm::mat4(1.0f));
		shader->SetUniformMat4fv("u_View", glm::mat4(1.0f));
		shader->SetUniformMat4fv("u_Model", glm::mat4(1.0f));

		VertexArray* va = VertexArray::Create();

		BufferLayout bl = BufferLayout({
			{ "a_Position", ShaderDataType::Float3 },
			{ "a_Color", ShaderDataType::Float4 },
			{ "texCoords", ShaderDataType::Float2 },
			{ "texIndex", ShaderDataType::Float }
		});

		VertexBuffer* vb = VertexBuffer::Create(vertices, 4 * 10 * sizeof(float));
		vb->SetLayout(bl);

		IndexBuffer* ib = IndexBuffer::Create(indices, sizeof(indices) / sizeof(unsigned int));

		va->AddVertexBuffer(vb);
		va->SetIndexBuffer(ib);

		while (m_Window->IsRunning())
		{
			m_Window->SetClearColor(Vec4f( 0.0f, 0.0f, 0.0f, 1.0f ));
			m_Window->Clear();
			

			if (Input::KeyPressed(KeyCode::Escape))
			{
				m_Window->Shutdown();
				break;
			}
			else if (Input::KeyPressed(KeyCode::E))
			{
				m_Window->SetFullScreen();
			}
			else if (Input::KeyPressed(KeyCode::Q))
			{
				m_Window->SetWindowed();
			}
			else if (Input::KeyPressed(KeyCode::W))
			{
				m_Window->SetWindowedBorderless();
			}

			glDrawElements(GL_TRIANGLES, va->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, 0);

			m_Window->OnUpdate();
		}
	}
}