#pragma once
#include "../Core.h"

#include "../Types/Vector2.h"

namespace Engine::Physics
{
	/// <summary>
	/// Required to transform an object.
	/// </summary>
	class ENGINE_API Transformable
	{
	public:
		/// <summary>
		/// Transforms the object by applying the movement/velocity.
		/// </summary>
		/// <param name="fixedDeltaTime">- The fixed delta time for the physics calculation.</param>
		virtual void Transform(const float fixedDeltaTime) = 0;

		/// <summary>
		/// Sets the velocity of the transformable.
		/// </summary>
		/// <param name="velocity">- The new velocity in pixels per second.</param>
		virtual void SetVelocity(const Vector2& velocity) = 0;

		/// <summary>
		/// Returns the velocity of the transformable.
		/// </summary>
		virtual const Vector2& GetVelocity() const = 0;

		/// <summary>
		/// Sets the position of the object.
		/// </summary>
		/// <param name="position">- The new position in pixels.</param>
		virtual void SetPosition(const Vector2& position) = 0;

		/// <summary>
		/// Returns the position of the transformable.
		/// </summary>
		virtual const Vector2& GetPosition() const = 0;		

		
	};
}