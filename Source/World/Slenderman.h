#ifndef SLENDERMAN_H_INCLUDED
#define SLENDERMAN_H_INCLUDED

#include "../Maths/GlmIncludes.h"
#include <SFML/Graphics.hpp>
#include "../Util/Random.h"

#include "../Model/TexturedModel.h"
#include "Entity.h"

class Camera;
class MasterRenderer;

class Slenderman
{
    public:
        enum class State
        {
            Ghosting,
            Stalking,
        };

        Slenderman();

        void update(const Camera& camera);
        void render(MasterRenderer& renderer);

        bool isInView() const;

        const glm::vec3& getLocation() const;

        State getState() const;

    private:
        void    gotoRandomLocation  ();
        bool    isInCamerasView     (const Camera& camera);
        float   distanceToCamera    (const Camera& camera);

        State m_state = State::Ghosting;



        sf::Clock m_ghostClock; //Used to time next slenderman appearence
        sf::Clock m_stalkClock; //Used to time slender stalking

        TexturedModel   m_model;
        Entity          m_entity;

        glm::vec3 m_currLocation;

        bool m_inView;

        Random<> m_random;
};

#endif // SLENDERMAN_H_INCLUDED
