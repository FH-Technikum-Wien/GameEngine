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

		float fixedUpdateAccumulator = 0.0f;
		float updateAccumulator = 0.0f;
		while (1)
		{
			// Calculate deltaTime in seconds
			auto currentFrameTime = clock.now();
			float deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(currentFrameTime - lastFrameTime).count() / 1000000.0f;
			lastFrameTime = currentFrameTime;

			//if (deltaTime > 0.25f)
			//	deltaTime = 0.25f;

			// Produced time that FixedUpdate consumes 
			fixedUpdateAccumulator += deltaTime;
			// Repeat physics updates as long as there is time remaining or skip it
			while (fixedUpdateAccumulator >= FIXED_DELTA_TIME)
			{
				// Calculate internal physics
				m_phyisicsSystem->Update(FIXED_DELTA_TIME);

				// Execute FixedUpdate
				FixedUpdate(FIXED_DELTA_TIME);

				// Reduce leftOver by used time
				fixedUpdateAccumulator -= FIXED_DELTA_TIME;
			}			

			// Compensate stutter due to different frame rates
			//m_phyisicsSystem->InterpolateLastPosition(fixedUpdateAccumulator / FIXED_DELTA_TIME);

			// Update RenderWindow (polls events)
			m_renderSystem->UpdateWindow();

			updateAccumulator += deltaTime;
			if (updateAccumulator >= UPDATE_LIMIT)
			{
				

				// Execute Update
				Update(deltaTime);

				// Render everything
				m_renderSystem->Render();

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
