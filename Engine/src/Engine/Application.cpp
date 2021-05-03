#include "Application.h"

#include <chrono>
#include "Logging/Log.h"

namespace Engine
{

	Application::Application()
	{
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
			m_renderSystem->Render();
		}
	}

	void Application::Update(float deltaTime)
	{
	}

	void Application::FixedUpdate(float fixedDeltaTime)
	{
	}
}
