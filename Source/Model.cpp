#include "Model.h"

Model::Model(const std::vector<GLfloat>& vertexPositions)
{
    create(vertexPositions);
}

void Model::create(const std::vector<GLfloat>& vertexPositions)
{
    glGenVertexArrays(1, &m_VAO);
    glBindVertexArray(m_VAO);
    addVBO(3, vertexPositions);
}

void Model::addVBO(int dim, const std::vector<GLfloat>& data)
{
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(data[0]),
                 data.data(),
                 GL_STATIC_DRAW);

    glVertexAttribPointer(m_VBOs.size(), dim, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
    glEnableVertexAttribArray(m_VBOs.size());

    m_VBOs.push_back(vbo)
}

void Model::bindVAO()
{
    glBindVertexArray(m_VAO);
}

Model::~Model()
{
    glDeleteVertexArrays(1, &m_VAO);
    glDeleteBuffers(m_VBOs.size(), m_VBOs.data());
}
