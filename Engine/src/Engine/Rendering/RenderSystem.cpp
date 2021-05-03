#include "RenderSystem.h"

namespace Engine::Rendering
{
	void RenderSystem::InitializeWindow(unsigned int width, unsigned int height, const std::string& title)
	{
		m_window = new RenderWindow(width, height, title);
	}

	void RenderSystem::Render() const
	{
		RenderWindow::Event event;
		while (m_window->PollEvent(event))
		{
			if (event.type == RenderWindow::EventType::CLOSE)
				m_window->Close();
		}

		m_window->Clear();


		for (Drawable* drawable : m_drawables)
		{
			m_window->Draw(drawable);
		}

		m_window->Show();
	}

	void RenderSystem::AddDrawable(Drawable* drawable)
	{
		m_drawables.push_back(drawable);
	}
}
