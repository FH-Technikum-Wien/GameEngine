#pragma once
#include "../Core.h"

#include "Drawable.h"
#include "RenderWindow.h"
#include <vector>

namespace Engine::Rendering
{
	class ENGINE_API RenderSystem
	{
	public:
		RenderSystem() = default;

		void InitializeWindow(unsigned int width, unsigned int height, const std::string& title);

		void UpdateWindow() const;
		void Render() const;
		void Add(Drawable* drawable);

	private:
		std::vector<Drawable*> m_drawables = std::vector<Drawable*>();
		RenderWindow* m_window = nullptr;
	};
}

