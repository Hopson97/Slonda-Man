#include "SkyboxRenderer.h"

#include "../GLLib/GLFunctions.h"
#include "../Model/Mesh.h"
#include "../Camera.h"

SkyboxRenderer::SkyboxRenderer()
:   m_skyShader ("Skybox", "Skybox")
{
    constexpr GLfloat SIZE = 500;
    std::vector<GLfloat> vertexCoords
    {
        //Back
         SIZE, -SIZE, -SIZE,
        -SIZE, -SIZE, -SIZE,
        -SIZE,  SIZE, -SIZE,
         SIZE,  SIZE, -SIZE,

        //Front
        -SIZE, -SIZE, SIZE,
         SIZE, -SIZE, SIZE,
         SIZE,  SIZE, SIZE,
        -SIZE,  SIZE, SIZE,

        //Right
        SIZE, -SIZE,  SIZE,
        SIZE, -SIZE, -SIZE,
        SIZE,  SIZE, -SIZE,
        SIZE,  SIZE,  SIZE,

        //Left
        -SIZE, -SIZE, -SIZE,
        -SIZE, -SIZE,  SIZE,
        -SIZE,  SIZE,  SIZE,
        -SIZE,  SIZE, -SIZE,

        //Top
        -SIZE, SIZE,  SIZE,
         SIZE, SIZE,  SIZE,
         SIZE, SIZE, -SIZE,
        -SIZE, SIZE, -SIZE,

        //Bottom
        -SIZE, -SIZE, -SIZE,
         SIZE, -SIZE, -SIZE,
         SIZE, -SIZE,  SIZE,
        -SIZE, -SIZE,  SIZE,
    };

    std::vector<GLuint> indices
    {
        0, 1, 2,
        2, 3, 0,

        4, 5, 6,
        6, 7, 4,

        8, 9, 10,
        10, 11, 8,

        12, 13, 14,
        14, 15, 12,

        16, 17, 18,
        18, 19, 16,

        20, 21, 22,
        22, 23, 20
    };

    m_skyBoxCube.create({vertexCoords, {}, {}, indices});
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
    GL::enable(GL::Cap::CullFace);
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


