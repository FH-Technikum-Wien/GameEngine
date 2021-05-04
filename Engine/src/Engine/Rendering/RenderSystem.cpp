#include "RenderSystem.h"

namespace Engine::Rendering
{
	void RenderSystem::InitializeWindow(unsigned int width, unsigned int height, const std::string& title)
	{
		m_window = new RenderWindow(width, height, title);
	}

	void RenderSystem::Render(const float stateBlending) const
	{
		m_window->Clear();

		for (Drawable* drawable : m_drawables)
		{
			m_window->Draw(drawable, stateBlending);
		}

		m_window->Show();
	}

	void RenderSystem::Add(Drawable* drawable)
	{
		m_drawables.push_back(drawable);
	}
	RenderWindow* RenderSystem::GetRenderWindow() const
	{
		return m_window;
	}
}
