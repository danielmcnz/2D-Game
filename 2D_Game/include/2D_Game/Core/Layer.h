#pragma once

#include "2D_Game.h"

namespace CGR
{
	class Layer
	{
	public:
		Layer() = default;
		virtual ~Layer() = default;

		virtual void OnUpdate(float deltaTime) = 0;
		virtual void OnGuiUpdate() = 0;
		virtual void OnEvent() = 0;
		virtual void OnRender() = 0;
	};
}