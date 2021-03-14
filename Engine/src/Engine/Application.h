#pragma once

#include "Core.h"

namespace Engine {

	class ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Needs to be defined in the Client/Application
	Application* CreateApplication();
}

