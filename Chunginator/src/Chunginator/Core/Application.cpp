#include "Core/Application.h"

namespace CGR
{
	Application* Application::s_Instance = nullptr;

	Application::Application(int argc, char** argv)
	{
		s_Instance = this;
		m_Window = Window::Create("Game", 1350, 750);
		m_GuiLayer = GuiLayer::Create();
	}

	Application::~Application()
	{}

	void Application::Run()
	{
		m_GuiLayer->Init();

		float textureIndex = 1.0f;
		float vertices[] = {
			// position				// color					// texcoords	// texindex
			-0.5f,  0.5f, 0.0f,		0.0f, 0.0f, 1.0f, 1.0f,		0.0f, 0.0f,		textureIndex,	// top left
			 0.5f,  0.5f, 0.0f,		0.0f, 0.0f, 1.0f, 1.0f,		1.0f, 0.0f,		textureIndex,	// top right
			 0.5f, -0.5f, 0.0f,		0.0f, 0.0f, 1.0f, 1.0f,		1.0f, 1.0f,		textureIndex,	// bottom right
			-0.5f, -0.5f, 0.0f,		0.0f, 0.0f, 1.0f, 1.0f,		0.0f, 1.0f,		textureIndex, 	// bottom left
		};

		unsigned int indices[] = {
			0, 1, 2,
			2, 3, 0
		};

		Shader* shader = Shader::Create("assets/shaders/vert.glsl", "assets/shaders/frag.glsl");
		shader->Bind();

		VertexArray* va = VertexArray::Create();

		BufferLayout bl = BufferLayout({
			{ "a_Position", ShaderDataType::Float3 },
			{ "a_Color", ShaderDataType::Float4 },
			{ "a_TexCoords", ShaderDataType::Float2 },
			{ "a_TexIndex", ShaderDataType::Float }
		});

		VertexBuffer* vb = VertexBuffer::Create(vertices, 4 * 10 * sizeof(float));
		vb->SetLayout(bl);

		IndexBuffer* ib = IndexBuffer::Create(indices, sizeof(indices) / sizeof(unsigned int));

		va->AddVertexBuffer(vb);
		va->SetIndexBuffer(ib);

		Texture2D* texture0 = Texture2D::Create(1, 1);
		texture0->Bind();
		uint32_t texData = 100;
		texture0->SetData(&texData);

		Texture2D* texture1 = Texture2D::Create("assets/textures/test.jpg");
		texture1->Bind(1);

		int32_t samplers[32];
		for (uint32_t i = 0; i < 32; ++i)
		{
			samplers[i] = i;
		}

		shader->SetUniform1iv("u_Textures", 32, samplers);

		while (m_Window->IsRunning())
		{
			m_Window->SetClearColor(Vec4f( 0.5f, 0.5f, 0.5f, 1.0f ));
			m_Window->Clear();

			m_GuiLayer->Begin();

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

			glm::mat4 projection = glm::ortho(0.0f, (float)m_Window->GetWidth(), 0.0f, (float)m_Window->GetHeight(), 0.1f, 100.0f);
			projection = glm::mat4(1.0f);
			
			shader->SetUniformMat4fv("u_Projection", projection);
			shader->SetUniformMat4fv("u_View", glm::mat4(1.0f));
			shader->SetUniformMat4fv("u_Model", glm::mat4(1.0f));

			glDrawElements(GL_TRIANGLES, va->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, 0);

			m_GuiLayer->End();

			m_Window->OnUpdate();
		}

		m_GuiLayer->Shutdown();
	}
}