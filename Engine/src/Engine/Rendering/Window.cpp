#include "Window.h"

#include <stdexcept>

#include "../Logging/Log.h"

namespace Engine::Rendering
{
	Window::Window(unsigned int width, unsigned int height, const std::string& title)
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		m_window = glfwCreateWindow(width, height, "", nullptr, nullptr);
		if (m_window == nullptr)
		{
			glfwTerminate();
			throw std::runtime_error("Failed to create the GLFW-Window");
		}
		glfwMakeContextCurrent(m_window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			throw std::runtime_error("Failed to initialize GLAD");
		}

		// Set OpenGL viewport.
		glViewport(0, 0, width, height);

	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::SetBackgroundColor(Color color)
	{
		m_backgroundColor = color;
	}

	void Window::HandleInput()
	{
		if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			Close();
	}

	bool Window::WindowShouldClose() const
	{
		return glfwWindowShouldClose(m_window);
	}

	void Window::Clear() const
	{
		glClearColor(m_backgroundColor.R, m_backgroundColor.G, m_backgroundColor.B, m_backgroundColor.A);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::Show() const
	{
		glfwSwapBuffers(m_window);
		// TODO: Move to seperate method
		glfwPollEvents();
	}

	void Window::Close()
	{			
		glfwSetWindowShouldClose(m_window, true);
	}

	void Window::PollEvents()
	{
		glfwPollEvents();
	}

	void Window::PrintError() const
	{
		GLenum error = glGetError();
		if (error != GL_NO_ERROR)
		{
			LOG_CORE_ERROR(error);
		}
	}
}