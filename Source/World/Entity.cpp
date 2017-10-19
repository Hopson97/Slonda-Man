#include "Entity.h"

Entity::Entity(const TexturedModel& model)
:   m_pTexturedModel    (&model)
{

}

const TexturedModel& Entity::getModel() const
{
    return *m_pTexturedModel;
}
