#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "../Model/TexturedModel.h"
#include "../Maths/GlmIncludes.h"

class Entity
{
    public:
        Entity(const TexturedModel& model);

        const TexturedModel& getModel () const;

        glm::vec3 position;
        glm::vec3 rotation;

    private:
        const TexturedModel* m_pTexturedModel;
};

#endif // ENTITY_H_INCLUDED
