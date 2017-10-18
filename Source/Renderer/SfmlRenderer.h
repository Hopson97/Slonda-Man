#ifndef SFMLRENDERER_H_INCLUDED
#define SFMLRENDERER_H_INCLUDED

#include <SFML/Graphics.hpp>

#include <vector>

class SfmlRenderer
{
    public:
        SfmlRenderer();

        void add(const sf::Drawable& drawable);

        void render(sf::RenderWindow& RenderWindow);

    private:
        std::vector<const sf::Drawable*> m_sfmlDrawables;
};

#endif // SFMLRENDERER_H_INCLUDED
