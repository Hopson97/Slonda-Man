#ifndef MASTERRENDERER_H_INCLUDED
#define MASTERRENDERER_H_INCLUDED

#include <GL/glew.h>
#include "../Maths/GlmIncludes.h"
#include "PrimitiveRenderer.h"

class MasterRenderer
{
    public:
        void addObject(const glm::vec3& location, Primitive type);

        void render();

    private:
        QuadRenderer m_quadRenderer;

};



#endif // MASTERRENDERER_H_INCLUDED
