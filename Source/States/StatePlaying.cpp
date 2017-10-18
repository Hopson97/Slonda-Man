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


void StatePlaying::update(sf::Time deltaTime)
{
}

void StatePlaying::fixedUpdate(sf::Time deltaTime)
{

}

glm::vec3 pos;
glm::vec3 rot;
void StatePlaying::render(MasterRenderer& renderer)
{
    rot.y++;
    renderer.addObject(pos, rot, Primitive::Quad);
}
