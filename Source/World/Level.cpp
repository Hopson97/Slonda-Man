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

    for (const auto& entity : m_entities)
        renderer.addObject(entity);

    for (const auto& objective : m_objectiveEntities)
    {
        if (!objective.isCollected)
            renderer.addObject(objective.entity);
    }
}

const std::vector<Entity>& Level::getEntities() const
{
    return m_entities;
}

bool Level::hasCollectedObjective(const Player& player)
{
    for (const auto& obj : m_objectiveEntities)
    {
        glm::vec3& epos = obj.entity.getPosition();
        glm::vec3& ppos = obj.entity.getPosition();

        if (glm::distance(epos, ppos) < 0.5)
        {
            obj.isCollected = true;
            return true;
        }
    }
    return false;
}



void Level::loadLevel()
{
    loadEntityInfo();

    Random<> rng;

    //Reads the level's image file and uses the level entity info to create it
    std::unordered_map<LevelEntity, std::vector<glm::vec3>, LevelEntity::Hash> entityLocations;
    std::vector<glm::vec3> objectiveLocations;
    for (unsigned z = 0; z < m_mapSizeZ; z++)
    for (unsigned x = 0; x < m_mapSizeX; x++)
    {
        glm::vec3 location(x * SCALE, -1, z * SCALE);
        unsigned colourHex = toHex(m_levelImage.getPixel(x, z));

        if (m_levelEntities.find(colourHex) == m_levelEntities.end())
        {
            //Try and place an objective down
            if (colourHex == 0xBEEF)
            {
                objectiveLocations.push_back(location);
            }
            continue;
        }

        const auto& e = m_levelEntities[colourHex];
        if (entityLocations.find(e) == entityLocations.end())
        {
            entityLocations.emplace(e, std::vector<glm::vec3>{});
        }

        glm::vec3 entityLocation (location.x + rng.getFloatInRange(-e.offset, e.offset),
                                  location.y,
                                  location.z + rng.getFloatInRange(-e.offset, e.offset));

        entityLocations.at(e).push_back(entityLocation);
    }

    ///@TODO
    /**
        So...
        I am having to store my models as a heap allocation
        This is because I get some VERY STRANGe behaviour otherwise.
        For example, some models get a VAO value 2425235345

        Likely cause:
            Move constructor mistake potentially
                Model.cpp
                TexturedModel.cpp
    */
    for (auto& lEntity : entityLocations)
    {
        const auto& levelEntity = lEntity.first;
        m_models.push_back(std::make_unique<TexturedModel>(levelEntity.modelFile, levelEntity.texture));
        //m_models.emplace_back(levelEntity.modelFile, levelEntity.texture);
        for (glm::vec3& location : lEntity.second)
        {
            m_entities.emplace_back(*m_models.at(m_models.size() - 1), location);
        }
    }

    m_models.push_back(std::make_unique<TexturedModel>("bear", "fluff"));
    for (auto& location : objectiveLocations)
    {
        m_objectiveEntities.emplace_back(*m_models.back(), location);
    }
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
                }
                else if (line == "offset")
                {
                    inFile >> entity.offset;
                }
            }
            m_levelEntities.emplace(entity.colour, entity);
        }
    }
}














