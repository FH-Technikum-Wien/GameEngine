#pragma once
#include "Core.h"

#include <memory>
#include "Rendering/RenderSystem.h"

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
	};

	// Needs to be defined in the Client/Application
	Application* CreateApplication();
}

