#include "Camera.h"

#include "Maths/Matrix.h"

Camera::Camera()
:   m_position  (0, 0.5, 1)
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

void Camera::handleInput(const sf::RenderWindow& window)
{
    //FPS Camera stuff
    auto forwards   = sf::Keyboard::W;
    auto back       = sf::Keyboard::S;
    auto left       = sf::Keyboard::A;
    auto right      = sf::Keyboard::D;
    auto speed      = 0.1f;
    auto& translate  = m_position;

    if (sf::Keyboard::isKeyPressed(forwards))
    {
        translate.x += -glm::cos(glm::radians(m_rotation.y + 90)) * speed;
        translate.z += -glm::sin(glm::radians(m_rotation.y + 90)) * speed;
    }
    else if (sf::Keyboard::isKeyPressed(back))
    {
        translate.x += glm::cos(glm::radians(m_rotation.y + 90)) * speed;
        translate.z += glm::sin(glm::radians(m_rotation.y + 90)) * speed;
    }

    if (sf::Keyboard::isKeyPressed(left))
    {
        translate.x += -glm::cos(glm::radians(m_rotation.y)) * speed;
        translate.z += -glm::sin(glm::radians(m_rotation.y)) * speed;
    }
    else if (sf::Keyboard::isKeyPressed(right))
    {
        translate.x += glm::cos(glm::radians(m_rotation.y)) * speed;
        translate.z += glm::sin(glm::radians(m_rotation.y)) * speed;
    }
}



































