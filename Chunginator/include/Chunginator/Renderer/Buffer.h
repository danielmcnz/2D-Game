#pragma once

#include "Chunginator.h"

namespace CGR
{
	enum class ShaderDataType
	{
		Float,
		Float2,
		Float3,
		Float4
	};

	class BufferElement
	{
	public:
		std::string Name;
		ShaderDataType Type;
		uint32_t Size;
		size_t Offset;
		bool Normalized;

	public:
		BufferElement(std::string name, ShaderDataType type, bool normalized = false)
			:
			Name(name), Type(type), Size(ShaderDataTypeSize(type)), Offset(0), Normalized(normalized)
		{}

		static GLenum OpenGLShaderDataType(ShaderDataType type)
		{
			switch (type)
			{
			case ShaderDataType::Float:		return GL_FLOAT;
			case ShaderDataType::Float2:	return GL_FLOAT;
			case ShaderDataType::Float3:	return GL_FLOAT;
			case ShaderDataType::Float4:	return GL_FLOAT;
			}

			return 0;
		}

		static GLenum OpenGLBoolean(bool type)
		{
			switch (type)
			{
			case true:		return GL_TRUE;
			case false:		return GL_FALSE;
			}

			return 0;
		}

		static uint32_t ShaderDataTypeSize(ShaderDataType type)
		{
			switch (type)
			{
			case ShaderDataType::Float:		return 4;
			case ShaderDataType::Float2:	return 2 * 4;
			case ShaderDataType::Float3:	return 3 * 4;
			case ShaderDataType::Float4:	return 4 * 4;
			}

			return 0;
		}

		uint32_t GetComponentCount()
		{
			switch (Type)
			{
			case ShaderDataType::Float:		return 1;
			case ShaderDataType::Float2:	return 2;
			case ShaderDataType::Float3:	return 3;
			case ShaderDataType::Float4:	return 4;
			}

			return 0;
		}
	};

	class BufferLayout
	{
	public:
		BufferLayout() = default;
		BufferLayout(std::vector<BufferElement> elements)
			:
			m_Elements(elements), m_Stride(0)
		{
			CalculateStrideAndOffsets();
		}

		void SetElements(std::vector<BufferElement>& elements) { m_Elements = elements; }
		std::vector<BufferElement>& GetElements() { return m_Elements; }

		size_t GetStride() { return m_Stride; }

		std::vector<BufferElement>::iterator begin() { return m_Elements.begin(); }
		std::vector<BufferElement>::iterator end() { return m_Elements.end(); }
		const std::vector<BufferElement>::const_iterator begin() const { return m_Elements.begin(); }
		const std::vector<BufferElement>::const_iterator end() const { return m_Elements.end(); }

	private:
		void CalculateStrideAndOffsets()
		{
			size_t offset = 0;
			for (auto& element : m_Elements)
			{
				element.Offset = offset;
				offset += element.Size;
				m_Stride += element.Size;
			}
		}

	private:
		std::vector<BufferElement> m_Elements;
		uint32_t m_Stride;
	};

	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual void SetData(void* data, uint32_t size) = 0;

		virtual void SetLayout(BufferLayout bufferLayout) = 0;
		virtual BufferLayout& GetLayout() = 0;

		static VertexBuffer* Create(uint32_t size);
		static VertexBuffer* Create(float* data, uint32_t size);
	};

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() = default;

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual uint32_t GetCount() = 0;

		static IndexBuffer* Create(uint32_t* data, uint32_t count);
	};
}