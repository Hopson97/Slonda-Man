#ifndef PRIMITIVERENDERER_H_INCLUDED
#define PRIMITIVERENDERER_H_INCLUDED

#include <vector>

#include "../GLLib/GLFunctions.h"
#include "../Maths/GlmIncludes.h"
#include "../Model/Model.h"
#include "../Shaders/Shader.h"
#include "../Texture/Texture2D.h"

class Camera;

enum class Primitive
{
    Quad,
};

struct PrimitiveTransform
{
    glm::vec3 location;
    glm::vec3 rotation;

};

class QuadRenderer
{
    public:
        QuadRenderer();

        void add(const glm::vec3& location, const glm::vec3& rotation);

        void render(const Camera& camera);

    private:
        std::vector<PrimitiveTransform> m_quadLocations;

        Model   m_quad;
        Shader  m_primShader;

        GLuint  m_locModelMatrix;
        GLuint  m_locProjViewMatrix;

        Texture2D m_textureTest;
};

#endif // PRIMITIVERENDERER_H_INCLUDED
