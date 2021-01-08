#pragma once

#include "Chunginator.h"

namespace CGR
{
	class GuiWidgets
	{
	public:
		static bool Button(std::string text, const Vec2f& size = Vec2f(0.0f, 0.0f));

		static bool SliderFloat(std::string title, float* value, float min, float max);
		static bool SliderFloat2(std::string title, float value[2], float min, float max);
		static bool SliderFloat3(std::string title, float value[3], float min, float max);
		static bool SliderFloat4(std::string title, float value[4], float min, float max);

		static bool ColorEdit3(std::string title, float color[3]);
		static bool ColorEdit4(std::string title, float color[4]);
	};
}