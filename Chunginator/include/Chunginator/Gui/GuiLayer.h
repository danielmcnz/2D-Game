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
		virtual void Begin() = 0;
		virtual void End() = 0;
		virtual void Shutdown() = 0;

		static GuiLayer* Create();
	};
}