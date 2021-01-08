#include "Gui/GuiWidgets.h"

namespace CGR
{
	bool GuiWidgets::Button(std::string text, const Vec2f& size)
	{
	#ifdef GUI_IMGUI
		ImVec2 imSize = ImVec2(size.x, size.y);
		return ImGui::Button(text.c_str(), imSize);
	#endif
	}

	bool GuiWidgets::SliderFloat(std::string title, float* value, float min, float max)
	{
	#ifdef GUI_IMGUI
		return ImGui::SliderFloat(title.c_str(), value, min, max);
	#endif
	}

	bool GuiWidgets::SliderFloat2(std::string title, float value[2], float min, float max)
	{
	#ifdef GUI_IMGUI
		return ImGui::SliderFloat2(title.c_str(), value, min, max);
	#endif
	}

	bool GuiWidgets::SliderFloat3(std::string title, float value[3], float min, float max)
	{
	#ifdef GUI_IMGUI
		return ImGui::SliderFloat3(title.c_str(), value, min, max);
	#endif
	}

	bool GuiWidgets::SliderFloat4(std::string title, float value[4], float min, float max)
	{
	#ifdef GUI_IMGUI
		return ImGui::SliderFloat3(title.c_str(), value, min, max);
	#endif
	}

	bool GuiWidgets::ColorEdit3(std::string title, float color[3])
	{
	#ifdef GUI_IMGUI
		return ImGui::ColorEdit3(title.c_str(), color);
	#endif
	}

	bool GuiWidgets::ColorEdit4(std::string title, float color[4])
	{
	#ifdef GUI_IMGUI
		return ImGui::ColorEdit4(title.c_str(), color);
	#endif
	}
}