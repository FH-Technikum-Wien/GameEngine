#include "SandBox.h"
#include <cmath>

Sandbox::Sandbox()
{
	m_renderSystem->InitializeWindow(1024, 512, "Engine");

	Engine::Rendering::Texts::Text* text = new Engine::Rendering::Texts::Text(Engine::Vector2(384,50), Engine::Color(1.0f,1.0f,1.0f), "ENGINE", 72);
	m_renderSystem->AddDrawable(text);

	m_movingRect = new Engine::Rendering::Shapes::Rectangle(Engine::Vector2(256, 256), Engine::Vector2(64, 64), Engine::Color(1.0f, 0, 0, 1.0f));
	m_renderSystem->AddDrawable(m_movingRect);

	m_deltaTime = new Engine::Rendering::Texts::Text(Engine::Vector2(0, 40), Engine::Color(1.0f, 1.0f, 1.0f), "0", 36);
	m_renderSystem->AddDrawable(m_deltaTime);
	m_frameRate = new Engine::Rendering::Texts::Text(Engine::Vector2(0, 0), Engine::Color(1.0f, 1.0f, 1.0f), "0", 36);
	m_renderSystem->AddDrawable(m_frameRate);
}

void Sandbox::Update(float deltaTime)
{
	CalculateFPS(deltaTime);

	m_deltaTime->SetText(std::to_string(fpsAverageFrameTime));
	m_frameRate->SetText(std::to_string((int)fpsFrameRate));

	MoveRectangle(deltaTime);
}

void Sandbox::MoveRectangle(float deltaTime)
{
	Engine::Vector2 position = m_movingRect->GetPosition();
	float movement = (goRight ? 1.0f : -1.0f) * 500 * deltaTime;
	Engine::Vector2 newPosition = Engine::Vector2((position.X + movement), position.Y);
	if (newPosition.X > 768)
		goRight = false;
	else if (newPosition.X < 256)
		goRight = true;
	m_movingRect->SetPosition(newPosition);

	m_color.R += 1.0f * deltaTime;
	m_color.G += 2.0f * deltaTime;
	m_color.B += 3.0f * deltaTime;

	m_movingRect->SetColor(Engine::Color(sin(m_color.R), sin(m_color.G), sin(m_color.B)));
}

void Sandbox::CalculateFPS(float deltaTime)
{
	fpsDeltaTime += deltaTime;
	++fpsFrames;

	// Update every second
	if (fpsDeltaTime > 1.0f)
	{
		fpsFrameRate = fpsFrames;
		fpsFrames = 0;
		fpsDeltaTime = 0;
		fpsAverageFrameTime = 1.0f / (fpsFrameRate == 0 ? 0.001f : fpsFrameRate);
	}
}