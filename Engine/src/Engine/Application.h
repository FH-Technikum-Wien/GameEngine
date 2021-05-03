#pragma once
#include "Core.h"

#include <memory>
#include "Rendering/RenderSystem.h"
#include "Physics/PhysicsSystem.h"

namespace Engine
{
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
		std::unique_ptr<Physics::PhysicsSystem> m_physicsSystem = std::make_unique<Physics::PhysicsSystem>();
		
		Rendering::Shader m_shader;

	private:
		const char* SAMPLE_VERTEX_SHADER = "src/Engine/Rendering/Shader/sampleShader.vert";
		const char* SAMPLE_FRAGMENT_SHADER = "src/Engine/Rendering/Shader/sampleShader.frag";
	};

	// Needs to be defined in the Client/Application
	Application* CreateApplication();
}

