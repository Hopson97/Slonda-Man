#include "Level.h"

#include "../Util/Random.h"
#include "../Model/ModelLoader.h"
#include "../Renderer/MasterRenderer.h"

#include <iostream>

namespace
{
    unsigned toHex (sf::Color colour)
    {
        return (colour.r << 16) | (colour.g << 8) | colour.b;
    }

    //Tree = 0x7F3300;
}

Level::Level(const std::string& name)
:   m_terrain       ({0, 0, 0})
{
    m_levelImage.loadFromFile("res/levels/" + name + ".png");
    m_mapSizeZ = m_levelImage.getSize().y;
    m_mapSizeX = m_levelImage.getSize().x;

    m_collideMap.reserve(m_mapSizeZ * m_mapSizeX * SCALE * SCALE);

    for (unsigned z = 0; z < m_mapSizeZ * SCALE; z++)
    for (unsigned x = 0; x < m_mapSizeX * SCALE; x++)
        m_collideMap.push_back(false);

    loadLevel();
}

void Level::render(MasterRenderer& renderer) const
{
    renderer.addObject(m_terrain);

    for (auto& entity : m_entities)
        renderer.addObject(entity);
}

const std::vector<Entity>& Level::getEntities() const
{
    return m_entities;
}


bool Level::collidableAt(int x, int z) const
{
    return false; //return m_collideMap.at(z * m_mapSizeZ * SCALE + x * SCALE);
}

void Level::loadLevel()
{
    Random<> randomisor;

    std::vector<glm::vec3> treePositions;
    for (unsigned z = 0; z < m_mapSizeZ; z++)
    for (unsigned x = 0; x < m_mapSizeX; x++)
    {
        glm::vec3 adjPos(x * SCALE, -1, z * SCALE);
        unsigned colourHex = toHex(m_levelImage.getPixel(x, z));
        if (colourHex == 0x7F3300)
        {
            glm::vec3 position(adjPos.x + randomisor.getFloatInRange(-0.5, 0.5),
                                -1,
                                adjPos.z + randomisor.getFloatInRange(-0.5, 0.5));

            treePositions.emplace_back(position);
        }
        //more models...
    }

    m_treeModel.create("tree1", "bark");

    for (auto& pos : treePositions)
    {
        m_entities.emplace_back(m_treeModel, pos);
    }
}



















