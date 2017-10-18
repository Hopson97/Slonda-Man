#include "PrimitiveRenderer.h"

QuadRenderer::QuadRenderer()
:   m_primShader    ("Primitive", "Primitive")
{
    std::vector<GLfloat> vert
    {
        -0.5,  0.5, 0,
        -0.5, -0.5, 0,
         0.5, -0.5, 0,
         0.5,  0.5, 0,
    };

    std::vector<GLuint> indices
    {
        0, 1, 2,
        2, 3, 0,
    };

    m_quad.create(vert, indices);

    //init shader
}

void QuadRenderer::add(const glm::vec3& location)
{
   m_quadLocations.push_back(location);
}

void QuadRenderer::render()
{
    m_quad.bindVAO();
    m_primShader.useProgram();
    //uniform locations
    for (auto& quad : m_quadLocations)
    {
        //matrix maths
        GL::drawElements(m_quad.getIndicesCount());
    }
    m_quadLocations.clear();
}
