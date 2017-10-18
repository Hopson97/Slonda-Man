#include "Camera.h"

#include "Maths/Matrix.h"

Camera::Camera()
:   m_position  (0, 0.5, -50)
,   m_rotation  (0, 0, 0)
{
    m_projectionMatrix = createProjectionMatrix();
}

void Camera::update()
{
    m_viewMatrix = createViewMatrix(*this);
    m_projectionViewMatrix = m_projectionMatrix * m_viewMatrix;
}


const glm::vec3& Camera::getPosition() const
{
    return m_position;
}

const glm::vec3& Camera::getRotation() const
{
    return m_rotation;
}

const glm::mat4& Camera::getProjViewMatrix() const
{
    return m_projectionViewMatrix;
}


