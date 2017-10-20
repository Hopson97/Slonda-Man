#include "Context.h"

#include <GL/glew.h>
#include "GLLib/GLFunctions.h"

Context::Context()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 0;
    settings.majorVersion = 3;
    settings.minorVersion = 3;
    settings.depthBits = 24;
    settings.stencilBits = 8;

    window.create(sf::VideoMode::getDesktopMode(), "Slender", sf::Style::Fullscreen, settings);
    window.create({1422, 800}, "Slender", sf::Style::Close, settings);

    glewExperimental = GL_TRUE;
    GLenum error = glewInit();

    if(error != GLEW_OK)
    {
        throw std::runtime_error("Unable to init glew");
    }

    glViewport(0, 0, window.getSize().x, window.getSize().y);
    GL::enable(GL::Cap::DepthTest);
    GL::enable(GL::Cap::CullFace);
    glCullFace(GL_BACK);
}
