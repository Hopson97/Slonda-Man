#ifndef MESH_H_INCLUDED
#define MESH_H_INCLUDED

struct Mesh
{
    std::vector<GLfloat> vertexCoords;
    std::vector<GLfloat> texCoords;
    std::vector<GLfloat> normals;
    std::vector<GLuint>  indices;
};


#endif // MESH_H_INCLUDED
