#include "StatePlaying.h"

#include "../Game.h"
#include <iostream>

#include "../Model/Mesh.h"
#include "../Model/ModelLoader.h"
#include "../Terrain/TerrainGenerator.h"
#include "../Util/Random.h"

StatePlaying::StatePlaying(Game& game, Camera& camera)
:   StateBase       (game)
,   m_level         ("test")
{
    camera.hookTransformable(&m_player);
}

void StatePlaying::handleEvent(sf::Event e)
{
}

void StatePlaying::handleInput()
{
    m_player.input(m_pGame->getWindow());
}

void StatePlaying::update(sf::Time deltaTime, const Camera& camera)
{
    m_player.update(deltaTime.asSeconds());
    for (const Entity& entity : m_level.getEntities())
    {
        glm::vec2 cam(m_player.position.x, m_player.position.z);
        glm::vec2 ent(entity  .position.x, entity  .position.z);

        float d = glm::distance(cam, ent);
        if(d < 1)
        {
            std::cout << "Collide\n";
        }
    }
}

void StatePlaying::fixedUpdate(sf::Time deltaTime)
{

}

void StatePlaying::render(MasterRenderer& renderer)
{
    m_level.render(renderer);
}
