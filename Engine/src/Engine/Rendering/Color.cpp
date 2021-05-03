#include "Color.h"

namespace Engine
{
	Engine::Color::Color(float r, float g, float b, float a) : R(m_vector[0]), G(m_vector[1]), B(m_vector[2]), A(m_vector[3])
	{
		m_vector[0] = r;
		m_vector[1] = g;
		m_vector[2] = b;
		m_vector[3] = a;
	}

	Color::Color() : Color(0, 0, 0)
	{
	}

	Color::Color(const Color& other) : m_vector(other.m_vector), R(m_vector[0]), G(m_vector[1]), B(m_vector[2]), A(m_vector[3])
	{
	}

	Color& Color::operator=(Color other)
	{
		m_vector = other.m_vector;
		return *this;
	}
	const Color& Color::GetAs255() const
	{
		return Color(R * 255, G * 255, B * 255, A * 255);
	}
}