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
		Application::IsRunning = true;

		std::chrono::high_resolution_clock clock;
		auto lastFrameTime = clock.now();

		double fixedUpdateAccumulator = 0.0f;
		double updateAccumulator = 0.0f;

		while (Application::IsRunning)
		{
			// Calculate deltaTime in seconds
			auto currentFrameTime = clock.now();
			double deltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(currentFrameTime - lastFrameTime).count() / 1e9;
			lastFrameTime = currentFrameTime;				

			// Produced time that can be consumed 
			fixedUpdateAccumulator += deltaTime;

			// Repeat physics updates as long as there is time remaining or skip it
			while (fixedUpdateAccumulator >= FIXED_DELTA_TIME)
			{
				// Calculate internal physics
				m_phyisicsSystem->Update(FIXED_DELTA_TIME);

				// Execute FixedUpdate
				FixedUpdate(FIXED_DELTA_TIME);

				// Reduce leftover time
				fixedUpdateAccumulator -= FIXED_DELTA_TIME;
			}

			// Update RenderWindow (polls events)
			m_inputSystem->PollWindowEvents(m_renderSystem->GetRenderWindow());

			updateAccumulator += deltaTime;
			if (updateAccumulator >= UPDATE_LIMIT)
			{
				// Execute Update
				Update(updateAccumulator);

				// Compensate stutter due to different frame rates
				const float stateBlending = fixedUpdateAccumulator / FIXED_DELTA_TIME;
				// Render everything
				m_renderSystem->Render(stateBlending);

				updateAccumulator = 0;
			}
		}
	}

	void Application::Update(float deltaTime)
	{
	}

	void Application::FixedUpdate(float fixedDeltaTime)
	{
	}
}
