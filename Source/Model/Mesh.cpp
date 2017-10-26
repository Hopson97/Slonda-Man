#include "Mesh.h"

#include <iostream>


//just a failed test
Mesh createMegaMesh(Mesh& mesh, std::vector<glm::vec3>& positions)
{
    Mesh newMesh;
    newMesh.vertexCoords    .reserve(mesh.vertexCoords  .size() * positions.size());
    newMesh.normals         .reserve(mesh.normals       .size() * positions.size());
    newMesh.texCoords       .reserve(mesh.texCoords     .size() * positions.size());
    newMesh.indices         .reserve(mesh.indices       .size() * positions.size());

    GLuint index = 0;
    for (auto& pos : positions)
    {
        for (unsigned i = 0; i < mesh.vertexCoords.size();)
        {
            newMesh.vertexCoords.push_back(pos.x + mesh.vertexCoords[i++]);
            newMesh.vertexCoords.push_back(pos.y + mesh.vertexCoords[i++]);
            newMesh.vertexCoords.push_back(pos.z + mesh.vertexCoords[i++]);
        }

        //normals
        for (unsigned i = 0; i < mesh.normals.size(); i++)
        {
            newMesh.normals.push_back(mesh.normals[i]);
        }

        //UV Coordinates
        for (unsigned i = 0; i < mesh.texCoords.size(); i++)
        {
            newMesh.texCoords.push_back(mesh.texCoords[i]);
        }

        //indices
        for (unsigned i = 0; i < mesh.indices.size(); i++)
        {
            newMesh.indices.push_back(index++);
        }
    }
    return newMesh;
}
