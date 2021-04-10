#pragma once

#ifdef ENGINE_PLATFORM_WINDOWS

// Will be defined in the application
extern Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{
	// TODO: Move to ENGINE INIT
	Engine::Log::Init();
	LOG_CORE_INFO("Engine Startup");

	Engine::Application* application = Engine::CreateApplication();
	application->Run();
	delete application;
}

#endif // ENGINE_PLATFORM_WINDOWS

