#pragma once
#include "../Core.h"
#include "../Rendering/Drawable.h"
#include "../Physics/Transformable.h"

namespace Engine::Shapes
{
	/// <summary>
	/// Allows to display and move a rectangle on the screen. The rectangle has a position, a color and a velocity at which it moves.
	/// <para>
    /// Represents a wrapper for the SFML rectangle element.
    /// </para>
	/// </summary>
	class ENGINE_API Rectangle : public Rendering::Drawable, public Physics::Transformable
	{
	public:
		/// <summary>
		/// Creates a rectangle at the given position with the given size and color.
		/// </summary>
		/// <param name="position">- The position of the rectangle in pixels.</param>
		/// <param name="size">- The size of the rectangle in pixels.</param>
		/// <param name="color">- The color of the rectangle.</param>
		Rectangle(const Vector2& position, const Vector2& size, const Color& color);

		/// <summary>
		/// Draws the rectangle to the given RenderWindow.
		/// </summary>
		/// <param name="window">- The window to render to.</param>
		/// <param name="stateBlending">- Allows the interpolation of variables to compensate stutter due to difference in System Framerates.</param>
		void Draw(sf::RenderWindow* window, const float stateBlending) override;

		/// <summary>
		/// Sets the (fill) color of the rectangle.
		/// </summary>
		/// <param name="position">- The new color.</param>
		void SetColor(const Color& position) override;

		/// <summary>
		/// Gets the (fill) color of the rectangle.
		/// </summary>
		const Color& GetColor() const override;

		/// <summary>
		/// Sets the size of the rectangle.
		/// </summary>
		/// <param name="size">- The new size in pixels.</param>
		void SetSize(const Vector2& size);

		/// <summary>
		/// Gets the current size of the rectangle.
		/// </summary>
		const Vector2& GetSize() const;

		/// <summary>
		/// Transforms the rectangle, e.g. moves it with it's current velocity.
		/// </summary>
		/// <param name="fixedDeltaTime">- The fixed time step used for the transformation calculation.</param>
		void Transform(const float fixedDeltaTime) override;

		/// <summary>
		/// Sets the position of the rectangle. This is instant, no interpolation will be applied.
		/// </summary>
		/// <param name="position">- The new position of the rectangle in pixels.</param>
		void SetPosition(const Vector2& position) override;

		/// <summary>
		/// Gets the current position of the rectangle.
		/// </summary>
		const Vector2& GetPosition() const override;

		/// <summary>
		/// Sets the velocity of the rectangle.
		/// </summary>
		/// <param name="velocity">- The new velocity in pixels per second.</param>
		void SetVelocity(const Vector2& velocity) override;

		/// <summary>
		/// Gets the current velocity of the rectangle.
		/// </summary>
		const Vector2& GetVelocity() const override;

		

	private:
		// The position of rectangle from the last frame.
		Vector2 m_previousPosition;
		// The current position of the rectangle.
		Vector2 m_position;
		// The velocity of the rectangle.
		Vector2 m_velocity;
		// The size of the rectangle.
		Vector2 m_size;
		// The (fill) color of the rectangle.
		Color m_color;
		// The internal SFML rectangle element.
		sf::RectangleShape m_shape;
	};
}

