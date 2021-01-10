#pragma once

#include "Chunginator.h"
#include "Core/Window.h"
#include "Core/Input.h"
#include "Gui/GuiLayer.h"

// Temporary //
#include "Renderer/VertexArray.h"
#include "Renderer/Buffer.h"
#include "Renderer/Shader.h"
#include "Renderer/Texture.h"
#include "Gui/GuiWidgets.h"

namespace CGR
{
	class Application
	{
	public:
		Application(int argc, char** argv);
		~Application();

		void Run();

		static Application& Get() { return *s_Instance; }
		Window& GetWindow() { return *m_Window; }

	private:
		static Application* s_Instance;
		Window* m_Window;
		GuiLayer* m_GuiLayer;
	};
}