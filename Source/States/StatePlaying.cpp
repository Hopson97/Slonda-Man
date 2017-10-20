#include "StatePlaying.h"

#include "../Game.h"
#include <iostream>

#include "../Model/Mesh.h"
#include "../Model/ModelLoader.h"

StatePlaying::StatePlaying(Game& game)
:   StateBase       (game)
,   m_testModel2    ("tree1", "world")
{
    Mesh mesh = loadObjModel("tree1");
    std::vector<glm::vec3> pos;
    for (int x = 0; x < 10; x++)
    {
        for (int z = 0; z < 10; z++)
        {
            pos.emplace_back(x * 15, -8, z * 15);
            m_entities.emplace_back(m_testModel2);
            m_entities.back().position = pos.back();
        }
    }
    /*
    Mesh newMesh = createMegaMesh(mesh, pos);
    m_testModel.create(newMesh, "world");
    std::cout << "SIZE: " << newMesh.vertexCoords.size() << " " << mesh.vertexCoords.size() << "\n";
    m_entities.emplace_back(m_testModel);*/
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

glm::vec3 pos;
glm::vec3 rot;
void StatePlaying::render(MasterRenderer& renderer)
{
    rot.y++;
    renderer.addObject(pos, rot, Primitive::Quad);

    for (auto& entity : m_entities)
        renderer.addObject(entity);
}
