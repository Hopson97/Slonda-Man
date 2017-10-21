#include "PostFXRenderer.h"

#include "../Model/Mesh.h"
#include "../GLLib/GLFunctions.h"

#include <iostream>

PostFXRenderer::PostFXRenderer(GLuint windowWidth, GLuint windowHeight)
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

    createBuffers(windowWidth, windowHeight);
}

PostFXRenderer::~PostFXRenderer()
{
    glDeleteFramebuffers    (1, &m_fbo);
    glDeleteTextures        (1, &m_fboTexture);
    glDeleteTextures        (1, &m_fboDepthTex);
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
    glBindTexture(GL_TEXTURE_2D, m_fboTexture);
    GL::drawElements(m_windowQuad.getIndicesCount());
    std::clog << "End draw" << std::endl;
}

void PostFXRenderer::createBuffers(GLuint windowWidth, GLuint windowHeight)
{
    glGenFramebuffers(1, &m_fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, m_fbo);

    //now for the color buffer

    glGenTextures(1, &m_fboTexture);
    glBindTexture(GL_TEXTURE_2D, m_fboTexture);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB32F, windowWidth, windowHeight, 0, GL_RGB, GL_FLOAT, nullptr);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glBindTexture(GL_TEXTURE_2D, 0);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_fboTexture, 0); //attach it to the frame buffe//and depth buffer

    glGenTextures(1, &m_fboDepthTex);
    glBindTexture(GL_TEXTURE_2D, m_fboDepthTex);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT32F, windowWidth , windowHeight, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glBindTexture(GL_TEXTURE_2D, 0);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_fboDepthTex, 0);

    glDrawBuffer(GL_COLOR_ATTACHMENT0);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}















