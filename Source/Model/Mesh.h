#ifndef MESH_H_INCLUDED
#define MESH_H_INCLUDED

#include <vector>
#include "../Glad/glad.h"
#include "../Maths/GlmIncludes.h"

struct Mesh
{
    Mesh() = default;
    Mesh(size_t initialVertSize,
         size_t initialTexSize,
         size_t initialNormalSize,
         size_t initialIndicesSize)
    :   vertexCoords    (initialVertSize)
    ,   texCoords       (initialTexSize)
    ,   normals         (initialNormalSize)
    ,   indices         (initialIndicesSize)
    {}

    Mesh(const std::vector<GLfloat>& vert,
         const std::vector<GLfloat>& tex,
         const std::vector<GLfloat>& norm,
         const std::vector<GLuint>&  ind)
    :   vertexCoords    (vert)
    ,   texCoords       (tex)
    ,   normals         (norm)
    ,   indices         (ind)
    {}

    std::vector<GLfloat> vertexCoords;
    std::vector<GLfloat> texCoords;
    std::vector<GLfloat> normals;
    std::vector<GLuint>  indices;
};

Mesh createMegaMesh(Mesh& mesh, std::vector<glm::vec3>& positions);

#endif // MESH_H_INCLUDED
