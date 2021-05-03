#include "Application.h"
#include <chrono>
#include "Logging/Log.h"

namespace Engine
{
	Application::Application()
	{
		m_shader.AddShader(SAMPLE_VERTEX_SHADER, Engine::Rendering::Shader::VERTEX_SHADER);
		m_shader.AddShader(SAMPLE_FRAGMENT_SHADER, Engine::Rendering::Shader::VERTEX_SHADER);
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		LOG_TRACE("Application Running.");
		std::chrono::high_resolution_clock clock;
		auto lastFrameTime = clock.now();
		while (1)
		{
			// Calculate deltaTime
			auto currentFrameTime = clock.now();
			auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentFrameTime - lastFrameTime).count() / 1000.0f;
			lastFrameTime = currentFrameTime;

			float fixedDeltaTime = 0.01f;

			// Execute User Updates
			Update(deltaTime);
			FixedUpdate(fixedDeltaTime);

			// Update systems
			m_physicsSystem->Update(fixedDeltaTime);
			m_renderSystem->Render(m_shader);
		}
	}

	void Application::Update(float deltaTime)
	{
	}

	void Application::FixedUpdate(float fixedDeltaTime)
	{
	}
}
