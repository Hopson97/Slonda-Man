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
{
    sf::Image i;
    i.loadFromFile("res/test.png");
    std::vector<glm::vec3> housePositions;
    std::vector<glm::vec3> treePositions;
    for (int z = 0; z < (int)i.getSize().y; z++)
    {
        for (int x = 0; x < (int)i.getSize().x; x++)
        {
            glm::vec3 pos = {x * 4, -1, z * 4};
            auto hex = toHex(i.getPixel(x, z));

            if (hex == 0x7D3500)
            {
                treePositions.push_back(pos);
            }
            else if (hex == 0xFF)
            {
                housePositions.push_back(pos);
            }
        }
    }
    Mesh house  = loadObjModel("house1");
    Mesh tree   = loadObjModel("tree1");
    Mesh trees  = createMegaMesh(tree, treePositions);
    Mesh houses = createMegaMesh(house, housePositions);

    m_trees.create(trees, "bark");
    m_houses.create(houses, "face");
    m_entities.emplace_back(m_trees);
    m_entities.emplace_back(m_houses);
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
