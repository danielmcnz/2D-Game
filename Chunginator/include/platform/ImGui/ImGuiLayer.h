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
		void Begin() override;
		void End() override;
		void Shutdown() override;

	private:
		Window* m_Window;
	};
}