#include "Generator.h"

#include "Mesh.h"
#include "ModelLoader.h"


Mesh generateWall(float xSize, float zSize, float height)
{
    Mesh mesh = loadObjModel("test/sectionobj");

    std::vector<glm::vec3> p;
    for (int i = 0; i < xSize; i++)
    {
        p.emplace_back(i, 0, 0);
    }

    Mesh wall = createMegaMesh(mesh, p);
    return wall;
}
