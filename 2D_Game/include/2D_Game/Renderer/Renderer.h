#pragma once

#include "2D_Game.h"
#include "Renderer/VertexArray.h"

namespace CGR
{
	class Renderer
	{
	public:
		virtual ~Renderer() = default;

		virtual void SetViewPort() = 0;

		virtual void DrawIndexed(VertexArray*& vertexArray) = 0;

		virtual void SwapBuffers() = 0;

		static Renderer* Create();
	};
}