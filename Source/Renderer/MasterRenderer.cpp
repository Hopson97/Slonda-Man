#include "MasterRenderer.h"

void MasterRenderer::addObject(const glm::vec3& location, Primitive type)
{
    switch(type)
    {
        case Primitive::Quad:
            m_quadRenderer.add(location);
            break;
    }
}

void MasterRenderer::addObject(const sf::Drawable& drawable)
{
    m_sfmlRenderer.add(drawable);
}

void MasterRenderer::render(sf::RenderWindow& target)
{
    m_quadRenderer.render();
    m_sfmlRenderer.render(target);
}
