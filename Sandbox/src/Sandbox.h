#pragma once

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

	void Update(float deltaTime) override;

private:
	void MoveRectangle(float deltaTime);
	void CalculateFPS(float deltaTime);

private:
	Engine::Rendering::Shapes::Rectangle* m_movingRect;
	Engine::Rendering::Texts::Text* m_deltaTime;
	Engine::Rendering::Texts::Text* m_frameRate;

	bool goRight = true;

	float fpsDeltaTime = 0.0f;
	unsigned int fpsFrames = 0;
	float fpsFrameRate = 0.0f;
	double fpsAverageFrameTime = 0.0f;
	Engine::Color m_color;
	const float PI = 3.14159265f;
};

Engine::Application* Engine::CreateApplication()
{
	return new Sandbox();
}
