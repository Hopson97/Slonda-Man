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

    Mesh mesh = Quad::generateMesh(7.5);
    m_slenderTest.create(mesh, "slender");
    m_slenderEntity.create(m_slenderTest, glm::vec3{25, -1, 25});
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
    static bool isCollide;
    static glm::vec3 lastPosition;

    m_player.update(deltaTime.asSeconds());

    isCollide = false;
    for (const Entity& entity : m_level.getEntities())
    {
        glm::vec2 cam(m_player.position.x, m_player.position.z);
        glm::vec2 ent(entity.getPosition().x, entity.getPosition().z);

        float d = glm::distance(cam, ent);
        if(d < 1)
        {
            isCollide = true;
            m_player.position = lastPosition;
        }
    }

    edgeCollideLevel();

    if (!isCollide)
        lastPosition = m_player.position;
}

void StatePlaying::fixedUpdate(sf::Time deltaTime)
{
    float y = m_player.rotation.y;
    m_slenderEntity.setRotation({0, -y, 0});
}

void StatePlaying::render(MasterRenderer& renderer)
{
    m_level.render(renderer);
    renderer.addObject(m_slenderEntity);
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
