#pragma once

#include "../Core.h"
#include "vector.h"

#include <cstdint>

namespace Engine
{
	class ENGINE_API Color
	{
	private:
		Vector<unsigned char> m_vector = Vector<unsigned char>(4);

	public:
		Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255);

		Color();

		Color(const Color& other);

		Color& operator=(Color other);

		~Color() = default;

	public:
		unsigned char& R;
		unsigned char& G;
		unsigned char& B;
		unsigned char& A;
	};
}

