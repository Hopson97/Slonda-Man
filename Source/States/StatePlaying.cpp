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
,   m_terrainTest   ({0, 0, 0})
,   m_testModel2    ("tree1", "bark")
{
    sf::Image i;
    i.loadFromFile("res/test.png");
    for (int z = 0; z < (int)i.getSize().y; z++)
    {
        for (int x = 0; x < (int)i.getSize().x; x++)
        {
            auto px = i.getPixel(x, z);
            std::cout << std::hex << toHex(px) << " ";
        }
        std::cout << "\n";
    }


    Mesh mesh = generateTerrain();

    Random<> rnd;
    std::vector<glm::vec3> pos;
    for (int x = 0; x < 25; x++)
    {
        for (int z = 0; z < 25; z++)
        {
            pos.emplace_back(x * 10, -1, z * 10);
            m_entities.emplace_back(m_testModel2);
            m_entities.back().position = pos.back();
        }
    }

    std::cout << "Function end\n";
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
    renderer.addObject(m_terrainTest);

    for (auto& entity : m_entities)
        renderer.addObject(entity);
}
