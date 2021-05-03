#pragma once
#include "../Core.h"

#include <vector>

#include "Shapes\Shape.h"
#include "Window.h"

namespace Engine::Rendering
{
	class ENGINE_API RenderSystem
	{
	public:
		RenderSystem();
		~RenderSystem();

		void InitializeWindow(unsigned int width, unsigned int height, const std::string& title);
		void Render(const Shader& shader);
		void AddShape(const Shape& shape);

	public:
		float WINDOW_WIDTH;
		float WINDOW_HEIGHT;

	private:
		Window* m_window = nullptr;
		std::vector<Shape> m_shapes;
	};
}
