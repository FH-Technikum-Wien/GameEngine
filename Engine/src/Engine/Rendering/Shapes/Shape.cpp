#include "Shape.h"

namespace Engine::Rendering
{
	Shape::Shape(const Vector2& position, const Color& color)
	{
		m_position = position;
		m_color = color;
	}

	Shape::~Shape()
	{
		delete[] m_vertices;
		delete[] m_indices;
	}

	void Shape::Render(const Shader& shader) const
	{
		glBindVertexArray(m_VAO);
		shader.setVec2("position", m_position);
		shader.setColor("color", m_color);

		glBindBuffer(GL_ARRAY_BUFFER, m_VBO_VERTICES);
		glDrawElements(GL_TRIANGLES, m_indexCount, GL_UNSIGNED_INT, 0);
	}

	void Shape::Initialize()
	{
		glGenVertexArrays(1, &m_VAO);
		glBindVertexArray(m_VAO);

		glGenBuffers(1, &m_VBO_VERTICES);
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO_VERTICES);

		glBufferData(GL_ARRAY_BUFFER, (m_vertexCount * 2) * sizeof(float), m_vertices, GL_STATIC_DRAW);

		// POSITION
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// Vertex indices
		glGenBuffers(1, &m_EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indexCount * sizeof(unsigned int), m_indices, GL_STATIC_DRAW);

		glBindVertexArray(0);
	}
}
