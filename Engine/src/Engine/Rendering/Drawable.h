#pragma once
#include "../Core.h"
#include "../Types/Color.h"

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
		/// Draws the object to the given render window.
		/// </summary>
		/// <param name="window">- The window to render to.</param>
		/// <param name="stateBlending">- Allows the interpolation of variables to compensate stutter due to difference in System Framerates.</param>
		virtual void Draw(sf::RenderWindow* window, const float stateBlending) = 0;

		/// <summary>
		/// Sets the color of the drawable.
		/// </summary>
		/// <param name="position">- The new color of the drawable.</param>
		virtual void SetColor(const Color& color) = 0;

		/// <summary>
		/// Gets the color of the drawable.
		/// </summary>
		virtual const Color& GetColor() const = 0;
	};
}