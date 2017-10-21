#include "MasterRenderer.h"

MasterRenderer::MasterRenderer(GLuint windowWidth, GLuint windowHeight)
:   m_postFXRenderer (windowWidth, windowHeight)
{

}


void MasterRenderer::addObject(const glm::vec3& location, const glm::vec3& rotation, Primitive type)
{
    switch(type)
    {
        case Primitive::Quad:
            m_quadRenderer.add(location, rotation);
            break;
    }
}

void MasterRenderer::render(sf::RenderWindow& target, const Camera& camera)
{
    //m_postFXRenderer.begin();

    m_quadRenderer   .render(camera);
    m_entityRenderer .render(camera);
    m_terrainRenderer.render(camera);

    //m_postFXRenderer.render();

    m_sfmlRenderer.render(target);
}

void MasterRenderer::addObject(const Entity& entity)
{
    m_entityRenderer.add(entity);
}

void MasterRenderer::addObject(const sf::Drawable& drawable)
{
    m_sfmlRenderer.add(drawable);
}

void MasterRenderer::addObject(const Terrain& terrain)
{
    m_terrainRenderer.add(terrain);
}
