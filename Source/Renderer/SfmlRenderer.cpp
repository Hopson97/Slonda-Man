#include "SfmlRenderer.h"

#include <GL/glew.h>

SfmlRenderer::SfmlRenderer()
{

}

void SfmlRenderer::add(const sf::Drawable& drawable)
{
    m_sfmlDrawables.push_back(&drawable);
}

void SfmlRenderer::render(sf::RenderWindow& window)
{
    //prep for SFML drawing
    glDisable(GL_DEPTH_TEST);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
    glUseProgram(0);

    window.pushGLStates();
    window.resetGLStates();
    for (auto& drawable : m_sfmlDrawables)
    {
        window.draw(*drawable);
    }
    window.popGLStates();

    m_sfmlDrawables.clear();
}
