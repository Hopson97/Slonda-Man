#include "FPSCounter.h"

#include "../ResourceManager/ResourceHolder.h"
#include "../Renderer/MasterRenderer.h"
#include <iostream>

FPSCounter::FPSCounter(const std::string& name, const sf::Vector2f& position)
:   m_name  (name)
{
    m_text.move(position);
    m_text.setOutlineColor (sf::Color::Black);
    m_text.setFillColor({255,255,255});
    m_text.setOutlineThickness  (2);
    m_text.setFont(ResourceHolder::get().fonts.get("arial"));
    m_text.setCharacterSize(15);
}


void FPSCounter::update()
{
    m_frameCount++;

    if (m_delayTimer.getElapsedTime().asSeconds() > 0.2)
    {
        m_fps = m_frameCount / m_fpsTimer.restart().asSeconds();
        m_frameCount = 0;
        m_delayTimer.restart();
    }
}

void FPSCounter::draw(MasterRenderer& renderer)
{
    m_text.setString(m_name + ": " + std::to_string((int)m_fps));
    renderer.addObject(m_text);
}
