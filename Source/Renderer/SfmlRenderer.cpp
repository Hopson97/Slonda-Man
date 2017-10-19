#include "SfmlRenderer.h"

#include "../GLLib/GLFunctions.h"

void SfmlRenderer::add(const sf::Drawable& drawable)
{
    m_sfmlDrawables.push_back(&drawable);
}

void SfmlRenderer::render(sf::RenderWindow& window)
{
    //prep for SFML drawing
    GL::unbindAll();
    window.pushGLStates();
    window.resetGLStates();
    for (auto& drawable : m_sfmlDrawables)
    {
        window.draw(*drawable);
    }
    window.popGLStates();

    m_sfmlDrawables.clear();
}
