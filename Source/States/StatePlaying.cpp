#include "StatePlaying.h"

#include "../Game.h"
#include <iostream>

#include "../Model/Mesh.h"
#include "../Model/ModelLoader.h"
#include "../Terrain/TerrainGenerator.h"
#include "../Util/Random.h"
#include "../Model/Generator.h"
#include "../ResourceManager/ResourceHolder.h"

StatePlaying::StatePlaying(Game& game, Camera& camera)
:   StateBase       (game)
,   m_level         ("test")
,   m_objectiveText (game.getWindow())
{
    camera.hookTransformable(&m_player);

    m_congratsText.setOutlineColor (sf::Color::Black);
    m_congratsText.setOutlineThickness (1);
    m_congratsText.setFillColor (sf::Color::White);
    m_congratsText.setFont (ResourceHolder::get().fonts.get("arial"));
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
    if (!m_isAllObjectivesFound)
    {
        static glm::vec3 lastPosition;

        m_player.update(deltaTime.asSeconds());

        entityCollideTest();
        edgeCollideLevel();
    }
    else
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            m_pGame->popState();
        }
    }
}

void StatePlaying::fixedUpdate(sf::Time deltaTime, const Camera& camera)
{
    if (m_isAllObjectivesFound)
        return;

    if(m_level.hasCollectedObjective(m_player))
    {
        collectObjective();
    }

    m_slenderman.update(camera);
    slenderLogic();
}

void StatePlaying::render(MasterRenderer& renderer)
{
    m_level         .render(renderer);
    m_slenderman    .render(renderer);

    if (m_isAllObjectivesFound)
        renderer.addObject(m_congratsText);
    else
        m_objectiveText .render(renderer);
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

void StatePlaying::collectObjective()
{
    int found = m_level.getObjectivesFound();
    int total = m_level.getTotalObjectives();

    m_objectiveText.update(found, total);

    //All objectives found!
    if (found == total)
    {
        endGame();
    }
}

void StatePlaying::endGame()
{
    typedef std::string s;
    float time = m_gameTimer.getElapsedTime().asSeconds();
    std::string endStr = s("Congratulations on completing Slender2Weeks by finding all ") +
                         std::to_string(m_level.getTotalObjectives()) +
                         s("!\n") +
                         s("Time taken: ") + std::to_string(time) + s(" seconds!\n") +
                         s("Created by Matthew Hopson\n") +
                         s("Press space bar to exit :)");
    m_isAllObjectivesFound = true;
    m_congratsText.setString(endStr);

    auto offset = m_congratsText.getGlobalBounds().width / 2;
    m_congratsText.setPosition(m_pGame->getWindow().getSize().x / 2 - offset,
                            m_pGame->getWindow().getSize().y / 2);
}

void StatePlaying::slenderLogic()
{
    //This function basically tests if Slenderman is in the player's line of sight
    if (m_slenderman.isInView() &&
        m_slenderman.getState() == Slenderman::State::Stalking)
    {
        auto cameraPos = m_player.position;
        glm::vec3 slenderPos(m_slenderman.getLocation().x,
                             m_slenderman.getLocation().y + 3, //eye height?
                             m_slenderman.getLocation().z);

        auto camToSlenderVector = slenderPos - cameraPos;
        auto normal             = glm::normalize(camToSlenderVector);
        auto currentStep        = cameraPos;
        glm::vec3 currStepLength;

        bool slenderManIsInView = false;
        while (glm::length(currStepLength) < glm::length(camToSlenderVector))
        {
            currentStep     += normal/ 2.0f;
            currStepLength  += normal/ 2.0f;;
            bool collide = false;
            for (const Entity& entity : m_level.getEntities())
            {
                glm::vec2 ent(entity.getPosition().x, entity.getPosition().z);

                float d = glm::distance({currentStep.x, currentStep.z}, ent);

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
        }
        else
        {
            std::cout << "he is occluded\n";
        }
    }
}
