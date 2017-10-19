#ifndef STATEPLAYING_H_INCLUDED
#define STATEPLAYING_H_INCLUDED

#include "StateBase.h"
#include "../GUI/StackMenu.h"

#include "../World/Entity.h"
#include "../Model/TexturedModel.h"

class StatePlaying : public StateBase
{
    public:
        StatePlaying(Game& game);

        void handleEvent    (sf::Event e)                   override;
        void handleInput    ()                              override;
        void update         (sf::Time deltaTime)            override;
        void fixedUpdate    (sf::Time deltaTime)            override;
        void render         (MasterRenderer& renderer)    override;

    private:
        TexturedModel m_testModel;
        //Entity m_testEntity;

        std::vector<Entity> m_entities;

};

#endif // STATEPLAYING_H_INCLUDED
