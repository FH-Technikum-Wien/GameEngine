#pragma once
#include "../../Core.h"

#include "Shape.h"

namespace Engine::Rendering
{
	class ENGINE_API Rectangle : public Shape
	{
	public:
		Rectangle(Vector2 size, Vector2 position, Color color);

	private:
		Vector2 m_size;
	};
}

