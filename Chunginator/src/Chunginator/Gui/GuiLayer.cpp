#include "Gui/GuiLayer.h"

#include "ImGui/ImGuiLayer.h"

namespace CGR
{
	GuiLayer* GuiLayer::Create()
	{
	#ifdef GUI_IMGUI
		return new ImGuiLayer();
	#endif
	}
}