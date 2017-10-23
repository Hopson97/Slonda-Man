#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "../Model/TexturedModel.h"
#include "../Maths/GlmIncludes.h"

class Entity
{
    public:
        Entity() = default;
        Entity(const TexturedModel& model,
               const glm::vec3& position,
               const glm::vec3& rotation = {0, 0, 0});

        void create(const TexturedModel& model,
                    const glm::vec3& position,
                    const glm::vec3& rotation = {0, 0, 0});

        const TexturedModel& getModel () const;

        const glm::mat4& getModelMatrix() const;

        void setPosition(const glm::vec3& position);
        void setRotation(const glm::vec3& position);

        const glm::vec3& getPosition() const;
        const glm::vec3& getRotation() const;

        void rotate(GLfloat amount)
        {
            m_rotation += amount;
        }



    private:
        void resetModelMatrix();

        glm::vec3 m_position;
        glm::vec3 m_rotation;

        const TexturedModel* m_pTexturedModel;

        glm::mat4 m_modelMatrix;

};

#endif // ENTITY_H_INCLUDED
