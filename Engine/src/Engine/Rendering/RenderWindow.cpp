#include "RenderWindow.h"

namespace Engine::Rendering
{
	RenderWindow::RenderWindow(unsigned int width, unsigned int height, const std::string& title)
	{
		m_sfWindow = new sf::RenderWindow(sf::VideoMode(width, height), title.c_str());
	}

	void RenderWindow::Render(Drawable* drawable)
	{
		drawable->Draw(m_sfWindow);
	}

}
