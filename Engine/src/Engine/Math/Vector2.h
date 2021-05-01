#pragma once

#include "../Core.h"
#include "vector.h"

namespace Engine
{
	class ENGINE_API Vector2
	{
	public:
		Vector2(float x, float y);
		Vector2(float value);
		Vector2(const Vector2& other);

		Vector2& operator=(Vector2 other);

		~Vector2() = default;

	public:
		float& X;
		float& Y;		

	private:
		Vector<float> m_vector = Vector<float>(2);
	};
}
