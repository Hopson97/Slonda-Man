#include "TerrainGenerator.h"

#include <GL/glew.h>

namespace
{
    constexpr GLuint    SIZE                = 512;
    constexpr GLuint    EDGE_VERTEX_COUNT   = 256;
    constexpr GLuint    AREA                = EDGE_VERTEX_COUNT * EDGE_VERTEX_COUNT;
    constexpr GLfloat   fEDGE_VERTEX_COUNT  = GLfloat(EDGE_VERTEX_COUNT - 1);

    void generateTerrainAttributes(Mesh& mesh)
    {

        std::vector<GLfloat>& vertexCoords  = mesh.vertexCoords;
        std::vector<GLfloat>& normals       = mesh.normals;
        std::vector<GLfloat>& textureCoords = mesh.texCoords;
        GLuint vertexPtr = 0;
        for (int z = 0; z < (int)EDGE_VERTEX_COUNT; z++)
        {
            for (int x = 0; x < (int)EDGE_VERTEX_COUNT; x++)
            {
                GLfloat fz = static_cast<GLfloat>(z);
                GLfloat fx = static_cast<GLfloat>(x);

                vertexCoords[vertexPtr * 3]     = fx / fEDGE_VERTEX_COUNT * SIZE;
                vertexCoords[vertexPtr * 3 + 1] = -1;
                vertexCoords[vertexPtr * 3 + 2] = fz / fEDGE_VERTEX_COUNT * SIZE;

                normals[vertexPtr * 3]     = 0.0;
                normals[vertexPtr * 3 + 1] = 1.0; //Pointing straight up
                normals[vertexPtr * 3 + 2] = 0.0;

                textureCoords[vertexPtr * 2]        = fx / fEDGE_VERTEX_COUNT;
                textureCoords[vertexPtr * 2 + 1]    = fz / fEDGE_VERTEX_COUNT;

                vertexPtr++;
            }
        }
    }

    void generateTerrainIndices(Mesh& mesh)
    {
        std::vector<GLuint>&  indices       = mesh.indices;

        GLuint indexPtr = 0;
        for (int z = 0; z < (int)EDGE_VERTEX_COUNT - 1; z++)
        {
            for (int x = 0; x < (int)EDGE_VERTEX_COUNT - 1; x++)
            {
                int topLeft     = (z * EDGE_VERTEX_COUNT) + x;
                int topRight    = topLeft + 1;
                int bottomLeft  = ((z + 1) * EDGE_VERTEX_COUNT) + x;
                int bottomRight = bottomLeft + 1;

                indices[indexPtr++] = topLeft;
                indices[indexPtr++] = bottomLeft;
                indices[indexPtr++] = topRight;
                indices[indexPtr++] = topRight;
                indices[indexPtr++] = bottomLeft;
                indices[indexPtr++] = bottomRight;
            }
        }
    }
}

Mesh generateTerrain()
{

    Mesh mesh(AREA * 3,
              AREA * 2,
              AREA * 3,
              6 * (EDGE_VERTEX_COUNT - 1) * (EDGE_VERTEX_COUNT - 1));


    generateTerrainAttributes   (mesh);
    generateTerrainIndices      (mesh);

    return mesh;
}





























