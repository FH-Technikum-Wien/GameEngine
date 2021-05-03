#include "Vector3.h"

namespace Engine
{
	Vector3::Vector3(float x, float y, float z) : X(m_vector[0]), Y(m_vector[1]), Z(m_vector[2])
	{
		m_vector[0] = x;
		m_vector[1] = y;
		m_vector[2] = z;
	}

	Vector3::Vector3(float value) : Vector3::Vector3(value, value, value)
	{
	}

	Vector3::Vector3() : Vector3::Vector3(0, 0, 0)
	{
	}

	Vector3::Vector3(const Vector3& other) : m_vector(other.m_vector), X(m_vector[0]), Y(m_vector[1]), Z(m_vector[2])
	{
	}
	Vector3& Vector3::operator=(Vector3 other)
	{
		m_vector = other.m_vector;
		return *this;
	}
}
