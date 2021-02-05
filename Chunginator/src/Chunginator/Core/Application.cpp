#include "Core/Application.h"

namespace CGR
{
	Application* Application::s_Instance = nullptr;

	Application::Application(int argc, char** argv)
	{
		s_Instance = this;
		m_Window = Window::Create("Game", 1800, 750);
		m_Window->SetIcon("assets/textures/icon.png");
		m_Window->SetVsync(true);

		m_GuiLayer = GuiLayer::Create();
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

		Texture2D* texture1 = Texture2D::Create("assets/textures/rawmap.png");
		texture1->Bind();

		int32_t samplers[32];
		for (uint32_t i = 0; i < 32; ++i)
		{
			samplers[i] = i;
		}

		shader->SetUniform1iv("u_Textures", 32, samplers);

		Vec3f angle = Vec3f(180.0f, 0.0f, 0.0f);

		float time = (float)glfwGetTime();
		float lastFrameTime = 0.0f;

		while (m_Window->IsRunning())
		{
			m_Window->SetClearColor(Vec4f( 0.5f, 0.5f, 0.5f, 1.0f ));
			m_Window->Clear();

			time = (float)glfwGetTime();
			float deltaTime = time - lastFrameTime;
			lastFrameTime = time;

			m_Renderer->SetViewPort();

			m_GuiLayer->Begin();

			m_Pcamera.OnUpdate(deltaTime);

			if (Input::KeyPressed(KeyCode::Escape))
			{
				m_Window->Shutdown();
				break;
			}
			
			if (Input::KeyPressed(KeyCode::F))
			{
				if (m_Window->IsFullScreen())
				{
					m_Window->SetWindowed();
				}
				else
				{
					m_Window->SetFullScreen();
				}
			}

			//ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());

			m_GuiLayer->NewWindow("Controls");

			m_Pcamera.OnGuiUpdate();
			GuiWidgets::SliderFloat3("angle", &angle.x, 0.0f, 360.0f);
			GuiWidgets::Text("FPS: %.1f", GuiWidgets::GetFramerate());

			m_GuiLayer->EndWindow();
			
			auto aspratio = m_Window->GetWidth() / m_Window->GetHeight();

			glm::mat4 model = glm::scale(glm::mat4(1.0f),
				glm::vec3(texture1->GetWidth() / aspratio, texture1->GetHeight() / aspratio, 1.0f))
				* glm::scale(glm::mat4(1.0f), glm::vec3(0.005, 0.005, 1.0f))
				* glm::rotate(glm::mat4(1.0f), glm::radians(angle.x), glm::vec3(1.0f, 0.0f, 0.0f))
				* glm::rotate(glm::mat4(1.0f), glm::radians(angle.y), glm::vec3(0.0f, 1.0f, 0.0f))
				* glm::rotate(glm::mat4(1.0f), glm::radians(angle.z), glm::vec3(0.0f, 0.0f, 1.0f));
			
			shader->SetUniformMat4fv("u_Model", model);
			shader->SetUniformMat4fv("u_View", m_Pcamera.GetView());
			shader->SetUniformMat4fv("u_Projection", m_Pcamera.GetProjection());


			m_Pcamera.OnRender();

			m_Renderer->DrawIndexed(va);

			m_GuiLayer->End();

			m_Window->OnUpdate();
		}

		m_GuiLayer->Shutdown();
	}
}