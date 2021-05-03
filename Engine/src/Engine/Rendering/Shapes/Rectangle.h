#pragma once
#include "../../Core.h"
#include "../Drawable.h"

namespace Engine::Rendering::Shapes
{
	class ENGINE_API Rectangle : public Drawable
	{
	public:
		Rectangle(const Vector2& position, const Vector2& size, const Color& color);

		void Draw(sf::RenderWindow* window) const override;

		void SetPosition(const Vector2& position) override;
		const Vector2& GetPosition() const override;

		void SetColor(const Color& position) override;
		const Color& GetColor() const override;

	private:
		Vector2 m_position;
		Color m_color;
		sf::RectangleShape m_shape;
	};
}

