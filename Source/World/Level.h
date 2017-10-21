#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include <vector>
#include <SFML/Graphics.hpp>

#include "../Terrain/Terrain.h"
#include "Entity.h"
#include "../Model/TexturedModel.h"

class MasterRenderer;

class Level
{
    constexpr static float SCALE = 3;

    public:
        Level(const std::string& name);

        void render(MasterRenderer& renderer) const;

        bool collidableAt(int x, int z) const;

    private:
        void loadLevel();

        Terrain       m_terrain;
        TexturedModel m_treeModel;

        sf::Image m_levelImage;

        std::vector<Entity> m_entities;
        std::vector<bool>   m_collideMap;

        unsigned m_mapSizeX;
        unsigned m_mapSizeZ;
};

#endif // LEVEL_H_INCLUDED
