#pragma once

#include "Chunginator.h"

namespace CGR
{
	class Renderer
	{
	public:
		virtual ~Renderer() = default;

		virtual void SwapBuffers() = 0;

		static Renderer* Create();
	};
}