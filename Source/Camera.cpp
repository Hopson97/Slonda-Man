#include "Camera.h"

Camera::Camera()
:   m_position  (0, 0.5, -0.5)
,   m_rotation  (0, 0, 0)
{ }

void Camera::update()
{
}


const glm::vec3& Camera::getPosition() const
{
    return m_position;
}

const glm::vec3& Camera::getRotation() const
{
    return m_rotation;
}


