#ifndef GENERATOR_H_INCLUDED
#define GENERATOR_H_INCLUDED

#include "Mesh.h"

namespace Cube
{
    std::vector<GLfloat> generateVertexPositions(GLfloat cubeSize);
    std::vector<GLuint>  generateIndices();
}

namespace Quad
{
    Mesh generateMesh(int size);
}

#endif // GENERATOR_H_INCLUDED
