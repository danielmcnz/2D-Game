#pragma once

#include "Gui/GuiLayer.h"

namespace CGR
{
	class ImGuiLayer : public GuiLayer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() override;

		void Init() override;
		void Shutdown() override;

		void NewWindow(std::string windowTitle, bool open = 0) override;
		void EndWindow() override;

		void Begin() override;
		void End() override;

	private:
		Window* m_Window;
	};
}