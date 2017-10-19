#include "StatePlaying.h"

#include "../Game.h"
#include <iostream>

StatePlaying::StatePlaying(Game& game)
:   StateBase   (game)
,   m_testModel ("test", "world")
{
    for (int x = 0; x < 10; x++)
    {
        for (int z = 0; z < 10; z++)
        {
            m_entities.emplace_back(m_testModel);
            m_entities.back().position = {x * 10, -10, z * 10};
        }
    }
}

void StatePlaying::handleEvent(sf::Event e)
{
}

void StatePlaying::handleInput()
{

}


void StatePlaying::update(sf::Time deltaTime)
{
}

void StatePlaying::fixedUpdate(sf::Time deltaTime)
{

}

glm::vec3 pos;
glm::vec3 rot;
void StatePlaying::render(MasterRenderer& renderer)
{
    rot.y++;
    renderer.addObject(pos, rot, Primitive::Quad);

    for (auto& entity : m_entities)
        renderer.addObject(entity);
}
