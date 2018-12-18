#include "Model.h"

#include <iostream>

#include "../GLLib/GLFunctions.h"
#include "Mesh.h"

Model::Model(const Mesh& mesh)
{
    create(mesh);
}

Model::Model(Model&& other)
:   m_VBOs          (std::move(other.m_VBOs))
,   m_VAO           (other.m_VAO)
,   m_indicesCount  (other.m_indicesCount)
{
    other.m_VAO = 0;
    other.m_indicesCount = 0;
}

Model& Model::operator=(Model&& other)
{
    m_VBOs          = std::move(other.m_VBOs);
    m_VAO           = other.m_VAO;
    m_indicesCount  = other.m_indicesCount;

    other.m_VAO = 0;
    other.m_indicesCount = 0;

    return *this;
}

void Model::create(const Mesh& mesh)
{
    glGenVertexArrays(1, &m_VAO);
    glBindVertexArray(m_VAO);

    addVBO(3, mesh.vertexCoords);
    addVBO(2, mesh.texCoords);
    addVBO(3, mesh.normals);
    createEBO(mesh.indices);
    std::cout << "create model with VAO: " << m_VAO << "\n";
}

void Model::addVBO(int dim, const std::vector<GLfloat>& data)
{
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    GL::bufferData(GL::BufferType::Array, data);

    glVertexAttribPointer(m_VBOs.size(), dim, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
    glEnableVertexAttribArray(m_VBOs.size());

    m_VBOs.push_back(vbo);
}

void Model::createEBO(const std::vector<GLuint>& indices)
{
    m_indicesCount = indices.size();
    GLuint ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    GL::bufferData(GL::BufferType::Element, indices);

    m_VBOs.push_back(ebo);
}

void Model::bindVAO() const
{
    glBindVertexArray(m_VAO);
}

GLuint Model::getIndicesCount() const
{
    return m_indicesCount;
}

Model::~Model()
{
    std::cout << "deleted model with VAO: " << m_VAO << "\n";
    glDeleteVertexArrays(1, &m_VAO);
    glDeleteBuffers(m_VBOs.size(), m_VBOs.data());
}
