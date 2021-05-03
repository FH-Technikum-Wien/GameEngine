#include "Vector2.h"

namespace Engine
{
	Vector2::Vector2(float x, float y) : X(m_vector[0]), Y(m_vector[1])
	{
		m_vector[0] = x;
		m_vector[1] = y;
	}

	Vector2::Vector2(float value) : Vector2::Vector2(value, value)
	{
	}

	Vector2::Vector2() : Vector2::Vector2(0, 0)
	{
	}

	Vector2::Vector2(const Vector2& other) : m_vector(other.m_vector), X(m_vector[0]), Y(m_vector[1])
	{
	}
	Vector2& Vector2::operator=(Vector2 other)
	{
		m_vector = other.m_vector;
		return *this;
	}
}