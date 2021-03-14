#pragma once

#ifdef ENGINE_PLATFORM_WINDOWS

// Will be defined in the application
extern Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{
	// TODO: Move to ENGINE INIT
	Engine::Log::Init();
	ENGINE_CORE_WARN("Initialized Log!");
	int a = 5;
	ENGINE_INFO("Hello! Var={0}", a);

	Engine::Application* application = Engine::CreateApplication();
	application->Run();
	delete application;
}

#endif // ENGINE_PLATFORM_WINDOWS

