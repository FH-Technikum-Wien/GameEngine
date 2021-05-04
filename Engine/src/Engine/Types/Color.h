#pragma once

#include "../Core.h"
#include "../Internal/vector.h"

#include <cstdint>

namespace Engine
{
	/// <summary>
	/// A simple vector with four elements representing a color (RGBA).
	/// <para>
	/// The range [0,1] represents the RGBA values [0,255], which this can be converted to using GetAs255().
	/// </para>
	/// </summary>
	class ENGINE_API Color
	{
	private:
		Internal::Vector<float> m_vector = Internal::Vector<float>(4);

	public:
		Color(float r, float g, float b, float a = 1.0f);

		Color();

		Color(const Color& other);

		Color& operator=(Color other);

		/// <summary>
		/// Returns this color with its values between 0 and 255.
		/// </summary>
		/// <returns> The color as values between 0 adn 255.</returns>
		Color GetAs255() const;

		~Color() = default;

	public:
		float& R;
		float& G;
		float& B;
		float& A;
	};
}

