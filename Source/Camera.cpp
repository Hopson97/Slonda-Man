#include "Camera.h"

#include "Maths/Matrix.h"

#include <iostream>
#include <iomanip>

Camera::Camera()
:   m_position  (5, 0.5, 5)
,   m_rotation  (0, 0, 0)
{
    m_projectionMatrix = createProjectionMatrix();
}


void Camera::update()
{
    static glm::vec3 rot;
    rot.x++;

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
        auto speed     = 2.1f * sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) ? 10 : 1;

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
            translate.y += speed;
        }
        else if (sf::Keyboard::isKeyPressed(down))
        {
            translate.y -= speed;
        }

        m_position += translate * dt;
    }
    static bool lockMouse = false;
    static sf::Clock delay;
    if (delay.getElapsedTime().asSeconds() > 0.5 && sf::Keyboard::isKeyPressed(sf::Keyboard::L))
    {
        delay.restart();
        lockMouse = !lockMouse;
    }


    //mouse input
    if (!lockMouse)
    {
        static const auto BOUND = 85;
        static const sf::Vector2i CENTER(window.getSize().x / 2, window.getSize().y / 2);

        static sf::Vector2i lastMousePosition = sf::Mouse::getPosition(window);
        auto mouseMove = sf::Mouse::getPosition(window) - lastMousePosition;

        m_rotation.y += mouseMove.x * 0.05;
        m_rotation.x += mouseMove.y * 0.05;



        if      (m_rotation.x >  BOUND) m_rotation.x =  BOUND;
        else if (m_rotation.x < -BOUND) m_rotation.x = -BOUND;

        if      (m_rotation.y > 360) m_rotation.y = 0;
        else if (m_rotation.y < 0)   m_rotation.y = 360;

        sf::Mouse::setPosition(CENTER, window);
        lastMousePosition = sf::Mouse::getPosition(window);

    }


}



































