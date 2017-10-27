#ifndef OBJECTIVETEXT_H_INCLUDED
#define OBJECTIVETEXT_H_INCLUDED

#include <SFML/Graphics.hpp>

class MasterRenderer;

class ObjectiveText
{
    public:
        ObjectiveText(const sf::RenderWindow& window);

        void update(int found, int total);

        void render(MasterRenderer& renderer);

    private:
        sf::Text    m_objectiveText;
        bool        m_isOn = false;
        sf::Clock   m_timer;
};

#endif // OBJECTIVETEXT_H_INCLUDED
