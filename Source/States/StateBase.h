#ifndef STATEBASE_H_INCLUDED
#define STATEBASE_H_INCLUDED

#include <SFML/Graphics.hpp>

#include "../Util/NonCopyable.h"

class Game;
class MasterRenderer;
class Camera;

class StateBase : public NonCopyable
{
    public:
        StateBase(Game& game)
        :   m_pGame   (&game)
        {}

        virtual ~StateBase() = default;

        virtual void handleEvent    (sf::Event e) = 0;
        virtual void handleInput    () = 0;
        virtual void update         (sf::Time deltaTime, const Camera& camera) = 0;
        virtual void fixedUpdate    (sf::Time deltaTime, const Camera& camera) = 0;
        virtual void render         (MasterRenderer& renderer) = 0;

    protected:
        Game* m_pGame;
};

#endif // STATEBASE_H_INCLUDED
