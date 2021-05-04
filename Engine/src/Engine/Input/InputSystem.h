#pragma once
#include "../Core.h"

#include "../Rendering/RenderWindow.h"
#include "../Types/Vector2.h"

#include <functional>

namespace Engine::Input
{
	/// <summary>
	/// Handles window events and user inputs.
	/// </summary>
	class ENGINE_API InputSystem
	{
	public:
		/// <summary>
		/// Subscribes the given function to the mouse click event.
		/// </summary>
		/// <param name="function">- The function to execute on mouse click.</param>
		void SetOnMouseClick(std::function<void(const Vector2& position)> function);

		/// <summary>
		/// Subscribes the given function to the mouse move event.
		/// </summary>
		/// <param name="function">- The function to execute on mouse move.</param>
		void SetOnMouseMoved(std::function<void(const Vector2& position)> function);

		/// <summary>
		/// Polls all window events. Should be called once per frame.
		/// </summary>
		/// <param name="window"></param>
		void PollWindowEvents(Rendering::RenderWindow* window) const;

	private:
		// The function to execute on mouse click.
		std::function<void(const Vector2& position)> m_onMouseClick;
		// The function to execute on mouse move.
		std::function<void(const Vector2& position)> m_onMouseMoved;
	};
}

