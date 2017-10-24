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
        Slenderman();

        void update(const Camera& camera);
        void render(MasterRenderer& renderer);

        bool isInView() const;

        const glm::vec3& getLocation() const;

    private:
        void gotoRandomLocation();

        TexturedModel   m_model;
        Entity          m_entity;

        glm::vec3 m_currLocation;

        sf::Clock m_stayTimer;

        bool m_inView;

        Random<> m_random;
};

#endif // SLENDERMAN_H_INCLUDED
