#include "RenderWindow.h"

namespace Engine::Rendering
{
	RenderWindow::RenderWindow(unsigned int width, unsigned int height, const std::string& title)
	{
		m_sfWindow = new sf::RenderWindow(sf::VideoMode(width, height), title.c_str());
	}

	void RenderWindow::Draw(Drawable* drawable, const float stateBlending)
	{
		drawable->Draw(m_sfWindow, stateBlending);
	}

	void RenderWindow::Show()
	{
		m_sfWindow->display();
	}

	void RenderWindow::Clear()
	{
		m_sfWindow->clear();
	}

	bool RenderWindow::PollEvent(Event& event)
	{
		sf::Event sfEvent;
		bool polled = m_sfWindow->pollEvent(sfEvent);
		event.type = static_cast<EventType>(sfEvent.type);
		return polled;
	}

	void RenderWindow::Close()
	{
		m_sfWindow->close();
	}

}
