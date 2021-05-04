#pragma once
#include "../Core.h"

#include <string>
#include <SFML/Graphics.hpp>
#include "Drawable.h"

namespace Engine::Rendering
{
	class ENGINE_API RenderWindow
	{
	public:
		enum EventType
		{
			CLOSE
		};
		struct Event
		{
			EventType type;
		};

	public:
		RenderWindow(unsigned int width, unsigned int height, const std::string& title);

		void Draw(Drawable* drawable, const float stateBlending);
		void Show();
		void Clear();
		bool PollEvent(Event& event);
		void Close();

	private:
		sf::RenderWindow* m_sfWindow;
	};
}

