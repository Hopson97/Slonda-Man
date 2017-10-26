#include "Slenderman.h"

#include <iostream>

#include "../Camera.h"
#include "../Model/Generator.h"
#include "Level.h"
#include "../Renderer/MasterRenderer.h"

Slenderman::Slenderman()
{
    Mesh mesh = Quad::generateMesh(7.0);
    m_model.create(mesh, "slender");
    m_entity.create(m_model, m_currLocation);
}

void Slenderman::update(const Camera& camera)
{
    switch (m_state)
    {
        case State::Stalking:
            m_entity.setRotation({0, -camera.getRotation().y, 0});
            if (shouldMoveSpot(camera))
            {
                std::cout << "Slender is finding a new spot\n";
                m_state = State::Ghosting;
                m_ghostClock.restart();
            }
            else if (m_inView)
            {
                m_stalkClock.restart();
            }
            break;

        case State::Ghosting:
            if (m_ghostClock.getElapsedTime() > sf::seconds(5))
            {
                bool success = false;
                while (!success)
                {
                    gotoRandomLocation();
                    if (distanceToCamera(camera) > MAX_DISTANCE) continue;
                    if (distanceToCamera(camera) < MIN_DISTANCE) continue;
                    if (isInCamerasView (camera))                continue;
                    success= true;

                }

                std::cout << "Slender has moved to a random spot\n";
                m_state = State::Stalking;
                m_stalkClock.restart();
            }
            break;
    }

    m_inView = isInCamerasView(camera);
}

bool Slenderman::isInCamerasView(const Camera& camera)
{
    return camera.getFrustum().isPointInFrustum(m_currLocation);
}

bool Slenderman::shouldMoveSpot(const Camera& camera)
{
    return distanceToCamera(camera) > MAX_DISTANCE ||
         (!m_inView && m_stalkClock.getElapsedTime() > sf::seconds(5));
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



