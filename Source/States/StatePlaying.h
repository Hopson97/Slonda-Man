#ifndef STATEPLAYING_H_INCLUDED
#define STATEPLAYING_H_INCLUDED

#include "StateBase.h"
#include "../World/Level.h"
#include "../World/Player.h"

class StatePlaying : public StateBase
{
    public:
        StatePlaying(Game& game, Camera& camera);

        void handleEvent    (sf::Event e)                   override;
        void handleInput    ()                              override;
        void update         (sf::Time deltaTime, const Camera& camera)            override;
        void fixedUpdate    (sf::Time deltaTime)            override;
        void render         (MasterRenderer& renderer)    override;

    private:
        void edgeCollideLevel();

        Level   m_level;
        Player  m_player;
};

#endif // STATEPLAYING_H_INCLUDED
