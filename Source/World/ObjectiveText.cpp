#include "ObjectiveText.h"

#include <string>
#include <iostream>

#include "../Renderer/MasterRenderer.h"
#include "../ResourceManager/ResourceHolder.h"

ObjectiveText::ObjectiveText(const sf::RenderWindow& window)
{
    m_objectiveText.setOutlineColor     (sf::Color::Black);
    m_objectiveText.setOutlineThickness (1);
    m_objectiveText.setFillColor        (sf::Color::White);
    m_objectiveText.setFont             (ResourceHolder::get().fonts.get("arial"));
    m_objectiveText.setString           ("Found XY/ XY teddy bears!");
    auto offset = m_objectiveText.getGlobalBounds().width / 2;
    m_objectiveText.setPosition(window.getSize().x / 2 - offset,
                                window.getSize().y / 2);
}

void ObjectiveText::update(int found, int total)
{
    auto foundStr = std::to_string(found);
    auto totalStr = std::to_string(total);

    m_objectiveText.setString("Found " + foundStr + "/" + totalStr + " teddy bears!");
    m_timer.restart();
    m_isOn = true;
}

void ObjectiveText::render(MasterRenderer& renderer)
{
    if (m_isOn)
    {
        renderer.addObject(m_objectiveText);
        m_isOn = m_timer.getElapsedTime() < sf::seconds(2);
    }
}
