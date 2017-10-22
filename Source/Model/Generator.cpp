#include "Generator.h"

#include "Mesh.h"
#include "ModelLoader.h"

namespace Cube
{
    std::vector<GLfloat> generateVertexPositions(GLfloat cubeSize)
    {
        return
        {
            //Back
             cubeSize, -cubeSize, -cubeSize,
            -cubeSize, -cubeSize, -cubeSize,
            -cubeSize,  cubeSize, -cubeSize,
             cubeSize,  cubeSize, -cubeSize,

            //Front
            -cubeSize, -cubeSize, cubeSize,
             cubeSize, -cubeSize, cubeSize,
             cubeSize,  cubeSize, cubeSize,
            -cubeSize,  cubeSize, cubeSize,

            //Right
            cubeSize, -cubeSize,  cubeSize,
            cubeSize, -cubeSize, -cubeSize,
            cubeSize,  cubeSize, -cubeSize,
            cubeSize,  cubeSize,  cubeSize,

            //Left
            -cubeSize, -cubeSize, -cubeSize,
            -cubeSize, -cubeSize,  cubeSize,
            -cubeSize,  cubeSize,  cubeSize,
            -cubeSize,  cubeSize, -cubeSize,

            //Top
            -cubeSize, cubeSize,  cubeSize,
             cubeSize, cubeSize,  cubeSize,
             cubeSize, cubeSize, -cubeSize,
            -cubeSize, cubeSize, -cubeSize,

            //Bottom
            -cubeSize, -cubeSize, -cubeSize,
             cubeSize, -cubeSize, -cubeSize,
             cubeSize, -cubeSize,  cubeSize,
            -cubeSize, -cubeSize,  cubeSize,
        };
    }

    std::vector<GLuint>  generateIndices()
    {
        return
        {
            0, 1, 2,
            2, 3, 0,

            4, 5, 6,
            6, 7, 4,

            8, 9, 10,
            10, 11, 8,

            12, 13, 14,
            14, 15, 12,

            16, 17, 18,
            18, 19, 16,

            20, 21, 22,
            22, 23, 20
        };
    }
}
