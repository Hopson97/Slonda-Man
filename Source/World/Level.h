#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include <vector>
#include <unordered_map>
#include <SFML/Graphics.hpp>

#include "../Terrain/Terrain.h"
#include "Entity.h"
#include "../Model/TexturedModel.h"

constexpr int LEVEL_SIZE = 300;

class MasterRenderer;



class Level
{

    struct LevelEntity
    {
        LevelEntity()
        {
            m_id = ++ID;
        }
        std::string modelFile;
        std::string texture;
        int         colour;
        float       offsetX;
        float       offsetY;

        struct Hash
        {
            size_t operator() (const LevelEntity& entity) const
            {
                return entity.m_id;
            }
        };

        bool operator ==(const LevelEntity& other) const
        {
            return m_id == other.m_id;
        }

        private:
            static int ID;
            int m_id;
    };

    constexpr static float SCALE = 3;

    public:
        Level(const std::string& name);

        void render(MasterRenderer& renderer) const;

        const std::vector<Entity>& getEntities () const;

    private:
        void loadEntityInfo();
        void loadLevel();

        Terrain       m_terrain;

        sf::Image m_levelImage;

        std::vector<TexturedModel>  m_models;
        std::vector<Entity>         m_entities;
        std::unordered_map<int, LevelEntity> m_levelEntities;

        unsigned m_mapSizeX;
        unsigned m_mapSizeZ;
};

#endif // LEVEL_H_INCLUDED
