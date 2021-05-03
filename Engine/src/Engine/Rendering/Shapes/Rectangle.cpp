#include "Rectangle.h"

namespace Engine::Rendering::Shapes
{
	Rectangle::Rectangle(const Vector2& position, const Vector2& size, const Color& color)
	{
		SetPosition(position);
		SetSize(size);
		SetColor(color);
	}

	void Rectangle::Draw(sf::RenderWindow* window) const
	{
		window->draw(m_shape);
	}

	void Rectangle::SetPosition(const Vector2& position)
	{
		m_position = position;
		m_shape.setPosition(position.X, position.Y);
	}	

	const Vector2& Rectangle::GetPosition() const
	{
		return m_position;
	}

	void Rectangle::SetColor(const Color& color)
	{
		m_color = color;
		m_shape.setFillColor(sf::Color(color.R, color.G, color.B, color.A));
	}

	const Color& Rectangle::GetColor() const
	{
		return m_color;
	}

	void Rectangle::SetSize(const Vector2& size)
	{
		m_size = size;
		m_shape.setSize(sf::Vector2f(size.X, size.Y));
	}

	const Vector2& Rectangle::GetSize() const
	{
		return m_size;
	}
}