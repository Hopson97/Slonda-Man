#include "PrimitiveRenderer.h"

#include "../GLLib/GLFunctions.h"
#include "../Maths/Matrix.h"
#include "../Camera.h"

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

    m_locModelMatrix    = GL::getUniformLocation(m_primShader.getShaderID(), "modelMatrix");
    m_locProjViewMatrix = GL::getUniformLocation(m_primShader.getShaderID(), "projectionViewMatrix");
}

void QuadRenderer::add(const glm::vec3& location)
{
   m_quadLocations.push_back(location);
}

void QuadRenderer::render(const Camera& camera)
{
    m_quad.bindVAO();
    m_primShader.useProgram();

    GL::loadUniform(m_locProjViewMatrix, camera.getProjViewMatrix());

    for (auto& quad : m_quadLocations)
    {
        GL::loadUniform(m_locModelMatrix, createModelMatrix(quad, {0, 0, 0}));
        GL::drawElements(m_quad.getIndicesCount());
    }
    m_quadLocations.clear();
}
