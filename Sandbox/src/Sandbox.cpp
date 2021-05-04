#include "SandBox.h"

#include <cmath>

Sandbox::Sandbox()
{
	m_renderSystem->InitializeWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Engine");

	m_inputSystem->SetOnMouseClick([&](const Engine::Vector2& position) -> void
		{
			OnMouseClick(position);
		});

	m_inputSystem->SetOnMouseMoved([&](const Engine::Vector2& position) -> void
		{
			OnMouseMove(position);
		});

	// Flying rectangle
	m_movingRect = new Engine::Shapes::Rectangle(Engine::Vector2(256, 256), Engine::Vector2(64, 64), Engine::Color(1.0f, 0, 0, 1.0f));
	m_movingRect->SetVelocity(Engine::Vector2(500.0f, 200.0f));
	m_renderSystem->Add(m_movingRect);
	m_phyisicsSystem->Add(m_movingRect);

	// Input rectangle
	m_inputRect = new Engine::Shapes::Rectangle(Engine::Vector2(256, 256), Engine::Vector2(32, 32), Engine::Color(1.0f, 1.0f, 1.0f, 1.0f));
	m_renderSystem->Add(m_inputRect);

	// Input text
	m_inputText = new Engine::Texts::Text(Engine::Vector2(395, 128), Engine::Color(0.8f, 0.8f, 0.8f, 0.0f), "\"Never gonna give you up\"", 20);
	m_renderSystem->Add(m_inputText);

	// Title
	Engine::Texts::Text* text = new Engine::Texts::Text(Engine::Vector2(384, 50), Engine::Color(1.0f, 1.0f, 1.0f), "ENGINE", 72);
	m_renderSystem->Add(text);

	// Update FPS
	text = new Engine::Texts::Text(Engine::Vector2(0, 0), Engine::Color(1.0f, 1.0f, 1.0f), "Update", 20);
	m_renderSystem->Add(text);
	m_frameRateText = new Engine::Texts::Text(Engine::Vector2(0, 30), Engine::Color(1.0f, 1.0f, 1.0f), "0", 15);
	m_renderSystem->Add(m_frameRateText);
	m_deltaTimeText = new Engine::Texts::Text(Engine::Vector2(0, 45), Engine::Color(1.0f, 1.0f, 1.0f), "0", 15);
	m_renderSystem->Add(m_deltaTimeText);
	m_updateDeltaTime = new Engine::Texts::Text(Engine::Vector2(0, 60), Engine::Color(1.0f, 1.0f, 1.0f), "0", 15);
	m_renderSystem->Add(m_updateDeltaTime);

	// FixedUpdate FPS
	text = new Engine::Texts::Text(Engine::Vector2(0, 90), Engine::Color(1.0f, 1.0f, 1.0f), "FixedUpdate", 20);
	m_renderSystem->Add(text);
	m_frameRateFixedText = new Engine::Texts::Text(Engine::Vector2(0, 120), Engine::Color(1.0f, 1.0f, 1.0f), "0", 15);
	m_renderSystem->Add(m_frameRateFixedText);
	m_deltaTimeFixedText = new Engine::Texts::Text(Engine::Vector2(0, 135), Engine::Color(1.0f, 1.0f, 1.0f), "0", 15);
	m_renderSystem->Add(m_deltaTimeFixedText);
	m_fixedUpdateDeltaTimeText = new Engine::Texts::Text(Engine::Vector2(0, 150), Engine::Color(1.0f, 1.0f, 1.0f), "0", 15);
	m_renderSystem->Add(m_fixedUpdateDeltaTimeText);
}

void Sandbox::Update(float deltaTime)
{
	CalculateFPS(lastFrameTime, m_deltaTimeSum, m_frames, m_frameRate, m_frameTime);

	m_frameRateText->SetText("FPS: " + std::to_string((int)m_frameRate));
	m_deltaTimeText->SetText("FrameTime: " + std::to_string(m_frameTime));
	m_updateDeltaTime->SetText("DeltaTime: " + std::to_string(deltaTime));

	//std::this_thread::sleep_for(std::chrono::milliseconds(100 / 6));
}

void Sandbox::FixedUpdate(float fixedDeltaTime)
{
	CalculateFPS(lastFrameTimeFixed, m_deltaTimeSumFixed, m_framesFixed, m_frameRateFixed, m_frameTimeFixed);

	m_frameRateFixedText->SetText("FPS: " + std::to_string((int)m_frameRateFixed));
	m_deltaTimeFixedText->SetText("FrameTime: " + std::to_string(m_frameTimeFixed));
	m_fixedUpdateDeltaTimeText->SetText("DeltaTime: " + std::to_string(fixedDeltaTime));

	MoveRectangle();

	//std::this_thread::sleep_for(std::chrono::milliseconds(8));
}

void Sandbox::MoveRectangle()
{
	Engine::Vector2 position = m_movingRect->GetPosition();
	Engine::Vector2 size = m_movingRect->GetSize();
	Engine::Vector2 velocity = m_movingRect->GetVelocity();

	if (position.X > WINDOW_WIDTH - size.X || position.X < 0)
	{
		m_color.R = random.Xorshf96_01();
		m_color.G = random.Xorshf96_01();
		m_color.B = random.Xorshf96_01();

		m_movingRect->SetColor(Engine::Color(m_color.R, m_color.G, m_color.B));
		m_movingRect->SetVelocity(Engine::Vector2(velocity.X * -1.0f, velocity.Y));
	}

	if (position.Y > WINDOW_HEIGHT - size.Y || position.Y < 0)
	{
		m_color.R = random.Xorshf96_01();
		m_color.G = random.Xorshf96_01();
		m_color.B = random.Xorshf96_01();

		m_movingRect->SetColor(Engine::Color(m_color.R, m_color.G, m_color.B));
		m_movingRect->SetVelocity(Engine::Vector2(velocity.X, velocity.Y * -1.0f));
	}
}

void Sandbox::OnMouseClick(const Engine::Vector2& position)
{
	m_color.R = random.Xorshf96_01();
	m_color.G = random.Xorshf96_01();
	m_color.B = random.Xorshf96_01();

	m_inputRect->SetColor(Engine::Color(m_color.R, m_color.G, m_color.B));
}

void Sandbox::OnMouseMove(const Engine::Vector2& position)
{
	Engine::Vector2 size = m_inputRect->GetSize();
	m_inputRect->SetPosition(Engine::Vector2(position.X - size.X / 2.0f, position.Y - size.Y / 2.0f));

	if (position.X >= 380 && position.X < 650 && position.Y >= 50 && position.Y < 120)
	{
		m_inputText->SetColor(Engine::Color(0.8f, 0.8f, 0.8f, 1.0f));
	}
	else
	{
		m_inputText->SetColor(Engine::Color(0.8f, 0.8f, 0.8f, 0.0f));
	}
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