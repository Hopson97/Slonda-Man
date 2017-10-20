#include "EntityRenderer.h"

#include <iostream>

#include "../World/Entity.h"
#include "../GLLib/GLFunctions.h"
#include "../Camera.h"
#include "../Maths/Matrix.h"

EntityRenderer::EntityRenderer()
:   m_shader    ("Entity", "Spotlight")
{
    m_locModelMatrix    = m_shader.getUniformLocation("modelMatrix");
    m_locProjViewMatrix = m_shader.getUniformLocation("projectionViewMatrix");
    m_locLightPosition  = m_shader.getUniformLocation("lightPosition");
    m_locLightDirection = m_shader.getUniformLocation("lightDirection");
}

void EntityRenderer::add(const Entity& entity)
{
    const TexturedModel* model = &entity.getModel();

    if (m_entities.count(model))
    {
        m_entities[model].push_back(&entity);
    }
    else
    {
        std::vector<const Entity*> batch {&entity};
        m_entities[model] = batch;
    }
}

void EntityRenderer::render(const Camera& camera)
{
    m_shader.useProgram();
    GL::loadUniform(m_locLightPosition, camera.getPosition());
    GL::loadUniform(m_locLightDirection, camera.getRotation());
    GL::loadUniform(m_locProjViewMatrix, camera.getProjViewMatrix());
    for (auto& modelEntity : m_entities)
    {
        modelEntity.first->getModel().bindVAO();
        modelEntity.first->getTexture().bind();

        for (const Entity* entity : modelEntity.second)
        {
            GL::loadUniform(m_locModelMatrix, createModelMatrix(entity->position, entity->rotation));
            GL::drawElements(modelEntity.first->getModel().getIndicesCount());
        }
    }
    m_entities.clear();
}
