#include "PostFXRenderer.h"

#include "../Model/Mesh.h"

PostFXRenderer::PostFXRenderer(int width, int height)
:   m_postFXShader  ("PostFX", "PostFX")
{
    std::vector<GLfloat> vert
    {
        -1,  1, 0,
        -1, -1, 0,
         1, -1, 0,
         1,  1, 0,
    };

    std::vector<GLfloat> texture
    {
        1, 1,
        1, 0,
        0, 0,
        0, 1,
    };

    std::vector<GLuint> indices
    {
        0, 1, 2,
        2, 3, 0,
    };

    m_windowQuad.create({vert, texture, {}, indices});

    glGenFramebuffers(1, &m_fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);

    glGenTextures   (1, &m_fboTexture);
    glBindTexture   (GL_TEXTURE_2D, m_fboTexture);
    glTexImage2D    (GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_fboTexture, 0);

    glGenRenderbuffers      (1, &m_rbo);
    glBindRenderbuffer      (GL_RENDERBUFFER, rbo);
    glRenderbufferStorage   (GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
    glBindRenderbuffer      (GL_RENDERBUFFER, 0);

    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_rbo);
}

PostFXRenderer::~PostFXRenderer()
{
    glDeleteFramebuffers    (1, &m_fbo);
    glDeleteTextures        (1, &m_fboTexture);
    glDeleteRenderbuffers   (1, &m_rbo);
}


void PostFXRenderer::begin()
{
    glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);
}

void PostFXRenderer::render()
{
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    m_windowQuad.bindVAO();
    m_postFXShader.useProgram();
    GL::drawElements(m_windowQuad.getIndicesCount());

}
