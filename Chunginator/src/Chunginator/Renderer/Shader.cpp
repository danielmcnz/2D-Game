#include "Renderer/Shader.h"

#ifdef CGR_OPENGL
	#include "OpenGL/OpenGLShader.h"
#endif

namespace CGR
{
	Shader* Shader::Create(std::string vertexPath, std::string fragmentPath)
	{
	#ifdef CGR_OPENGL
		return new OpenGLShader(vertexPath, fragmentPath);
	#endif
	}

	std::string Shader::LoadShader(std::string shaderPath)
	{
		std::fstream file(shaderPath);
		std::stringstream ss;
		std::string line;

		while (std::getline(file, line))
		{
			ss << line << "\n";
		}

		return ss.str();
	}
}