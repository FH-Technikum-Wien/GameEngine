#include "Rectangle.h"

#include "../RenderSystem.h"

namespace Engine::Rendering
{
	Rectangle::Rectangle(Vector2 size, Vector2 position, Color color) : Shape(position, color)
	{
		m_size = size;

		float xNormalized = size.X / 1280.0f;
		float yNormalized = size.Y / 720.0f;

		m_vertices = new float[12]{
			-xNormalized,  yNormalized,
			-xNormalized, -yNormalized,
			 xNormalized, -yNormalized,
			-xNormalized,  yNormalized,
			 xNormalized, -yNormalized,
			 xNormalized,  yNormalized,
		};

		m_indices = new unsigned int[6]{
			0,1,2,
			3,4,5
		};

		m_vertexCount = 6;
		m_indexCount = 6;

		Initialize();
	}
}
