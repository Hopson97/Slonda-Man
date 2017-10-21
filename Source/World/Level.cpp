#include "Level.h"

#include "../Util/Random.h"
#include "../Model/ModelLoader.h"
#include "../Renderer/MasterRenderer.h"


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
    sf::Image levelImage;
    levelImage.loadFromFile("res/levels/" + name + ".png");
    m_mapSizeZ = levelImage.getSize().y;
    m_mapSizeX = levelImage.getSize().x;

    m_collideMap.reserve(m_mapSizeZ * m_mapSizeX * SCALE * SCALE);
    for (int i = 0; i < m_mapSizeZ * m_mapSizeX * SCALE * SCALE; i++)
    {
        m_collideMap.push_back(false);
    }
    Random<> randomisor;

    std::vector<glm::vec3> treePositions;
    for (unsigned z = 0; z < levelImage.getSize().y; z++)
    {
        for (unsigned x = 0; x < levelImage.getSize().x; x++)
        {
            glm::vec3 adjPos(x * SCALE, -1, z * SCALE);
            unsigned colourHex = toHex(levelImage.getPixel(x, z));
            if (colourHex == 0x7F3300)
            {
                glm::vec3 position(adjPos.x + randomisor.getFloatInRange(-2, 2),
                                   -1,
                                   adjPos.z + randomisor.getFloatInRange(-2, 2));

                treePositions.emplace_back(position);
                m_collideMap.at(position.z * m_mapSizeZ * SCALE + position.x * SCALE) = true;
            }

            //more models...
        }
    }

    Mesh tree       = loadObjModel("tree1");
    Mesh allTrees   = createMegaMesh(tree, treePositions);
    m_treeModel.create(allTrees, "bark");
    m_entities.emplace_back(m_treeModel);
}

void Level::render(MasterRenderer& renderer) const
{
    renderer.addObject(m_terrain);

    for (auto& entity : m_entities)
        renderer.addObject(entity);
}

bool Level::collidableAt(int x, int y) const
{
    return m_collideMap.at(y * m_mapSizeZ * SCALE + x * SCALE);
}
