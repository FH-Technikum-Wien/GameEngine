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
		event.Type = static_cast<EventType>(sfEvent.type);
		
		switch (event.Type)
		{
		case EventType::MOUSE_BUTTON_PRESSED:
			event.Mouse.Position = Vector2(sfEvent.mouseButton.x, sfEvent.mouseButton.y);
			break;
		case EventType::MOUSE_BUTTON_RELEASED:
			break;
		case EventType::MOUSE_MOVED:
			event.Mouse.Position = Vector2(sfEvent.mouseMove.x, sfEvent.mouseMove.y);
			break;
		default:
			break;
		}

		return polled;
	}

	void RenderWindow::Close()
	{
		m_sfWindow->close();
	}

}
