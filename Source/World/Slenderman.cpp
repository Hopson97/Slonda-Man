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

    Mesh mesh = Quad::generateMesh(7.5);
    m_model.create(mesh, "slender");
    m_entity.create(m_model, m_currLocation);
}

void Slenderman::update(const Camera& camera)
{
    if (m_state == State::Stalking)
    {
        m_entity.setRotation({0, -camera.getRotation().y, 0});
        if (distanceToCamera(camera) > 30 || (!m_inView && m_stalkClock.getElapsedTime() > sf::seconds(5)))
        {
            std::cout << "Slender is finding a new spot\n";
            m_state = State::Ghosting;
            m_ghostClock.restart();
        }
        else if (m_inView)
        {
            m_stalkClock.restart();
        }
    }
    else
    {
        if (m_ghostClock.getElapsedTime() > sf::seconds(5))
        {
            bool success = false;
            while (!success)
            {
                gotoRandomLocation();
                if (distanceToCamera(camera) > 30)  continue;
                if (isInCamerasView (camera))       continue;
                success= true;

            }

            std::cout << "Slender has moved to a random spot\n";
            m_state = State::Stalking;
            m_stalkClock.restart();
        }
    }

    m_inView = isInCamerasView(camera);
}

bool Slenderman::isInCamerasView(const Camera& camera)
{
    return camera.getFrustum().isPointInFrustum(m_currLocation);
}

float Slenderman::distanceToCamera(const Camera& camera)
{
    return glm::distance(m_currLocation, camera.getPosition());
}


void Slenderman::gotoRandomLocation()
{
    float x = m_random.getFloatInRange(0, LEVEL_SIZE);
    float y = m_random.getFloatInRange(0, LEVEL_SIZE);
    m_currLocation = {x, -1.1, y};
    m_entity.setPosition(m_currLocation);
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


Slenderman::State Slenderman::getState() const
{
    return m_state;
}



