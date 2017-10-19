#ifndef MODELLOADER_H_INCLUDED
#define MODELLOADER_H_INCLUDED

#include <vector>
#include <string>
#include <GL/glew.h>

struct OutMesh
{
    std::vector<GLfloat> vertexCoords;
    std::vector<GLfloat> texCoords;
    std::vector<GLfloat> normals;
    std::vector<GLuint>  indices;
};

OutMesh loadObjModel(const std::string& fileName);

#endif // MODELLOADER_H_INCLUDED
