#include "Core/Application.h"

namespace CGR
{
	Application* Application::s_Instance = nullptr;

	Application::Application(int argc, char** argv)
	{
		s_Instance = this;
		m_Window = Window::Create("Game", 1350, 750);
		m_GuiLayer = GuiLayer::Create();
		m_Pcamera = new PerspectiveCamera();
		m_Renderer = Renderer::Create();
	}

	Application::~Application()
	{}

	void Application::Run()
	{
		m_GuiLayer->Init();

		float textureIndex = 0.0f;
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
		uint32_t texData = 0xffffffff;
		texture0->SetData(&texData);
		texture0->Unbind();

		Texture2D* texture1 = Texture2D::Create("assets/textures/test.jpg");
		texture1->Bind();

		int32_t samplers[32];
		for (uint32_t i = 0; i < 32; ++i)
		{
			samplers[i] = i;
		}

		shader->SetUniform1iv("u_Textures", 32, samplers);

		float angle = 0.0f;

		while (m_Window->IsRunning())
		{
			m_Window->SetClearColor(Vec4f( 0.5f, 0.5f, 0.5f, 1.0f ));
			m_Window->Clear();

			m_Renderer->SetViewPort();

			m_GuiLayer->Begin();

			m_Pcamera->OnGuiUpdate();
			m_Pcamera->OnUpdate(1.0f);

			if (Input::KeyPressed(KeyCode::Escape))
			{
				m_Window->Shutdown();
				break;
			}
			else if (Input::KeyPressed(KeyCode::One))
			{
				m_Window->SetFullScreen();
			}
			else if (Input::KeyPressed(KeyCode::Two))
			{
				m_Window->SetWindowed();
			}
			else if (Input::KeyPressed(KeyCode::Three))
			{
				m_Window->SetWindowedBorderless();
			}
			
			GuiWidgets::SliderFloat("angle", &angle, -180.0f, 180.0f);

			glm::mat4 model = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(1.0f, 0.0f, 0.0f));

			shader->SetUniformMat4fv("u_Model", model);
			shader->SetUniformMat4fv("u_View", m_Pcamera->GetView());
			shader->SetUniformMat4fv("u_Projection", m_Pcamera->GetProjection());

			m_Pcamera->OnRender();

			m_Renderer->DrawIndexed(va);

			m_GuiLayer->End();

			m_Window->OnUpdate();
		}

		m_GuiLayer->Shutdown();
	}
}