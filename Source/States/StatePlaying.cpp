#include "StatePlaying.h"

#include "../Game.h"
#include <iostream>

#include "../Model/Mesh.h"
#include "../Model/ModelLoader.h"
#include "../Terrain/TerrainGenerator.h"
#include "../Util/Random.h"

StatePlaying::StatePlaying(Game& game)
:   StateBase       (game)
,   m_level         ("test")
{}

void StatePlaying::handleEvent(sf::Event e)
{
}

void StatePlaying::handleInput()
{

}


void StatePlaying::update(sf::Time deltaTime, const Camera& camera)
{
    for (const Entity& entity : m_level.getEntities())
    {
        glm::vec2 cam(camera.getPosition().x,   camera.getPosition().z);
        glm::vec2 ent(entity.position.x,        entity.position.z);
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
