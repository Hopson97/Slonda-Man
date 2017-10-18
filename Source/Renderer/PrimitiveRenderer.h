#ifndef PRIMITIVERENDERER_H_INCLUDED
#define PRIMITIVERENDERER_H_INCLUDED

#include <vector>

#include "../GLLib/GLFunctions.h"
#include "../Maths/GlmIncludes.h"
#include "../Model.h"
#include "../Shaders/Shader.h"

class Camera;

enum class Primitive
{
    Quad,
};

class QuadRenderer
{
    public:
        QuadRenderer();

        void add(const glm::vec3& location);

        void render(const Camera& camera);

    private:
        std::vector<glm::vec3> m_quadLocations;

        Model   m_quad;
        Shader  m_primShader;
};

#endif // PRIMITIVERENDERER_H_INCLUDED
