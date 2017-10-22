#ifndef CAMERA_H_INCLUDED
#define CAMERA_H_INCLUDED

#include <SFML/Graphics.hpp>

#include <GL/glew.h>
#include "Maths/Frustum.h"

struct Transform;

class Camera
{
    public:
        Camera();

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
        glm::vec3 m_position;
        glm::vec3 m_torchPosition;
        glm::vec3 m_rotation;
        glm::vec3 m_direction;

        glm::mat4 m_projectionMatrix;
        glm::mat4 m_viewMatrix;
        glm::mat4 m_projectionViewMatrix;

        const Transform* m_pTransform = nullptr;

        ViewFrustum m_frustum;
};

#endif // CAMERA_H_INCLUDED
