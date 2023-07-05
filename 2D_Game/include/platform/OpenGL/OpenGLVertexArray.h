#pragma once

#include "Renderer/VertexArray.h"

namespace CGR
{
	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		~OpenGLVertexArray() override;

		void Bind() override;
		void Unbind() override;

		void AddVertexBuffer(VertexBuffer*& vertexBuffer) override;
		std::vector<VertexBuffer*>& GetVertexBuffers() override { return m_VertexBuffers; }
		void SetIndexBuffer(IndexBuffer*& indexBuffer) override;
		IndexBuffer*& GetIndexBuffer() override { return m_IndexBuffer; }

	private:
		uint32_t m_VertexArrayID;
		uint32_t m_VertexBufferIndex;
		std::vector<VertexBuffer*> m_VertexBuffers;
		IndexBuffer* m_IndexBuffer;
	};
}