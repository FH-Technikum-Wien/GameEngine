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
		LOG_TRACE("Application Run");
		std::chrono::high_resolution_clock clock;
		auto lastFrameTime = clock.now();

		float leftOver = 0.0f;
		while (1)
		{
			// Calculate deltaTime in seconds
			auto currentFrameTime = clock.now();
			float deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(currentFrameTime - lastFrameTime).count() / 1000000.0f;
			lastFrameTime = currentFrameTime;

			// Produced time that FixedUpdate consumes 
			leftOver += deltaTime;
			// Repeat physics updates as long as there is time remaining
			while (leftOver >= FIXED_DELTA_TIME)
			{
				// Calculate internal physics
				m_phyisicsSystem->Update(FIXED_DELTA_TIME, leftOver / FIXED_DELTA_TIME);

				// Execute FixedUpdate
				FixedUpdate(FIXED_DELTA_TIME);

				// Reduce leftOver by used time
				leftOver -= FIXED_DELTA_TIME;
			}

			// Execute Update
			Update(deltaTime);

			// Render everything
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
