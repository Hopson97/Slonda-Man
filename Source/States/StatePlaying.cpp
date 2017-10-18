#include "StatePlaying.h"

#include "../GUI/Button.h"
#include "../GUI/Textbox.h"
#include "../Game.h"
#include "../Model.h"
#include "../GLLib/GLFunctions.h"
#include <iostream>

Model m;

StatePlaying::StatePlaying(Game& game)
:   StateBase   (game)
{ }

void StatePlaying::handleEvent(sf::Event e)
{
}

void StatePlaying::handleInput()
{

}

glm::vec3 pos;
void StatePlaying::update(sf::Time deltaTime)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        pos.x -= 0.5 * deltaTime.asSeconds();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        pos.x += 0.5 * deltaTime.asSeconds();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        pos.y += 0.5 * deltaTime.asSeconds();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        pos.y -= 0.5 * deltaTime.asSeconds();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        pos.z += 0.5 * deltaTime.asSeconds();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        pos.z -= 0.5 * deltaTime.asSeconds();
    }
}

void StatePlaying::fixedUpdate(sf::Time deltaTime)
{

}

void StatePlaying::render(MasterRenderer& renderer)
{
    renderer.addObject(pos, Primitive::Quad);
}
