#include "Entity.h"

#include "../Maths/Matrix.h"

Entity::Entity(const TexturedModel& model, const glm::vec3& position, const glm::vec3& rotation)
:   m_position          (position)
,   m_rotation          (rotation)
,   m_pTexturedModel    (&model)
{
    resetModelMatrix();
}

void Entity::create(const TexturedModel& model, const glm::vec3& position, const glm::vec3& rotation)
{
    m_position = position;
    m_rotation = rotation;
    m_pTexturedModel = &model;

    resetModelMatrix();
}



const TexturedModel& Entity::getModel() const
{
    return *m_pTexturedModel;
}

const glm::mat4& Entity::getModelMatrix() const
{
    return m_modelMatrix;
}

void Entity::setPosition(const glm::vec3& position)
{
    m_position = position;
    resetModelMatrix();
}

void Entity::setRotation(const glm::vec3& rotation)
{
    m_rotation = rotation;
    resetModelMatrix();
}

const glm::vec3& Entity::getPosition() const
{
    return m_position;
}

const glm::vec3& Entity::getRotation() const
{
    return m_rotation;
}

void Entity::resetModelMatrix()
{
     m_modelMatrix = createModelMatrix(m_position, m_rotation);
}

