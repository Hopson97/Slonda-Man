#include "Texture2D.h"

#include <SFML/Graphics.hpp>

#include "../GLLib/GLFunctions.h"

Texture2D::Texture2D(const std::string& texName)
{
    create(texName);
}

Texture2D::~Texture2D()
{
    glDeleteTextures(1, &m_texID);
}

void Texture2D::create(const std::string& texName)
{
    sf::Image i;
    i.loadFromFile("res/txrs/" + texName + ".png");
    i.flipVertically();

    glGenTextures(1, &m_texID);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_texID);

    GL::textureImage2D(i, GL::RGBA::RGBA);

    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_LOD_BIAS, -1);;
}

void Texture2D::bind() const
{
    glBindTexture(GL_TEXTURE_2D, m_texID);
}

Texture2D& Texture2D::operator=(Texture2D&& other)
{
    m_texID = other.m_texID;
    other.m_texID = 0;
    return *this;
}

Texture2D::Texture2D(Texture2D&& other)
:   m_texID (other.m_texID)
{
    other.m_texID = 0;
}














