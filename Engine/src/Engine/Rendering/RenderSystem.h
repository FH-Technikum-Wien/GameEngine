#pragma once
#include "../Core.h"

#include "Drawable.h"
#include "RenderWindow.h"
#include <vector>

namespace Engine::Rendering
{
	/// <summary>
	/// Draws elements.
	/// </summary>
	class ENGINE_API RenderSystem
	{
	public:
		RenderSystem() = default;

		/// <summary>
		/// Creates the RenderWindow with the given width, height and title.
		/// </summary>
		/// <param name="width">- The width of the window.</param>
		/// <param name="height">- The height of the window.</param>
		/// <param name="title">- The title of the window.</param>
		void InitializeWindow(unsigned int width, unsigned int height, const std::string& title);

		/// <summary>
		/// Renders all elements to the RenderWindow.
		/// </summary>
		/// <param name="stateBlending">- Allows the interpolation of variables to compensate stutter due to difference in GameSystem Framerates.</param>
		void Render(const float stateBlending) const;

		/// <summary>
		/// Adds a new drawable to the render list.
		/// </summary>
		/// <param name="drawable"> The drawable to render.</param>
		void Add(Drawable* drawable);

		/// <summary>
		/// Gets the RenderWindow.
		/// </summary>
		RenderWindow* GetRenderWindow() const;

	private:
		// All elements to render.
		std::vector<Drawable*> m_drawables = std::vector<Drawable*>();
		// The RenderWindow to render to.
		RenderWindow* m_window = nullptr;
	};
}

