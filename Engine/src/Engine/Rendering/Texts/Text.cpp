#include "Text.h"

namespace Engine::Rendering::Texts
{
	Text::Text(const Vector2& position, const Color& color, const std::string& text, unsigned int fontSize)
	{
		SetFont(DEFAULT_FONT_PATH);
		SetPosition(position);
		SetColor(color);
		SetText(text);
		SetFontSize(fontSize);
	}

	void Text::Draw(sf::RenderWindow* window, const float stateBlending)
	{
		window->draw(m_text);
	}

	void Text::SetPosition(const Vector2& position)
	{
		m_position = position;
		m_text.setPosition(position.X, position.Y);
	}

	const Vector2& Text::GetPosition() const
	{
		return m_position;
	}

	void Text::SetColor(const Color& color)
	{
		m_color = color;
		Color colorAs255 = color.GetAs255();
		m_text.setFillColor(sf::Color(colorAs255.R, colorAs255.G, colorAs255.B, colorAs255.A));
	}

	const Color& Text::GetColor() const
	{
		return m_color;
	}


	void Text::SetFont(const std::string& pathToFont)
	{
		if (!m_font.loadFromFile(pathToFont))
		{
			LOG_CORE_ERROR("Couldn't load font from: " + pathToFont);
			return;
		}

		m_text.setFont(m_font);
	}

	void Text::SetFontSize(unsigned int fontSize)
	{
		m_text.setCharacterSize(fontSize);
	}

	void Text::SetText(const std::string& text)
	{
		m_text.setString(text.c_str());
	}
}
