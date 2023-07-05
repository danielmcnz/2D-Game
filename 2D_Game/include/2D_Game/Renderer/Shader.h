#pragma once

#include "2D_Game.h"

namespace CGR
{
	enum class ShaderType;

	class Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		virtual uint32_t GetUniformLocation(std::string location) = 0;

		virtual void SetUniform1f(std::string location, float data) = 0;
		virtual void SetUniform1fv(std::string location, uint32_t count, float* data) = 0;
		virtual void SetUniform2f(std::string location, Vec2f data) = 0;
		virtual void SetUniform3f(std::string location, Vec3f data) = 0;
		virtual void SetUniform4f(std::string location, Vec4f data) = 0;
		virtual void SetUniform1iv(std::string location, uint32_t count, int* data) = 0;
		virtual void SetUniformMat4fv(std::string location, glm::mat4 data) = 0;

		static Shader* Create(std::string vertexPath, std::string fragmentPath);

	protected:
		std::string LoadShader(std::string shaderPath);

		virtual uint32_t CompileShader(ShaderType shaderType, std::string& shaderSource) = 0;
	};
}