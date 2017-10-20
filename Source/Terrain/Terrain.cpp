#include "Terrain.h"

#include "TerrainGenerator.h"

Terrain::Terrain(const glm::vec3& position)
{
    m_terrainModel.create(generateTerrain());
}

const glm::vec3& Terrain::getPosition() const
{
    return m_position;
}

const Model& Terrain::getModel() const
{
    return m_terrainModel;
}
