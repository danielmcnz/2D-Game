#pragma once

#include "Chunginator.h"

namespace CGR
{
	class Renderer2D
	{
	public:
		static void BeginScene();
		static void EndScene();

		static void DrawQuad(Vec2f position, Vec2f size);
		static void DrawQuad(Vec2f position, Vec2f size, float rotation);
	
	private:
		static void BeginBatch();
		static void EndBatch();
	};
}