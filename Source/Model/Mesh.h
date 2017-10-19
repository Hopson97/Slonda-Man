#ifndef MESH_H_INCLUDED
#define MESH_H_INCLUDED

#include <vector>
#include <GL/glew.h>
#include "../Maths/GlmIncludes.h"

struct Mesh
{
    std::vector<GLfloat> vertexCoords;
    std::vector<GLfloat> texCoords;
    std::vector<GLfloat> normals;
    std::vector<GLuint>  indices;
};

Mesh createMegaMesh(Mesh& mesh, std::vector<glm::vec3>& positions);

#endif // MESH_H_INCLUDED
