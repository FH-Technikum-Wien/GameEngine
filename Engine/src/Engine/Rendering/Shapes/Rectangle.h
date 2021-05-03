#pragma once
#include "../../Core.h"
#include "../Drawable.h"
#include "../../Physics/Transformable.h"

namespace Engine::Rendering::Shapes
{
	class ENGINE_API Rectangle : public Drawable, public Physics::Transformable
	{
	public:
		Rectangle(const Vector2& position, const Vector2& size, const Color& color);

		void Draw(sf::RenderWindow* window) const override;

		void SetColor(const Color& position) override;
		const Color& GetColor() const override;

		void SetSize(const Vector2& size);
		const Vector2& GetSize() const;

		void Transform(const float fixedDeltaTime) override;

		void InterpolateLastPosition(const float alpha) override;

		void SetPosition(const Vector2& position) override;
		const Vector2& GetPosition() const override;

		void SetVelocity(const Vector2& velocity) override;
		const Vector2& GetVelocity() const override;

		

	private:
		Vector2 m_previousPosition;
		Vector2 m_position;
		Vector2 m_velocity;

		Vector2 m_size;
		Color m_color;
		sf::RectangleShape m_shape;
	};
}

