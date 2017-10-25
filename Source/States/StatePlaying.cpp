#include "StatePlaying.h"

#include "../Game.h"
#include <iostream>

#include "../Model/Mesh.h"
#include "../Model/ModelLoader.h"
#include "../Terrain/TerrainGenerator.h"
#include "../Util/Random.h"
#include "../Model/Generator.h"

StatePlaying::StatePlaying(Game& game, Camera& camera)
:   StateBase       (game)
,   m_level         ("test")
{
    camera.hookTransformable(&m_player);
}

void StatePlaying::handleEvent(sf::Event e)
{
}

void StatePlaying::handleInput()
{
    m_player.input(m_pGame->getWindow());
}

void StatePlaying::update(sf::Time deltaTime, const Camera& camera)
{
    static glm::vec3 lastPosition;

    m_player    .update(deltaTime.asSeconds());

    entityCollideTest();
    edgeCollideLevel();
}

void StatePlaying::fixedUpdate(sf::Time deltaTime, const Camera& camera)
{
    sf::Clock c;
    m_slenderman.update(camera);
    if (m_slenderman.isInView() &&
        m_slenderman.getState() == Slenderman::State::Stalking)
    {
        glm::vec2 camXZ     = {camera.getPosition       ().x, camera.getPosition        ().z};
        glm::vec2 slenderXZ = {m_slenderman.getLocation ().x, m_slenderman.getLocation  ().z};

        auto camToSlenderVector = slenderXZ - camXZ;
        auto normal             = glm::normalize(camToSlenderVector);
        auto currentStep        = camXZ;
        glm::vec2 currStepLength;

        bool slenderManIsInView = false;
        while (glm::length(currStepLength) < glm::length(camToSlenderVector))
        {
            currentStep     += normal/ 2.0f;
            currStepLength  += normal/ 2.0f;;
            bool collide = false;
            for (const Entity& entity : m_level.getEntities())
            {
                glm::vec2 ent(entity.getPosition().x, entity.getPosition().z);

                float d = glm::distance(currentStep, ent);

                if(d < 0.5)
                {
                    collide = true;
                    break;
                }
            }
            slenderManIsInView = !collide;
            if (!slenderManIsInView)
                break;
        }

        if (slenderManIsInView)
        {
            std::cout << "he is in view\n";
            //wstd::cout << c.getElapsedTime().asSeconds() * 1000 << "\n";
        }
        else
        {
            std::cout << "he is occluded\n";
        }
    }
}

void StatePlaying::render(MasterRenderer& renderer)
{
    m_level     .render(renderer);
    m_slenderman.render(renderer);
}

void StatePlaying::entityCollideTest()
{
    static glm::vec3 lastPosition;

    bool isCollide = false;
    for (const Entity& entity : m_level.getEntities())
    {
        glm::vec2 cam(m_player.position.x, m_player.position.z);
        glm::vec2 ent(entity.getPosition().x, entity.getPosition().z);

        float d = glm::distance(cam, ent);
        if(d < 1)
        {
            isCollide = true;
            m_player.position = lastPosition;
            break;
        }
    }

    if (!isCollide)
        lastPosition = m_player.position;
}



void StatePlaying::edgeCollideLevel()
{
    const static float EDGE = 6.5;
    if (m_player.position.x > LEVEL_SIZE - EDGE)
        m_player.position.x = LEVEL_SIZE - EDGE;
    else if (m_player.position.x < EDGE)
        m_player.position.x = EDGE;

    if (m_player.position.z > LEVEL_SIZE - EDGE)
        m_player.position.z = LEVEL_SIZE - EDGE;
    else if (m_player.position.z < EDGE)
        m_player.position.z = EDGE;
}
