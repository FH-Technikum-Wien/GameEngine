#pragma once
#include "../Core.h"
#include "../Math/Vector2.h"
#include "Color.h"

#include <SFML/Graphics.hpp>

namespace Engine::Rendering
{
	class ENGINE_API Drawable
	{
	public:
		/// <summary>
		/// Draws the object with the given render window.
		/// </summary>
		virtual void Draw(sf::RenderWindow* window) const = 0;

		virtual void SetPosition(const Vector2& position) = 0;
		virtual const Vector2& GetPosition() const = 0;

		virtual void SetColor(const Color& position) = 0;
		virtual const Color& GetColor() const = 0;
	};
}