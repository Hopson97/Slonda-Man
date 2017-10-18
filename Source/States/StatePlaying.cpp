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
{

    m.create(
    {
        -0.5,  0.5, 0,
        -0.5, -0.5, 0,
         0.5, -0.5, 0,
         0.5,  0.5, 0,
    },
    {
        0, 1, 2,
        2, 3, 0
    });
}

void StatePlaying::handleEvent(sf::Event e)
{
}

void StatePlaying::handleInput()
{

}

void StatePlaying::update(sf::Time deltaTime)
{

}

void StatePlaying::fixedUpdate(sf::Time deltaTime)
{

}

void StatePlaying::render(sf::RenderTarget& renderer)
{
    m.bindVAO();
    glDrawElements(GL_TRIANGLES, m.getIndicesCount(), GL_UNSIGNED_INT, nullptr);
}
