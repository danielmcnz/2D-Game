#pragma once

#include "Renderer/Buffer.h"

namespace CGR
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(uint32_t size);
		OpenGLVertexBuffer(float* data, uint32_t size);
		~OpenGLVertexBuffer() override;

		void SetLayout(BufferLayout bufferLayout) override { m_BufferLayout = bufferLayout; }
		BufferLayout& GetLayout() override { return m_BufferLayout; }

		void Bind() override;
		void Unbind() override;

	private:
		uint32_t m_VertexBufferID;
		BufferLayout m_BufferLayout;
	};

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t* data, uint32_t count);
		~OpenGLIndexBuffer() override;

		void Bind() override;
		void Unbind() override;

		uint32_t GetCount() override { return m_Count; };

	private:
		uint32_t m_IndexBufferID;
		uint32_t m_Count;
	};
}