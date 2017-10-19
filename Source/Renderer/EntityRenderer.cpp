#include "EntityRenderer.h"

#include <iostream>

#include "../World/Entity.h"
#include "../GLLib/GLFunctions.h"
#include "../Camera.h"
#include "../Maths/Matrix.h"

EntityRenderer::EntityRenderer()
:   m_primShader    ("Primitive", "Primitive")
{
    m_locModelMatrix    = m_primShader.getUniformLocation("modelMatrix");
    m_locProjViewMatrix = m_primShader.getUniformLocation("projectionViewMatrix");
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
