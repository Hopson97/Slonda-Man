#include "Level.h"

#include "../Util/Random.h"
#include "../Model/ModelLoader.h"
#include "../Renderer/MasterRenderer.h"

#include <iostream>
#include <fstream>

namespace
{
    unsigned toHex (sf::Color colour)
    {
        return (colour.r << 16) | (colour.g << 8) | colour.b;
    }

    //Tree = 0x7F3300;
}

int Level::LevelEntity::ID = 0;

Level::Level(const std::string& name)
:   m_terrain       ({-100, 0, -100})
{
    m_levelImage.loadFromFile("res/levels/" + name + ".png");
    m_mapSizeZ = m_levelImage.getSize().y;
    m_mapSizeX = m_levelImage.getSize().x;

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

void Level::loadEntityInfo()
{
    std::ifstream inFile;
    inFile.open("res/levels/info.txt");
    if (!inFile.is_open())
    {
        throw std::runtime_error("Unable to open entity info file!");
    }

    std::string line;
    while (std::getline(inFile, line))
    {
        if (line == "entity")
        {
            LevelEntity entity;
            while (line != "end")
            {
                inFile >> line;
                if (line == "obj")
                {
                    inFile >> entity.modelFile;
                }
                else if (line == "texture")
                {
                    inFile >> entity.texture;
                }
                else if (line == "colour")
                {
                    inFile >> std::hex >> entity.colour;
                    std::cout << std::hex << "Colour: " << entity.colour << "\n";
                }
                else if (line == "offsetx")
                {
                    inFile >> entity.offsetX;
                }
                else if (line == "offsety")
                {
                    inFile >> entity.offsetY;
                }
            }
            m_levelEntities[entity.colour] = entity;
        }
    }
}

void Level::loadLevel()
{
    loadEntityInfo();
    Random<> randomisor;

    std::unordered_map<LevelEntity, std::vector<glm::vec3>, LevelEntity::Hash> entityLocations;
    for (unsigned z = 0; z < m_mapSizeZ; z++)
    for (unsigned x = 0; x < m_mapSizeX; x++)
    {
        glm::vec3 location(x * SCALE, -1, z * SCALE);
        unsigned colourHex = toHex(m_levelImage.getPixel(x, z));

        if (m_levelEntities.find(colourHex) == m_levelEntities.end())
        {
            continue;
        }

        LevelEntity& e = m_levelEntities[colourHex];
        if (entityLocations.find(e) == entityLocations.end())
        {
            entityLocations[e] = std::vector<glm::vec3>();
        }

        glm::vec3 entityLocation (location.x + randomisor.getFloatInRange(e.offsetX, e.offsetX),
                                  location.y,
                                  location.z + randomisor.getFloatInRange(e.offsetY, e.offsetY));

        entityLocations[e].push_back(entityLocation);
    }

    for (auto& lEnity : entityLocations)
    {
        const LevelEntity& e = lEnity.first;
        m_models.emplace_back(e.modelFile, e.texture);
        for (glm::vec3& location : lEnity.second)
        {
            m_entities.emplace_back(m_models.back(), location);
        }
    }
}



















