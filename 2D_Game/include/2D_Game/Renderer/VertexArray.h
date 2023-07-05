#pragma once

#include "2D_Game.h"
#include "Renderer/Buffer.h"

namespace CGR
{
	class VertexArray
	{
	public:
		virtual ~VertexArray() = default;

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual void AddVertexBuffer(VertexBuffer*& vertexBuffer) = 0;
		virtual std::vector<VertexBuffer*>& GetVertexBuffers() = 0;

		virtual void SetIndexBuffer(IndexBuffer*& indexBuffer) = 0;
		virtual IndexBuffer*& GetIndexBuffer() = 0;


		static VertexArray* Create();
	};
}