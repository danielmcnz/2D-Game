#pragma once

#include "Chunginator.h"
#include "Renderer/Renderer.h"
#include "Renderer/Texture.h"

namespace CGR
{
	class Renderer2D
	{
	public:
		static void Init();

		static void BeginScene();
		static void EndScene();

		static void DrawQuad(Vec3f& position, Vec2f& size, Texture*& texture);
		static void DrawQuad(Vec3f& position, Vec2f& size, Vec4f& color);

		static void DrawQuad(glm::mat4 transform, Texture*& texture);
		static void DrawQuad(glm::mat4 transform, Vec4f& color);

	private:
		static void BeginBatch();
		static void NextBatch();
	};
}