#include "Model.h"

#include <iostream>

Model::Model(const std::vector<GLfloat>& vertexPositions,
             const std::vector<GLfloat>& textureCoordinates,
             const std::vector<GLuint>&  indices)
{
    create(vertexPositions, textureCoordinates, indices);
}

void Model::create(const std::vector<GLfloat>& vertexPositions,
                   const std::vector<GLfloat>& textureCoordinates,
                   const std::vector<GLuint>&  indices)
{
    glGenVertexArrays(1, &m_VAO);
    glBindVertexArray(m_VAO);

    addVBO(3, vertexPositions);
    addVBO(2, textureCoordinates);
    createEBO(indices);
}

void Model::addVBO(int dim, const std::vector<GLfloat>& data)
{
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER,
                 data.size() * sizeof(GLfloat),
                 data.data(),
                 GL_STATIC_DRAW);

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
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 indices.size() * sizeof(GLuint),
                 indices.data(),
                 GL_STATIC_DRAW);
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
