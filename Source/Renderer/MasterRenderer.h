#ifndef MASTERRENDERER_H_INCLUDED
#define MASTERRENDERER_H_INCLUDED

#include <GL/glew.h>
#include "../Maths/GlmIncludes.h"

#include "PrimitiveRenderer.h"
#include "SfmlRenderer.h"
#include "EntityRenderer.h"

class Camera;

class MasterRenderer
{
    public:
        void addObject(const glm::vec3& location, const glm::vec3& rotation, Primitive type);
        void addObject(const sf::Drawable& drawable);
        void addObject(const Entity& entity);

        void render(sf::RenderWindow& target, const Camera& camera);

    private:
        QuadRenderer    m_quadRenderer;
        SfmlRenderer    m_sfmlRenderer;
        EntityRenderer  m_entityRenderer;

};



#endif // MASTERRENDERER_H_INCLUDED
