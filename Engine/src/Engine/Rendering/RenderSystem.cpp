#include "RenderSystem.h"

namespace Engine::Rendering
{
	void RenderSystem::InitializeWindow(unsigned int width, unsigned int height, const std::string& title)
	{
		m_window = new RenderWindow(width, height, title);
	}

	void RenderSystem::Render() const
	{
		for (Drawable* drawable : m_drawables)
		{
			m_window->Render(drawable);
		}
	}

	void RenderSystem::AddDrawable(Drawable* drawable)
	{
		m_drawables.push_back(drawable);
	}
}
