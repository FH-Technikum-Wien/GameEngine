#pragma once

#include "../Core.h"
#include "vector.h"

#include <cstdint>

namespace Engine
{
	class ENGINE_API Color
	{
	private:
		Vector<float> m_vector = Vector<float>(4);

	public:
		Color(float r, float g, float b, float a = 1.0f);

		Color();

		Color(const Color& other);

		Color& operator=(Color other);

		const Color& GetAs255() const;

		~Color() = default;

	public:
		float& R;
		float& G;
		float& B;
		float& A;
	};
}

