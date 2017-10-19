#include "Texture2D.h"

#include <SFML/Graphics.hpp>


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
    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RGBA,
                 i.getSize().x,
                 i.getSize().y,
                 0,
                 GL_RGBA,
                 GL_UNSIGNED_BYTE,
                 i.getPixelsPtr());
    glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Texture2D::bind() const
{
    glBindTexture(GL_TEXTURE_2D, m_texID);
}
