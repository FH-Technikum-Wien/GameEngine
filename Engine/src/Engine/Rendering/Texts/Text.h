#pragma once
#include "../../Core.h"
#include "../Drawable.h"
#include "../../Logging/Log.h"

namespace Engine::Rendering::Texts
{
    class ENGINE_API Text : public Drawable
    {
    public:
        Text(const Vector2& position, const Color& color, const std::string& text, unsigned int fontSize);

        void Draw(sf::RenderWindow* window) const override;

        void SetPosition(const Vector2& position) override;
        const Vector2& GetPosition() const override;

        void SetColor(const Color& position) override;
        const Color& GetColor() const override;

        void SetFont(const std::string& pathToFont);
        void SetFontSize(unsigned int fontSize);
        void SetText(const std::string& text);

    private:
        Vector2 m_position;
        Color m_color;
        sf::Text m_text;
        sf::Font m_font;

        const std::string DEFAULT_FONT_PATH = "Fonts\\Roboto\\Roboto-Light.ttf";
    };
}

