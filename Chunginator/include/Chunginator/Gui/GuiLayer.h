#pragma once

#include "Chunginator.h"
#include "Core/Window.h"

namespace CGR
{
	class GuiLayer
	{
	public:
		virtual ~GuiLayer() = default;

		virtual void Init() = 0;
		virtual void Shutdown() = 0;

		virtual void NewWindow(std::string windowTitle, bool open = 0) = 0;
		virtual void EndWindow() = 0;

		virtual void Begin() = 0;
		virtual void End() = 0;

		static GuiLayer* Create();
	};
}