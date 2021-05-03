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
		RenderWindow(unsigned int width, unsigned int height, const std::string& title);

		void Render(Drawable* drawable);

	private:
		sf::RenderWindow* m_sfWindow;
	};
}

