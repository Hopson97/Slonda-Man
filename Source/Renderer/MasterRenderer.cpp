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

void MasterRenderer::render()
{
    m_quadRenderer.render();
}
