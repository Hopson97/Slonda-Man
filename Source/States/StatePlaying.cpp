#include "StatePlaying.h"

#include "../Game.h"
#include <iostream>

#include "../Model/Mesh.h"
#include "../Model/ModelLoader.h"
#include "../Terrain/TerrainGenerator.h"
#include "../Util/Random.h"

namespace
{
    unsigned toHex (sf::Color colour)
    {
        return (colour.r << 16) | (colour.g << 8) | colour.b;
    }
}

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
    if (m_level.collidableAt(camera.getPosition().x, camera.getPosition().z))
    {
        std::cout << "Colliding\n";
    }
}

void StatePlaying::fixedUpdate(sf::Time deltaTime)
{

}

void StatePlaying::render(MasterRenderer& renderer)
{
    m_level.render(renderer);
}
