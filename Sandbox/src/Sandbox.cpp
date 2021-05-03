#include <Engine.h>

#include <Engine/Rendering/Shapes/Rectangle.h>
#include <Engine/Rendering/Texts/Text.h>

class Sandbox : public Engine::Application
{
public:
	Sandbox();
	~Sandbox()
	{
	};
};

Engine::Application* Engine::CreateApplication()
{
	return new Sandbox();
}

Sandbox::Sandbox()
{
	m_renderSystem->InitializeWindow(1024, 512, "Engine");

	Engine::Rendering::Shapes::Rectangle* rect = new Engine::Rendering::Shapes::Rectangle(Engine::Vector2(256, 64), Engine::Vector2(512, 64), Engine::Color(100, 100, 100, 255));
	m_renderSystem->AddDrawable(rect);
	Engine::Rendering::Texts::Text* text = new Engine::Rendering::Texts::Text(Engine::Vector2(256,64), Engine::Color(255,255,255), "ENGINE", 72);
	m_renderSystem->AddDrawable(text);
}