#pragma once
#include "../Core.h"

#include "../Math/Vector2.h"

namespace Engine::Physics
{
	class ENGINE_API Transformable
	{
	public:
		/// <summary>
		/// Transforms the object by applying the movement/velocity.
		/// </summary>
		/// <param name="fixedDeltaTime">- The fixed delta time for the physics calculation.</param>
		/// <param name="alpha">- The interpolation factor for the transformation.</param>
		virtual void Transform(const float fixedDeltaTime, const float alpha) = 0;

		/// <summary>
		/// Sets the position of the object.
		/// </summary>
		virtual void SetPosition(const Vector2& position) = 0;

		/// <summary>
		/// Returns the position of the transformable.
		/// </summary>
		virtual const Vector2& GetPosition() const = 0;

		/// <summary>
		/// Sets the velocity of the transformable.
		/// </summary>
		virtual void SetVelocity(const Vector2& velocity) = 0;

		/// <summary>
		/// Returns the velocity of the transformable.
		/// </summary>
		virtual const Vector2& GetVelocity() const = 0;
	};
}