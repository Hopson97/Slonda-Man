#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "Transform.h"

class Player : public Transform
{
    public:
        Player();

        void input  (const sf::RenderWindow& window);
        void update (float dt);

    private:
        void keyboardInput();
        void mouseInput   (const sf::RenderWindow& window);

        glm::vec3 m_velocity;

};

#endif // PLAYER_H_INCLUDED
