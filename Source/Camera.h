#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Glad/glad.h"
#include "Maths/Frustum.h"

struct Transform;

class Camera
{
    public:
        Camera(const sf::RenderWindow& window);

        void hookTransformable(const Transform* transform);
        void update();

        const glm::vec3& getPosition()      const;
        const glm::vec3& getTorchPosition() const;
        const glm::vec3& getRotation()      const;
        const glm::vec3& getDirection()     const;

        const glm::mat4& getProjViewMatrix  () const;
        const glm::mat4& getViewMatrix      () const;
        const glm::mat4& getProjMatrix      () const;

        const ViewFrustum& getFrustum       () const;

    private:
        glm::vec3 m_position        {0.0f};
        glm::vec3 m_torchPosition   {0.0f};
        glm::vec3 m_rotation        {0.0f};
        glm::vec3 m_direction       {0.0f};

        glm::mat4 m_projectionMatrix    {1.0f};
        glm::mat4 m_viewMatrix          {1.0f};
        glm::mat4 m_projectionViewMatrix{1.0f};

        const Transform* m_pTransform = nullptr;

        ViewFrustum m_frustum;
};

#endif // CAMERA_H_INCLUDED
