#pragma once
#include "Core.h"

#include <memory>
#include "Rendering/RenderSystem.h"
#include "Physics/PhysicsSystem.h"
#include "Input/InputSystem.h"

namespace Engine {

	class ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	protected:
		virtual void Update(float deltaTime);
		virtual void FixedUpdate(float fixedDeltaTime);

	protected:
		std::unique_ptr<Rendering::RenderSystem> m_renderSystem = std::make_unique<Rendering::RenderSystem>();
		std::unique_ptr<Physics::PhysicsSystem> m_phyisicsSystem = std::make_unique<Physics::PhysicsSystem>();
		std::unique_ptr<Input::InputSystem> m_inputSystem = std::make_unique<Input::InputSystem>();

		const float FIXED_DELTA_TIME = 1.0f / 100.0f;
		const float UPDATE_LIMIT = 1.0f / 60.0f;
	};

	// Needs to be defined in the Client/Application
	Application* CreateApplication();
}

