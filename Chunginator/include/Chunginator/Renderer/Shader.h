#pragma once

#include "Chunginator.h"

namespace CGR
{
	enum class ShaderType;

	class Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() = 0;
		virtual void Unbind() = 0;

		static Shader* Create(std::string vertexPath, std::string fragmentPath);

	protected:
		std::string LoadShader(std::string shaderPath);

		virtual uint32_t CompileShader(ShaderType shaderType, std::string& shaderSource) = 0;
	};
}