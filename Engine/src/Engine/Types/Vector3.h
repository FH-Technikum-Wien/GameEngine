#pragma once

#include "../Core.h"
#include "vector.h"

namespace Engine
{
	class ENGINE_API Vector3
	{
	private:
		Vector<float> m_vector = Vector<float>(3);

	public:
		Vector3(float x, float y, float z);
		Vector3(float value);
		Vector3();
		Vector3(const Vector3& other);

		Vector3& operator=(Vector3 other);

		~Vector3() = default;

	public:
		float& X;
		float& Y;
		float& Z;


	};
}

