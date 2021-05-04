#pragma once
#include "../Core.h"
#include "Color.h"

#include <SFML/Graphics.hpp>

namespace Engine::Rendering
{
	/// <summary>
	/// Required to draw an object.
	/// </summary>
	class ENGINE_API Drawable
	{
	public:
		/// <summary>
		/// Draws the object with the given render window.
		/// </summary>
		virtual void Draw(sf::RenderWindow* window, const float stateBlending) = 0;

		/// <summary>
		/// Sets the color of the drawable.
		/// </summary>
		virtual void SetColor(const Color& position) = 0;

		/// <summary>
		/// Gets the color of the drawable.
		/// </summary>
		virtual const Color& GetColor() const = 0;
	};
}