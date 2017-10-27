#ifndef STATEPLAYING_H_INCLUDED
#define STATEPLAYING_H_INCLUDED

#include "StateBase.h"
#include "../World/Level.h"
#include "../World/Player.h"
#include "../World/Slenderman.h"

class StatePlaying : public StateBase
{
    class ObjectiveText
    {
        public:
            ObjectiveText()
            {
                objectiveText.setOutlineColor     (sf::Color::Black);
                objectiveText.setOutlineThickness (1);
                objectiveText.setFillColor        (sf::Color::White);
                objectiveText.setString           ("Found XY/ XY teddy bears!");
                auto offset = objectiveText.getGlobalBounds().width / 2;
                objectiveText.setPosition(  game.getWindow().getSize().x / 2 - offset,
                                            game.getWindow().getSize().y / 2);
            }

            void update(int found, int total)
            {
                auto foundStr = std::to_string(found);
                auto totalStr = std::to_string(total);

                objectiveText.setText("Found " + foundStr + "/" + totalStr + " teddy bears!")
                m_timer.restart();
                m_isOn = true;
            }

            void render(MasterRenderer& renderer)
            {

            }
        private:
            sf::Text    m_objectiveText;
            bool        m_isOn = false;
            sf::Clock   m_timer;
    };

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
