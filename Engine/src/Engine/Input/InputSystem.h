#pragma once
#include "../Core.h"

#include "../Rendering/RenderWindow.h"
#include "../Types/Vector2.h"

#include <functional>

namespace Engine::Input
{
	class ENGINE_API InputSystem
	{
	public:
		void SetOnMouseClick(std::function<void(const Vector2& position)> function);

		void SetOnMouseMoved(std::function<void(const Vector2& position)> function);

		void PollWindowEvents(Rendering::RenderWindow* window) const;

	private:
		std::function<void(const Vector2& position)> m_onMouseClick;
		std::function<void(const Vector2& position)> m_onMouseMoved;
	};
}

