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

void Camera::handleInput(const sf::RenderWindow& window, float dt)
{
    //FPS Camera stuff
    //Keyboard
    {
        static const auto forwards  = sf::Keyboard::W;
        static const auto back      = sf::Keyboard::S;
        static const auto left      = sf::Keyboard::A;
        static const auto right     = sf::Keyboard::D;
        static const auto up        = sf::Keyboard::Z;
        static const auto down      = sf::Keyboard::X;
        static const auto speed     = 0.01f;
        glm::vec3 translate;

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

        if (sf::Keyboard::isKeyPressed(up))
        {
            translate.y += 0.01;
        }
        else if (sf::Keyboard::isKeyPressed(down))
        {
            translate.y -= 0.01;
        }

        m_position += translate * dt;
    }
    //Mouse
    {
        static const auto BOUND = 85;
        static const sf::Vector2i CENTER(window.getSize().x / 2, window.getSize().y / 2);

        static sf::Vector2i lastMousePosition = sf::Mouse::getPosition(window);
        auto mouseMove = sf::Mouse::getPosition(window) - lastMousePosition;

        m_rotation.y += mouseMove.x * 0.05;
        m_rotation.x += mouseMove.y * 0.05;


/*
        if      (m_rotation.x >  BOUND) m_rotation.x =  BOUND;
        else if (m_rotation.x < -BOUND) m_rotation.x = -BOUND;

        if      (m_rotation.y > 360) m_rotation.y = 0;
        else if (m_rotation.y < 0)   m_rotation.y = 360;
*/
        sf::Mouse::setPosition(CENTER, window);
        lastMousePosition = sf::Mouse::getPosition(window);

    }


}



































