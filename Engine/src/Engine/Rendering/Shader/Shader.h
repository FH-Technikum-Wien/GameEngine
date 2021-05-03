#pragma once
#include "../../Core.h"

#include <glad\glad.h>
#include <GLFW/glfw3.h>

#include "../../Math/Math.h"
#include "../../Types/Color.h"
#include <string>

namespace Engine::Rendering
{
	class ENGINE_API Shader
	{
	public:
		enum ShaderType
		{
			VERTEX_SHADER = GL_VERTEX_SHADER,
			FRAGMENT_SHADER = GL_FRAGMENT_SHADER,
			GEOMETRY_SHADER = GL_GEOMETRY_SHADER
		};
	public:
		// ID of the program
		unsigned int shaderProgramID = -1;

		Shader() = default;

		Shader(const char* vertexShaderPath, const char* fragmentShaderPath);

		~Shader();

		void AddShader(const char* shaderPath, ShaderType type);

		void activate() const;

		void setBool(const std::string& name, bool value) const;
		void setInt(const std::string& name, int value) const;
		void setFloat(const std::string& name, float value) const;
		void setVec2(const std::string& name, Vector2 value) const;
		void setVec3(const std::string& name, Vector3 value) const;
		void setColor(const std::string& name, Color value) const;

		static std::string readFile(const char* filePath);
	};
}
