#pragma once

#include <Engine.h>

#include <Engine/Shapes/Rectangle.h>
#include <Engine/Texts/Text.h>
#include "Engine/Math/Random.h"

class Sandbox : public Engine::Application
{
public:
	Sandbox();
	~Sandbox()
	{
	};

	void Update(float deltaTime) override;
	void FixedUpdate(float fixedDeltaTime) override;

private:
	void MoveRectangle();
	void OnMouseClick(const Engine::Vector2& position);
	void OnMouseMove(const Engine::Vector2& position);

	void CalculateFPS(std::chrono::steady_clock::time_point& lastFrameTime, float& deltaTimeSum, unsigned int& frames, float& frameRate, float& frameTime);

private:
	const unsigned int WINDOW_WIDTH = 1024;
	const unsigned int WINDOW_HEIGHT = 512;

	Engine::Math::Random random;

	Engine::Shapes::Rectangle* m_movingRect;
	Engine::Shapes::Rectangle* m_inputRect;
	Engine::Texts::Text* m_inputText;
	Engine::Color m_color;
	bool goRight = true;

	Engine::Texts::Text* m_deltaTimeText;
	Engine::Texts::Text* m_frameRateText;
	Engine::Texts::Text* m_updateDeltaTime;

	Engine::Texts::Text* m_deltaTimeFixedText;
	Engine::Texts::Text* m_frameRateFixedText;
	Engine::Texts::Text* m_fixedUpdateDeltaTimeText;


	float m_frameRate = 0.0f;
	float m_frameRateFixed = 0.0f;
	float m_deltaTimeSum = 0.0f;
	float m_deltaTimeSumFixed = 0.0f;
	float m_frameTime = 0.0f;
	float m_frameTimeFixed = 0.0f;
	unsigned int m_frames = 0;
	unsigned int m_framesFixed = 0;

	const float PI = 3.14159265f;
	std::chrono::high_resolution_clock clock;
	std::chrono::steady_clock::time_point lastFrameTime = clock.now();
	std::chrono::steady_clock::time_point lastFrameTimeFixed = clock.now();
};

Engine::Application* Engine::CreateApplication()
{
	return new Sandbox();
}
