#include "RenderSystem.h"

namespace Engine::Rendering
{
	RenderSystem::RenderSystem()
	{
	}

	RenderSystem::~RenderSystem()
	{
		delete[] m_window;
	}

	void RenderSystem::InitializeWindow(unsigned int width, unsigned int height, const std::string& title)
	{
		WINDOW_WIDTH = width;
		WINDOW_HEIGHT = height;
		m_window = new Window(width, height, title);
	}

	void RenderSystem::Render(const Shader& shader)
	{
		if (m_window == nullptr)
			return;

		m_window->HandleInput();
		m_window->Clear();
		

		for (const Shape& shape : m_shapes)
			shape.Render(shader);

		m_window->Show();
		m_window->PrintError();
	}

	void RenderSystem::AddShape(const Shape& shape)
	{
		m_shapes.push_back(shape);
	}
}