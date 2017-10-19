#include "PrimitiveRenderer.h"

#include "../GLLib/GLFunctions.h"
#include "../Maths/Matrix.h"
#include "../Camera.h"
#include "../Model/ModelLoader.h"

#include <iostream>

QuadRenderer::QuadRenderer()
:   m_primShader    ("Primitive", "Primitive")
,   m_textureTest   ("world")
{
    std::vector<GLfloat> vert
    {
        -0.5,  0.5, 0,
        -0.5, -0.5, 0,
         0.5, -0.5, 0,
         0.5,  0.5, 0,
    };

    std::vector<GLfloat> texure
    {
        1, 1,
        1, 0,
        0, 0,
        0, 1,
    };

    std::vector<GLuint> indices
    {
        0, 1, 2,
        2, 3, 0,
    };

    m_quad.create({vert, texure, {}, indices});

    m_locModelMatrix    = m_primShader.getUniformLocation("modelMatrix");
    m_locProjViewMatrix = m_primShader.getUniformLocation("projectionViewMatrix");
}

void QuadRenderer::add(const glm::vec3& location, const glm::vec3& rotation)
{
   m_quadLocations.push_back({location, rotation});
}

void QuadRenderer::render(const Camera& camera)
{
    GL::enable(GL::Cap::DepthTest);
    m_quad.bindVAO();
    m_primShader.useProgram();
    m_textureTest.bind();
    GL::loadUniform(m_locProjViewMatrix, camera.getProjViewMatrix());

    for (auto& quad : m_quadLocations)
    {
        GL::loadUniform(m_locModelMatrix, createModelMatrix(quad.location, quad.rotation));
        GL::drawElements(m_quad.getIndicesCount());
    }

    m_quadLocations.clear();
}
