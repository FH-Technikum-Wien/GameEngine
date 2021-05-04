#pragma once
#include "Core.h"

#include <memory>
#include "Rendering/RenderSystem.h"
#include "Physics/PhysicsSystem.h"
#include "Input/InputSystem.h"

namespace Engine {

	/// <summary>
	/// Base class for any application. 
	/// Provides an Update() and a FixedUpdate() method which are called parallel to the rendering and the physics calculation respectively.
	/// <para>
	/// Provides currently three systems: RenderSystem, PhysicsSystem and InputSystem.
	/// </para>
	/// </summary>
	class ENGINE_API Application
	{
	public:
		// Whether the application should run.
		inline static bool IsRunning;

	public:
		Application();
		virtual ~Application();

		/// <summary>
		/// The Main Loop of the application.
		/// </summary>
		void Run();

	protected:

		/// <summary>
		/// Will be called every rendering frame with the time that the last frame took as deltaTime.
		/// </summary>
		/// <param name="deltaTime">- The time the previous frame took in seconds.</param>
		virtual void Update(float deltaTime);

		/// <summary>
		/// Will be called every physics calculation frame with the fixed physics step size as fixedDeltaTime.
		/// </summary>
		/// <param name="fixedDeltaTime">- The fixed step size in seconds.</param>
		virtual void FixedUpdate(float fixedDeltaTime);

	protected:
		// The fixed time step used for the physics calculation.
		const float FIXED_DELTA_TIME = 1.0f / 100.0f;
		// The limit for the render and update frame rate.
		const float UPDATE_LIMIT = 1.0f / 60.0f;

		// The RenderSystem. Used for rendering elements, such as text or shapes.
		std::unique_ptr<Rendering::RenderSystem> m_renderSystem = std::make_unique<Rendering::RenderSystem>();
		// The PhysicsSystem. Used for calculating the game physics and movements.
		std::unique_ptr<Physics::PhysicsSystem> m_phyisicsSystem = std::make_unique<Physics::PhysicsSystem>();
		// The InputSystem. Used for checking input events and reacting on them.
		std::unique_ptr<Input::InputSystem> m_inputSystem = std::make_unique<Input::InputSystem>();

		
	};

	// Needs to be defined in the Client/Application
	Application* CreateApplication();
}

