#ifndef FPSCOUNTER_H_INCLUDED
#define FPSCOUNTER_H_INCLUDED

#include <SFML/Graphics.hpp>

class FPSCounter
{
    public:
        FPSCounter(const std::string& name, const sf::Vector2f& position);

        void update();

        void draw(sf::RenderTarget& renderer);

    private:
        sf::Text m_text;
        sf::Font m_font;

        sf::Clock m_delayTimer;
        sf::Clock m_fpsTimer;

        float m_fps = 0;

        int m_frameCount = 0;

        std::string m_name;
};

#endif // FPSCOUNTER_H_INCLUDED
