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

	uint32_t OpenGLShader::GetUniformLocation(std::string location)
	{
		uint32_t loc = glGetUniformLocation(m_ProgramID, location.c_str());
		if (loc == -1)
		{
			std::cout << "Uniform does not exist" << std::endl;
		}

		return loc;
	}

	void OpenGLShader::SetUniform1f(std::string location, float data)
	{
		glUniform1f(GetUniformLocation(location), data);
	}

	void OpenGLShader::SetUniform1fv(std::string location, uint32_t count, float* data)
	{
		glUniform1fv(GetUniformLocation(location), count, data);
	}

	void OpenGLShader::SetUniform2f(std::string location, Vec2f data)
	{
		glUniform2f(GetUniformLocation(location), data.x, data.y);
	}

	void OpenGLShader::SetUniform3f(std::string location, Vec3f data)
	{
		glUniform3f(GetUniformLocation(location), data.x, data.y, data.z);
	}

	void OpenGLShader::SetUniform4f(std::string location, Vec4f data)
	{
		glUniform4f(GetUniformLocation(location), data.x, data.y, data.z, data.w);
	}

	void OpenGLShader::SetUniform1iv(std::string location, uint32_t count, int* data)
	{
		glUniform1iv(GetUniformLocation(location), count, data);
	}

	void OpenGLShader::SetUniformMat4fv(std::string location, glm::mat4 data)
	{
		glUniformMatrix4fv(GetUniformLocation(location), 1, GL_FALSE, glm::value_ptr(data));
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