#ifndef ENTITYRENDERER_H_INCLUDED
#define ENTITYRENDERER_H_INCLUDED

#include <unordered_map>
#include <vector>

#include "../Shaders/Shader.h"

class TexturedModel;
class Entity;
class Camera;

class EntityRenderer
{
    public:
        EntityRenderer();

        void add(const Entity& entity);

        void render(const Camera& camera);

    private:
        std::unordered_map<const TexturedModel*, std::vector<const Entity*>> m_entities;

        Shader  m_shader;

        GLuint  m_locModelMatrix;
        GLuint  m_locProjViewMatrix;
        GLuint  m_locLightPosition;
        GLuint  m_locLightDirection;
};

#endif // ENTITYRENDERER_H_INCLUDED
