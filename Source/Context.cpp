#include "Context.h"

#include "Glad/glad.h"
#include "GLLib/GLFunctions.h"

Context::Context()
{
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 0;
    settings.majorVersion = 3;
    settings.minorVersion = 3;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.attributeFlags = sf::ContextSettings::Default;

    //window.create(sf::VideoMode::getDesktopMode(), "Slender", sf::Style::Fullscreen, settings);
    window.create(sf::VideoMode{{1600, 900}}, "Slonder", sf::Style::Close, sf::State::Windowed,
                  settings);
    window.setMouseCursorVisible(false);
    
    gladLoadGL();

    glViewport(0, 0, window.getSize().x, window.getSize().y);
    GL::enable(GL::Cap::DepthTest);
    GL::enable(GL::Cap::CullFace);
    glCullFace(GL_BACK);
}
