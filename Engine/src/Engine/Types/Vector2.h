#pragma once

#include "../Core.h"
#include "../Internal/vector.h"

namespace Engine
{
	/// <summary>
	/// A simple vector with two elements. Provides some basic operations.
	/// </summary>
	class ENGINE_API Vector2
	{
	private:
		Internal::Vector<float> m_vector = Internal::Vector<float>(2);

	public:
		Vector2(float x, float y);
		Vector2(float value);
		Vector2();
		Vector2(const Vector2& other);

		Vector2& operator=(Vector2 other);

		Vector2 operator*(float scalar) const;

		Vector2 operator+(const Vector2& other) const;

		~Vector2() = default;

	public:
		float& X;
		float& Y;
	};
}
