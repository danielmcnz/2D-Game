#include "ImGui/ImGuiLayer.h"

#include <Core/Application.h>

namespace CGR
{
	ImGuiLayer::ImGuiLayer()
	{}

	ImGuiLayer::~ImGuiLayer()
	{}

	void ImGuiLayer::Init()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		auto window = Application::Get().GetWindow().GetNativeWindow();

	#ifdef CGR_OPENGL
		ImGui_ImplGlfw_InitForOpenGL((GLFWwindow*)window, true);
		ImGui_ImplOpenGL3_Init((const char*)glGetString(GL_NUM_SHADING_LANGUAGE_VERSIONS));
	#endif
	}

	void ImGuiLayer::Shutdown()
	{
	#ifdef CGR_OPENGL
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
	#endif

		ImGui::DestroyContext();
	}

	void ImGuiLayer::Begin()
	{
	#ifdef CGR_OPENGL
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
	#endif

		ImGui::NewFrame();
	}

	void ImGuiLayer::End()
	{
		ImGui::Render();
	#ifdef CGR_OPENGL
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	#endif
	}
}