#include "SkyboxRenderer.h"

#include "../GLLib/GLFunctions.h"
#include "../Model/Mesh.h"
#include "../Camera.h"

#include "../Model/Generator.h"

SkyboxRenderer::SkyboxRenderer()
:   m_skyShader ("Skybox", "Skybox")
{
    m_skyBoxCube.create({Cube::generateVertexPositions(300),
                        {}, {},
                        Cube::generateIndices()});

    m_skyTexture.loadFromFiles({"skyside", "skyside", "sky", "skyside", "skyside", "skyside"});

    m_locationView = m_skyShader.getUniformLocation("viewMatrix");
    m_locationProj = m_skyShader.getUniformLocation("projectionMatrix");
}

void SkyboxRenderer::render(const Camera& camera)
{
    GL::disable(GL::Cap::CullFace);
    m_skyShader.useProgram();
    m_skyBoxCube.bindVAO();
    m_skyTexture.bind();

    loadUnifroms(camera);

    GL::drawElements(m_skyBoxCube.getIndicesCount());
    //GL::enable(GL::Cap::CullFace);
}

void SkyboxRenderer::loadUnifroms(const Camera& camera)
{
    glm::mat4 view = camera.getViewMatrix();

    view[3][0] = 0;
    view[3][1] = 0;
    view[3][2] = 0;

    GL::loadUniform(m_locationView, view);
    GL::loadUniform(m_locationProj, camera.getProjMatrix());
}


