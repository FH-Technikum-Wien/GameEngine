#pragma once

#include "../Core.h"
#include "vector.h"

#include <cstdint>

typedef std::uint8_t uint8;

namespace Engine
{
	class ENGINE_API Color
	{
	public:
		Color(uint8 r, uint8 g, uint8 b, uint8 a = 255);
		Color(const Color& other);

		Color& operator=(Color other);

		~Color() = default;

	public:
		uint8& R;
		uint8& G;
		uint8& B;
		uint8& A;

	private:
		Vector<uint8> m_vector = Vector<uint8>(4);
	};
}

