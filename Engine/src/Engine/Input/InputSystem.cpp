#include "InputSystem.h"
#include "../Application.h"

namespace Engine::Input
{
	void InputSystem::SetOnMouseClick(std::function<void(const Vector2& position)> function)
	{
		m_onMouseClick = function;
	}

	void InputSystem::SetOnMouseMoved(std::function<void(const Vector2& position)> function)
	{
		m_onMouseMoved = function;
	}

	void InputSystem::PollWindowEvents(Rendering::RenderWindow* window) const
	{
		Rendering::RenderWindow::Event event;
		// Poll all events and handle them.
		while (window->PollEvent(event))
		{
			switch (event.Type)
			{
			case Rendering::RenderWindow::EventType::CLOSE:
				window->Close();
				Application::IsRunning = false;
				break;
			case Rendering::RenderWindow::EventType::MOUSE_BUTTON_PRESSED:
				m_onMouseClick(event.Mouse.Position);
				break;
			case Rendering::RenderWindow::EventType::MOUSE_MOVED:
				m_onMouseMoved(event.Mouse.Position);
				break;
			default:
				break;
			}
		}
	}
}
