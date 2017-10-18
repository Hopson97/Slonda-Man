#ifndef MASTERRENDERER_H_INCLUDED
#define MASTERRENDERER_H_INCLUDED

#include <GL/glew.h>
#include "../Maths/GlmIncludes.h"

#include "PrimitiveRenderer.h"
#include "SfmlRenderer.h"

class MasterRenderer
{
    public:
        void addObject(const glm::vec3& location, Primitive type);
        void addObject(const sf::Drawable& drawable);

        void render(sf::RenderWindow& target);

    private:
        QuadRenderer    m_quadRenderer;
        SfmlRenderer    m_sfmlRenderer;

};



#endif // MASTERRENDERER_H_INCLUDED
