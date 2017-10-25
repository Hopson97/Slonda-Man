#include "Slenderman.h"

#include <iostream>

#include "../Camera.h"
#include "../Model/Generator.h"
#include "Level.h"
#include "../Renderer/MasterRenderer.h"

Slenderman::Slenderman()
{
    m_currLocation = {150, -1.1, 150};
    //gotoRandomLocation();

    Mesh mesh = Quad::generateMesh(5.5);
    m_model.create(mesh, "slender");
    m_entity.create(m_model, m_currLocation);
}

void Slenderman::update(const Camera& camera)
{
    if (m_state == State::Stalking)
    {
        m_entity.setRotation({0, -camera.getRotation().y, 0});
    }

    if (glm::distance(m_currLocation, camera.getPosition()) > 30)
    {
        //m_state = State::Ghosting;
    }

    m_inView = camera.getFrustum().isPointInFrustum(m_currLocation);
}

void Slenderman::gotoRandomLocation()
{
    float x = m_random.getFloatInRange(0, LEVEL_SIZE);
    float y = m_random.getFloatInRange(0, LEVEL_SIZE);
    std::cout << "x: " << x << " y: " << y << "\n";
    m_currLocation = {x, -1.1, y};
}

void Slenderman::render(MasterRenderer& renderer)
{
    if (m_state == State::Stalking)
        renderer.addObject(m_entity);
}

bool Slenderman::isInView() const
{
    return m_inView;
}

const glm::vec3& Slenderman::getLocation() const
{
    return m_currLocation;
}



