#ifndef POSTFXRENDERER_H_INCLUDED
#define POSTFXRENDERER_H_INCLUDED

#include <GL/glew.h>
#include "../Model/Model.h"
#include "../Shaders/Shader.h"

class PostFXRenderer : public NonCopyable, public NonMovable
{
    public:
        PostFXRenderer(GLuint windowWidth, GLuint windowHeight);
        ~PostFXRenderer();

        void begin();
        void render();

    private:
        void createBuffers(GLuint windowWidth, GLuint windowHeight);

        Model   m_windowQuad;
        GLuint  m_fbo = 0;
        GLuint  m_fboTexture = 0;
        GLuint  m_fboDepthTex = 0;
        Shader  m_postFXShader;
};

#endif // POSTFXRENDERER_H_INCLUDED
