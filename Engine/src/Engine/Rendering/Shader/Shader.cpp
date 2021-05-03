#include "Shader.h"

#include <fstream>
#include <sstream>
#include "../../Logging/Log.h"

namespace Engine::Rendering
{
	Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath)
	{
		AddShader(vertexShaderPath, ShaderType::VERTEX_SHADER);
		AddShader(fragmentShaderPath, ShaderType::FRAGMENT_SHADER);
	}

	Shader::~Shader()
	{
		glDeleteShader(shaderProgramID);
	}

	void Shader::AddShader(const char* shaderPath, ShaderType type)
	{
		std::string shaderString = readFile(shaderPath);

		const char* shaderCode = shaderString.c_str();

		int success;
		char infoLog[512];

		// Create shader Object
		unsigned int shader;
		shader = glCreateShader(type);
		if (shaderProgramID == -1)
			shaderProgramID = glCreateProgram();

		// Attach shader source to shader object
		glShaderSource(shader, 1, &shaderCode, nullptr);
		// Compile shader (at run-time)
		glCompileShader(shader);
		// Check compilation
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, nullptr, infoLog);
			std::string error = "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" + std::string(infoLog);
			LOG_CORE_ERROR(error);
		}

		// Shader program
		glAttachShader(shaderProgramID, shader);
		glLinkProgram(shaderProgramID);
		// Check compilation
		glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shaderProgramID, 512, nullptr, infoLog);
			std::string error = "ERROR::SHADER::PROGRAM::LINKING_ERROR\n" + std::string(infoLog);
			LOG_CORE_ERROR(error);
		}

		// Delete Shaders after linking, not needed anymore
		glDeleteShader(shader);
	}

	void Shader::activate() const
	{
		glUseProgram(shaderProgramID);
	}

	void Shader::setBool(const std::string& name, bool value) const
	{
		glUniform1i(glGetUniformLocation(shaderProgramID, name.c_str()), (int)value);
	}

	void Shader::setInt(const std::string& name, int value) const
	{
		glUniform1i(glGetUniformLocation(shaderProgramID, name.c_str()), value);
	}

	void Shader::setFloat(const std::string& name, float value) const
	{
		glUniform1f(glGetUniformLocation(shaderProgramID, name.c_str()), value);
	}

	void Shader::setVec2(const std::string& name, Vector2 value) const
	{
		glUniform2fv(glGetUniformLocation(shaderProgramID, name.c_str()), 1, &value.X);
	}

	void Shader::setVec3(const std::string& name, Vector3 value) const
	{
		glUniform3fv(glGetUniformLocation(shaderProgramID, name.c_str()), 1, &value.X);
	}

	void Shader::setColor(const std::string& name, Color value) const
	{
		glUniform4fv(glGetUniformLocation(shaderProgramID, name.c_str()), 1, &value.R);
	}

	std::string Shader::readFile(const char* filePath)
	{
		std::string content;
		std::ifstream fileStream(filePath, std::ios::in);

		if (!fileStream.is_open())
		{
			std::string error = "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ";
			LOG_CORE_ERROR(error);
			return "";
		}

		std::stringstream fileStringStream;
		// Read file's buffer into stream
		fileStringStream << fileStream.rdbuf();
		// Close file
		fileStream.close();

		return fileStringStream.str();
	}
}