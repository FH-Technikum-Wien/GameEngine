#pragma once
#include "../Core.h"
#include "../Rendering/Drawable.h"
#include "../Logging/Log.h"
#include "../Physics/Transformable.h"

namespace Engine::Texts
{
    /// <summary>
    /// Allows to write text to the screen. The text has a color, a position as well as text attributes such as font and fontSize.
    /// <para>
    /// Represents a wrapper for the SFML text element.
    /// </para>
    /// </summary>
    class ENGINE_API Text : public Rendering::Drawable, public Physics::Transformable
    {
    public:
        /// <summary>
        /// Creates a text element at the given position with the given color, text and fontSize.
        /// Use SetFont() to change the font.
        /// </summary>
        /// <param name="position">- The position of the text in pixels.</param>
        /// <param name="color">- The color of the text.</param>
        /// <param name="text">- The actual text.</param>
        /// <param name="fontSize">- The size of the text.</param>
        Text(const Vector2& position, const Color& color, const std::string& text, unsigned int fontSize);

        /// <summary>
        /// Draws the text element onto the given RenderWindow.
        /// </summary>
        /// <param name="window">- The window to render to.</param>
        /// <param name="stateBlending">- Allows the interpolation of variables to compensate stutter due to difference in System Framerates.</param>
        void Draw(sf::RenderWindow* window, const float stateBlending) override;

        /// <summary>
        /// Sets the position of the text.
        /// </summary>
        /// <param name="position">- The new position.</param>
        void SetPosition(const Vector2& position) override;

        /// <summary>
        /// Gets the current position of the text.
        /// </summary>
        const Vector2& GetPosition() const override;

        /// <summary>
        /// Sets the color of the text.
        /// </summary>
        /// <param name="color">- The new color.</param>
        void SetColor(const Color& color) override;

        /// <summary>
        /// Gets the current color of the text.
        /// </summary>
        const Color& GetColor() const override;

        /// <summary>
        /// Sets the font of the text.
        /// </summary>
        /// <param name="pathToFont">- The path to the new font.</param>
        void SetFont(const std::string& pathToFont);

        /// <summary>
        /// Sets the font size of the text.
        /// </summary>
        /// <param name="fontSize">- The new font size.</param>
        void SetFontSize(unsigned int fontSize);

        /// <summary>
        /// Sets the actual text rendered by this text element.
        /// </summary>
        /// <param name="text">- The new text to render.</param>
        void SetText(const std::string& text);

        void Transform(const float fixedDeltaTime) override
        {
        };

        void SetVelocity(const Vector2& velocity) override
        {
        };

        const Vector2& GetVelocity() const override
        {
            return Vector2();
        };

    private:
        // The position of the text.
        Vector2 m_position;
        // The color of the text.
        Color m_color;
        // The internal SFML text element.
        sf::Text m_text;
        // The internal SFML font element.
        sf::Font m_font;
        // Path to the default font.
        const std::string DEFAULT_FONT_PATH = "Fonts\\Roboto\\Roboto-Light.ttf";
    };
}

