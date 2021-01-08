#include "OpenGL/OpenGLBuffer.h"

namespace CGR
{
	OpenGLVertexBuffer::OpenGLVertexBuffer(uint32_t size)
	{
		glGenBuffers(1, &m_VertexBufferID);
		glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferID);
		glBufferData(GL_ARRAY_BUFFER, size, 0, GL_DYNAMIC_DRAW);
	}

	OpenGLVertexBuffer::OpenGLVertexBuffer(float* data, uint32_t size)
	{
		glGenBuffers(1, &m_VertexBufferID);
		glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferID);
		glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &m_VertexBufferID);
	}

	void OpenGLVertexBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferID);
	}

	void OpenGLVertexBuffer::Unbind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* data, uint32_t count)
		:
		m_Count(count)
	{
		glGenBuffers(1, &m_IndexBufferID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), data, GL_STATIC_DRAW);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &m_IndexBufferID);
	}

	void OpenGLIndexBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID);
	}

	void OpenGLIndexBuffer::Unbind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}