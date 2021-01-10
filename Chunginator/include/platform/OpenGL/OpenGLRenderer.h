#pragma once

#include "Renderer/Renderer.h"

namespace CGR
{
	class OpenGLRenderer : public Renderer
	{
	public:
		OpenGLRenderer();
		~OpenGLRenderer() override;

		void SetViewPort() override;

		void DrawIndexed(VertexArray*& vertexArray) override;

		void SwapBuffers() override;
	};
}