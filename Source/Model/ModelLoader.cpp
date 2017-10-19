#include "ModelLoader.h"

#include <sstream>
#include <vector>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>

#include "../Maths/GlmIncludes.h"
#include <GL/glew.h>
#include <array>

namespace
{
    using Vector3   = std::array<GLfloat, 3>;
    using Vector2   = std::array<GLfloat, 2>;
    using FaceArray = std::array<std::string, 3>;

    //The code below this comment was not written by me, so all credit goes to github use Ruixel
    template<typename T>
    void insertIntoFloatVector(std::vector<T>& vec, std::istringstream& ss,
                                size_t arraySize)
     {
        std::array<std::string, 3> x;
        ss.seekg(2);

        if (arraySize == 2)
            ss >> x[0] >> x[1];
        else
            ss >> x[0] >> x[1] >> x[2];

        T tArray;
        for(size_t i = 0; i<arraySize; i++)
            tArray[i] = stof(x[i]);
        vec.push_back(tArray);

    }

    void insertIntoStringVector(std::vector<std::string>& vec, std::istringstream& inStream)
    {
        std::array<std::string, 3> x;
        inStream.seekg(2);

        inStream >> x[0] >> x[1] >> x[2];

        for(int i = 0; i< 3; i++)
            vec.push_back(x[i]);
    }
}

Mesh loadObjModel(const std::string& fileName)
{
    // OBJ File Vectors
    std::vector<Vector3> vertices, normals;
    std::vector<Vector2> textureCoordinates;
    std::vector<std::string> faces;

    Mesh outMesh;

    // File Buffer Objects
    std::ifstream objFile;
    std::stringstream obj;
    objFile.exceptions( std::ifstream::badbit );

    // Attempt to read file, if error occurs it returns a nullptr
    try
    {
        objFile.open("res/models/" + fileName + ".obj");
        obj << objFile.rdbuf();
        objFile.close();

    }
    catch (std::ios_base::failure e)
    {
        std::cout << "Error loading " << "res/models/" + fileName + ".obj" << std::endl;
        //return nullptr;
    }

    // Read the buffer and place into separate vectors to process later
    std::string line;
    while (std::getline(obj, line))
    {
        std::istringstream ss(line);

        if (ss.peek() == 'v')
        {
            ss.seekg(1);

            // Vertex
            if (ss.peek() == ' ')
                insertIntoFloatVector(vertices, ss, 3);
            else if (ss.peek() == 't')
                insertIntoFloatVector(textureCoordinates, ss, 2);
            else if (ss.peek() == 'n')
                insertIntoFloatVector(normals, ss, 3);
        }

        if (ss.peek() == 'f')
            insertIntoStringVector(faces, ss);
    }

    // From vector<array>s into single <arrays>
    FaceArray a;
    GLfloat face[3];
    int pointAt, indexCount = 0;
    std::string str;
    for (auto& i : faces)
    {
        std::istringstream ss(i);

        pointAt = 0;
        while (getline(ss, str, '/'))
        {
                face[pointAt] = stoi(str);
                pointAt++;
        }

        for (int v = 0; v < 3; v++)
            outMesh.vertexCoords.push_back(vertices.at(face[0]-1).at(v));

        for (int v = 0; v < 2; v++)
            outMesh.texCoords.push_back(textureCoordinates.at(face[1]-1).at(v));


        for (int v = 0; v < 3; v++)
            outMesh.normals.push_back(normals.at(face[2]-1).at(v));


        for (int v = 0; v < 3; v++)
            outMesh.indices.push_back(indexCount++);
    }

    return outMesh;
}


