#pragma once
#include "../../Core.h"

#include "../Shader/Shader.h"
#include "../../Math/Math.h"
#include "../../Types/Color.h"

namespace Engine::Rendering
{
	class ENGINE_API Shape
	{
	public:
		Shape(const Vector2& position, const Color& color);
		~Shape();

		void Render(const Shader& shader) const;

		void SetPosition(const Vector2& position);
		const Vector2& GetPosition() const;

		void SetColor(const Color& color);
		const Color& GetColor() const;

	protected:
		void Initialize();

	protected:
		Vector2 m_position;
		Color m_color;

		float* m_vertices;
		unsigned int* m_indices;

		unsigned int m_vertexCount = 0;
		unsigned int m_indexCount = 0;

	private:
		unsigned int m_VAO = 0;
		unsigned int m_EBO = 0;
		unsigned int m_VBO_VERTICES = 0;

	};
}

