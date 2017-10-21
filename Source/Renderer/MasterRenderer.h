#ifndef MASTERRENDERER_H_INCLUDED
#define MASTERRENDERER_H_INCLUDED

#include <GL/glew.h>
#include "../Maths/GlmIncludes.h"

#include "PrimitiveRenderer.h"
#include "SfmlRenderer.h"
#include "EntityRenderer.h"
#include "TerrainRenderer.h"
#include "PostFXRenderer.h"

class Camera;
class Terrain;

class MasterRenderer
{
    public:
        MasterRenderer(GLuint windowWidth, GLuint windowHeight);

        void addObject(const glm::vec3& location, const glm::vec3& rotation, Primitive type);
        void addObject(const sf::Drawable& drawable);
        void addObject(const Terrain& terrain);
        void addObject(const Entity& entity);

        void render(sf::RenderWindow& target, const Camera& camera);

    private:
        QuadRenderer    m_quadRenderer;
        SfmlRenderer    m_sfmlRenderer;
        EntityRenderer  m_entityRenderer;
        TerrainRenderer m_terrainRenderer;
        PostFXRenderer  m_postFXRenderer;

};



#endif // MASTERRENDERER_H_INCLUDED
