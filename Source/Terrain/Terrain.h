#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED

#include "../Maths/GlmIncludes.h"
#include "../Model/Model.h"

class Mesh;

class Terrain
{
    public:
        Terrain(const glm::vec3& position);

        const glm::vec3& getPosition() const;
        const Model&     getModel   () const;

    private:
        glm::vec3 m_position;

        Model m_terrainModel;

};

#endif // TERRAIN_H_INCLUDED
