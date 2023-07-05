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

		uint32_t GetUniformLocation(std::string location) override;

		void SetUniform1f(std::string location, float data) override;
		void SetUniform1fv(std::string location, uint32_t count, float* data) override;
		void SetUniform2f(std::string location, Vec2f data) override;
		void SetUniform3f(std::string location, Vec3f data) override;
		void SetUniform4f(std::string location, Vec4f data) override;
		void SetUniform1iv(std::string location, uint32_t count, int* data) override;
		void SetUniformMat4fv(std::string location, glm::mat4 data) override;

	protected:
		uint32_t CompileShader(ShaderType shaderType, std::string& shaderSource) override;

	private:
		uint32_t m_ProgramID;
		uint32_t m_VertexShader;
		uint32_t m_FragmentShader;
	};
}