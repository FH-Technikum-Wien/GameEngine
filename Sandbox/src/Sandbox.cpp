#include "SandBox.h"
#include <cmath>

Sandbox::Sandbox()
{
	m_renderSystem->InitializeWindow(1024, 512, "Engine");

	// Title
	Engine::Rendering::Texts::Text* text = new Engine::Rendering::Texts::Text(Engine::Vector2(384, 50), Engine::Color(1.0f, 1.0f, 1.0f), "ENGINE", 72);
	m_renderSystem->AddDrawable(text);
	// Flying rectangle

	m_movingRect = new Engine::Rendering::Shapes::Rectangle(Engine::Vector2(256, 256), Engine::Vector2(64, 64), Engine::Color(1.0f, 0, 0, 1.0f));
	m_renderSystem->AddDrawable(m_movingRect);

	// Update FPS
	text = new Engine::Rendering::Texts::Text(Engine::Vector2(0, 0), Engine::Color(1.0f, 1.0f, 1.0f), "Update", 25);
	m_renderSystem->AddDrawable(text);
	m_frameRateText = new Engine::Rendering::Texts::Text(Engine::Vector2(0, 40), Engine::Color(1.0f, 1.0f, 1.0f), "0", 20);
	m_renderSystem->AddDrawable(m_frameRateText);
	m_deltaTimeText = new Engine::Rendering::Texts::Text(Engine::Vector2(0, 60), Engine::Color(1.0f, 1.0f, 1.0f), "0", 20);
	m_renderSystem->AddDrawable(m_deltaTimeText);

	// FixedUpdate FPS
	text = new Engine::Rendering::Texts::Text(Engine::Vector2(0, 100), Engine::Color(1.0f, 1.0f, 1.0f), "FixedUpdate", 25);
	m_renderSystem->AddDrawable(text);
	m_frameRateFixedText = new Engine::Rendering::Texts::Text(Engine::Vector2(0, 140), Engine::Color(1.0f, 1.0f, 1.0f), "0", 20);
	m_renderSystem->AddDrawable(m_frameRateFixedText);
	m_deltaTimeFixedText = new Engine::Rendering::Texts::Text(Engine::Vector2(0, 160), Engine::Color(1.0f, 1.0f, 1.0f), "0", 20);
	m_renderSystem->AddDrawable(m_deltaTimeFixedText);
}

void Sandbox::Update(float deltaTime)
{
	CalculateFPS(lastFrameTime, m_deltaTimeSum, m_frames, m_frameRate, m_frameTime);

	m_frameRateText->SetText("FPS: " + std::to_string((int)m_frameRate));
	m_deltaTimeText->SetText("FrameTime: " + std::to_string(m_frameTime));

	//std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void Sandbox::FixedUpdate(float fixedDeltaTime)
{
	CalculateFPS(lastFrameTimeFixed, m_deltaTimeSumFixed, m_framesFixed, m_frameRateFixed, m_frameTimeFixed);

	m_frameRateFixedText->SetText("FPS: " + std::to_string((int)m_frameRateFixed));
	m_deltaTimeFixedText->SetText("FrameTime: " + std::to_string(m_frameTimeFixed));

	MoveRectangle(fixedDeltaTime);

	//std::this_thread::sleep_for(std::chrono::milliseconds(8));
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

void Sandbox::CalculateFPS(std::chrono::steady_clock::time_point& lastFrameTime, float& deltaTimeSum, unsigned int& frames, float& frameRate, float& frameTime)
{
	auto currentFrameTime = clock.now();
	float deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(currentFrameTime - lastFrameTime).count() / 1000000.0f;
	lastFrameTime = currentFrameTime;

	deltaTimeSum += deltaTime;
	++frames;

	// Update every second
	if (deltaTimeSum > 1.0f)
	{
		frameRate = frames;
		frames = 0;
		deltaTimeSum = 0;
		frameTime = 1.0f / (frameRate == 0 ? 0.001f : frameRate);
	}
}