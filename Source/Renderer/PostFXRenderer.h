#ifndef POSTFXRENDERER_H_INCLUDED
#define POSTFXRENDERER_H_INCLUDED

#include <GL/glew.h>
#include "../Model/Model.h"
#include "../Shaders/Shader.h"

class PostFXRenderer : public NonCopyable, public NonMovable
{
    public:
        PostFXRenderer(int width, int height);
        ~PostFXRenderer();

        void begin();
        void render();

    private:
        Model   m_windowQuad;
        GLuint  m_fbo;
        GLuint  m_fboTexture;
        GLuint  m_rbo;
        Shader  m_postFXShader;
};

#endif // POSTFXRENDERER_H_INCLUDED
