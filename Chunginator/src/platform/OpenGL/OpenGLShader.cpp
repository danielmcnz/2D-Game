#include "OpenGL/OpenGLShader.h"

namespace CGR
{
	OpenGLShader::OpenGLShader(std::string vertexPath, std::string fragmentPath)
		:
		m_ProgramID(0)
	{
		std::string vertexSource = LoadShader(vertexPath);
		m_VertexShader = CompileShader(ShaderType::Vertex, vertexSource);

		std::string fragmentSource = LoadShader(fragmentPath);
		m_FragmentShader = CompileShader(ShaderType::Fragment, fragmentSource);

		m_ProgramID = glCreateProgram();

		glAttachShader(m_ProgramID, m_VertexShader);
		glAttachShader(m_ProgramID, m_FragmentShader);
		glLinkProgram(m_ProgramID);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteShader(m_VertexShader);
		glDeleteShader(m_FragmentShader);
		glDeleteProgram(m_ProgramID);
	}

	void OpenGLShader::Bind()
	{
		glUseProgram(m_ProgramID);
	}

	void OpenGLShader::Unbind()
	{
		glUseProgram(0);
	}

	uint32_t OpenGLShader::CompileShader(ShaderType shaderType, std::string& shaderSource)
	{
		GLenum type = shaderType == ShaderType::Vertex ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER;

		uint32_t shader = glCreateShader(type);
		const char* shaderSourceChar = shaderSource.c_str();
		glShaderSource(shader, 1, &shaderSourceChar, nullptr);
		glCompileShader(shader);

		return shader;
	}
}