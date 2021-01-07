#pragma once

#include "Renderer/Shader.h"

namespace CGR
{
	enum class ShaderType
	{
		Vertex,
		Fragment
	};

	class OpenGLShader : public Shader
	{
	public:
		OpenGLShader(std::string vertexPath, std::string FragmentPath);
		~OpenGLShader() override;

		void Bind() override;
		void Unbind() override;

	protected:
		uint32_t CompileShader(ShaderType shaderType, std::string& shaderSource) override;

	private:
		uint32_t m_ProgramID;
		uint32_t m_VertexShader;
		uint32_t m_FragmentShader;
	};
}