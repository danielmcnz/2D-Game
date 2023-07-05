#include "Renderer/Renderer2D.h"

namespace CGR
{
	struct QuadVertex
	{
		Vec4f position;
		Vec4f color;
		Vec2f texCoord;
		float texIndex;
	};

	struct QuadData
	{
		static const unsigned int MaxQuads = 1000;
		static const unsigned int MaxVertices = MaxQuads * 4;
		static const unsigned int MaxIncidies = MaxQuads * 6;

		VertexArray*& vertexArray;
		VertexBuffer*& vertexBuffer;
		IndexBuffer*& indexBuffer;

		QuadVertex* vertexBase = nullptr;
		QuadVertex* vertexPtr = nullptr;

		Vec4f positions[4];
	};

	/*static QuadData s_Data;

	void Renderer2D::Init()
	{
		s_Data.vertexArray = VertexArray::Create();

		s_Data.vertexBuffer = VertexBuffer::Create(s_Data.MaxVertices * sizeof(QuadVertex));

		BufferLayout layout = BufferLayout({
			{ "a_Position", ShaderDataType::Float4 },
			{ "a_Color", ShaderDataType::Float4 },
			{ "a_TexCoords", ShaderDataType::Float2 },
			{ "a_TexIndex", ShaderDataType::Float }
			});

		uint32_t indices[s_Data.MaxIncidies];
		
		for (int i = 0; i < s_Data.MaxIncidies; ++i)
		{

		}

		s_Data.positions[0] = { -0.5f,  0.5f, 0.0f, 1.0f };
		s_Data.positions[1] = {  0.5f,  0.5f, 0.0f, 1.0f };
		s_Data.positions[2] = {  0.5f, -0.5f, 0.0f, 1.0f };
		s_Data.positions[3] = { -0.5f, -0.5f, 0.0f, 1.0f };
	}

	void Renderer2D::DrawQuad(Vec3f& position, Vec2f& size, Texture*& texture)
	{
		glm::mat4 transform = glm::mat4(1.0f);

		DrawQuad(transform, texture);
	}

	void Renderer2D::DrawQuad(Vec3f& position, Vec2f& size, Vec4f& color)
	{
		glm::mat4 transform = glm::mat4(1.0f);

		DrawQuad(transform, color);
	}

	void Renderer2D::DrawQuad(glm::mat4 transform, Texture*& texture)
	{

	}

	void Renderer2D::DrawQuad(glm::mat4 transform, Vec4f& color)
	{

	}*/
}