#include <Engine.h>
#include "Engine/Rendering/Shapes/Rectangle.h"

class Sandbox : public Engine::Application
{
public:
	Sandbox();
	~Sandbox() {}
};

Engine::Application* Engine::CreateApplication() 
{
	return new Sandbox();
}

Sandbox::Sandbox()
{
	m_renderSystem->InitializeWindow(1280, 720, "Engine");

	Engine::Rendering::Rectangle rect = Engine::Rendering::Rectangle(Engine::Vector2(100,100), Engine::Vector2(100, 100), Engine::Color(1.0f,1.0f,1.0f));
	m_renderSystem->AddShape(rect);
}