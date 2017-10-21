#include "Entity.h"

Entity::Entity(const TexturedModel& model, const glm::vec3& position)
:   position            (position)
,   m_pTexturedModel    (&model)
{

}

const TexturedModel& Entity::getModel() const
{
    return *m_pTexturedModel;
}
