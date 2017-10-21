#include "Player.h"

Player::Player()
{
    position = {45, 0, 45};
}

void Player::input(const sf::RenderWindow& window)
{
    keyboardInput();
    mouseInput(window);
}

void Player::update(float dt)
{
    position += m_velocity;
    m_velocity *= 0.8;
}

void Player::keyboardInput()
{
    static const auto forwards  = sf::Keyboard::W;
    static const auto back      = sf::Keyboard::S;
    static const auto left      = sf::Keyboard::A;
    static const auto right     = sf::Keyboard::D;
    static const auto up        = sf::Keyboard::Z;
    static const auto down      = sf::Keyboard::X;
    auto speed     = 0.00005f * sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) ? 10 : 1;

    glm::vec3 translate;
    float yaw   = glm::radians(rotation.y);
    float yaw90 = glm::radians(rotation.y + 90);

    if (sf::Keyboard::isKeyPressed(forwards))
    {
        translate.x += -glm::cos(yaw90) * speed;
        translate.z += -glm::sin(yaw90) * speed;
    }
    else if (sf::Keyboard::isKeyPressed(back))
    {
        translate.x += glm::cos(yaw90) * speed;
        translate.z += glm::sin(yaw90) * speed;
    }

    if (sf::Keyboard::isKeyPressed(left))
    {
        translate.x += -glm::cos(yaw) * speed;
        translate.z += -glm::sin(yaw) * speed;
    }
    else if (sf::Keyboard::isKeyPressed(right))
    {
        translate.x += glm::cos(yaw) * speed;
        translate.z += glm::sin(yaw) * speed;
    }

    if (sf::Keyboard::isKeyPressed(up))
    {
        translate.y += speed;
    }
    else if (sf::Keyboard::isKeyPressed(down))
    {
        translate.y -= speed;
    }

    m_velocity += translate * 0.005f;
}

void Player::mouseInput(const sf::RenderWindow& window)
{
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

        rotation.y += mouseMove.x * 0.05;
        rotation.x += mouseMove.y * 0.05;



        if      (rotation.x >  BOUND) rotation.x =  BOUND;
        else if (rotation.x < -BOUND) rotation.x = -BOUND;

        if      (rotation.y > 360) rotation.y = 0;
        else if (rotation.y < 0)   rotation.y = 360;

        sf::Mouse::setPosition(CENTER, window);
        lastMousePosition = sf::Mouse::getPosition(window);

    }
}
