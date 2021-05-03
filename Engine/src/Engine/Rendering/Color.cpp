#include "Color.h"

namespace Engine
{
	Engine::Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a) : R(m_vector[0]), G(m_vector[1]), B(m_vector[2]), A(m_vector[3])
	{
		m_vector[0] = r;
		m_vector[1] = g;
		m_vector[2] = b;
		m_vector[2] = a;
	}

	Color::Color(const Color& other) : m_vector(other.m_vector), R(m_vector[0]), G(m_vector[1]), B(m_vector[2]), A(m_vector[2])
	{
	}
	Color& Color::operator=(Color other)
	{
		m_vector = other.m_vector;
		return *this;
	}
}