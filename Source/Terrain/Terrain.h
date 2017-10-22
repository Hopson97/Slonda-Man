#ifndef TERRAIN_H_INCLUDED
#define TERRAIN_H_INCLUDED

#include "../Maths/GlmIncludes.h"
#include "../Model/Model.h"

#include <string>
#include <functional>

typedef std::function<GLfloat(int, int)> HeightFunction;

class Mesh;

class Terrain
{
    public:
        Terrain(const glm::vec3& position, HeightFunction heightFunction = [](int, int){return -1;});

        const glm::vec3& getPosition() const;
        const Model&     getModel   () const;

    private:
        glm::vec3 m_position;

        Model m_terrainModel;

};

#endif // TERRAIN_H_INCLUDED
