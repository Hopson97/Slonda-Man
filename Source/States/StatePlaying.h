#ifndef STATEPLAYING_H_INCLUDED
#define STATEPLAYING_H_INCLUDED

#include "StateBase.h"
#include "../World/Level.h"
#include "../World/Player.h"
#include "../World/Slenderman.h"
#include "../World/ObjectiveText.h"

class StatePlaying : public StateBase
{
    public:
        StatePlaying(Game& game, Camera& camera);

        void handleEvent    (sf::Event e)                   override;
        void handleInput    ()                              override;
        void update         (sf::Time deltaTime, const Camera& camera)  override;
        void fixedUpdate    (sf::Time deltaTime, const Camera& camera)  override;
        void render         (MasterRenderer& renderer)    override;

    private:
        void entityCollideTest();
        void edgeCollideLevel();

        Level       m_level;
        Player      m_player;
        Slenderman  m_slenderman;
        ObjectiveText    m_objectiveText;
};

#endif // STATEPLAYING_H_INCLUDED
