#pragma once
#include "../Core.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>
#include "../Types/Color.h"

namespace Engine::Rendering
{
	class ENGINE_API Window
	{	

	public:
		Window(unsigned int width, unsigned int height, const std::string& title);
		~Window();

		void SetBackgroundColor(Color color);
		void HandleInput();

		bool WindowShouldClose() const;
		void Clear() const;
		void Show() const;
		void Close();
		void PollEvents();
		void PrintError() const;

		GLFWwindow* m_window;
	private:

		Color m_backgroundColor;
	};
}

