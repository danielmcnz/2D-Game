#include "OpenGL/OpenGLVertexArray.h"

namespace CGR
{
	OpenGLVertexArray::OpenGLVertexArray()
		:
		m_VertexBufferIndex(0), m_IndexBuffer(nullptr)
	{
		glGenVertexArrays(1, &m_VertexArrayID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_VertexArrayID);
	}

	void OpenGLVertexArray::Bind()
	{
		glBindVertexArray(m_VertexArrayID);
	}

	void OpenGLVertexArray::Unbind()
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::AddVertexBuffer(VertexBuffer*& vertexBuffer)
	{
		Bind();
		vertexBuffer->Bind();

		auto& layout = vertexBuffer->GetLayout();

		auto temp = layout.GetElements().size();

		for (auto& element : layout)
		{
			glEnableVertexAttribArray(m_VertexBufferIndex);
			glVertexAttribPointer(m_VertexBufferIndex,
				element.GetComponentCount(), 
				BufferElement::OpenGLShaderDataType(element.Type), 
				BufferElement::OpenGLBoolean(element.Normalized),
				(GLsizei)layout.GetStride(),
				(const void*)element.Offset);
			++m_VertexBufferIndex;
		}

		m_VertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(IndexBuffer*& indexBuffer)
	{
		Bind();
		indexBuffer->Bind();

		m_IndexBuffer = indexBuffer;
	}
}