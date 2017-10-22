#include "Camera.h"

#include "Maths/Matrix.h"

#include <iostream>
#include <iomanip>

#include "World/Transform.h"

Camera::Camera()
:   m_position  (5, 0.5, 5)
,   m_rotation  (0, 0, 0)
{
    m_projectionMatrix = createProjectionMatrix();
}


void Camera::hookTransformable(const Transform* transform)
{
    m_pTransform = transform;
}

void Camera::update()
{
    if (m_pTransform)
    {
        m_position = m_pTransform->position;
        m_rotation = m_pTransform->rotation;
    }

    float yaw    = glm::radians(m_rotation.y);
    float pitch  = glm::radians(m_rotation.x);
    float roll   = glm::radians(m_rotation.z);

    m_direction.x = -sin(yaw) * cos(pitch);
    m_direction.z = cos(yaw) * cos(pitch);
    m_direction.y = sin(pitch);

    glm::vec3 translate;
    translate.x += glm::cos(glm::radians(m_rotation.y)) * 0.5;
    translate.z += glm::sin(glm::radians(m_rotation.y)) * 0.5;
    translate.x += -glm::cos(glm::radians(m_rotation.y + 90)) * 0.2;
    translate.z += -glm::sin(glm::radians(m_rotation.y + 90)) * 0.2;
    translate.y -= 0.1;
    m_torchPosition = m_position + translate;

    m_viewMatrix = createViewMatrix(*this);
    m_projectionViewMatrix = m_projectionMatrix * m_viewMatrix;
}

const glm::vec3& Camera::getPosition() const
{
    return m_position;
}

const glm::vec3& Camera::getTorchPosition() const
{
    return m_torchPosition;
}


const glm::vec3& Camera::getRotation() const
{
    return m_rotation;
}

const glm::vec3& Camera::getDirection() const
{
    return m_direction;
}

const glm::mat4& Camera::getProjViewMatrix() const
{
    return m_projectionViewMatrix;
}

const glm::mat4& Camera::getViewMatrix() const
{
    return m_viewMatrix;
}

const glm::mat4& Camera::getProjMatrix() const
{
    return m_projectionMatrix;
}


































