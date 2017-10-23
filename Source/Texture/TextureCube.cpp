#include "TextureCube.h"

#include <SFML/Graphics.hpp>

TextureCube::TextureCube(const std::array<std::string, 6>& textureFiles)
{
    loadFromFiles(textureFiles);
}

TextureCube::TextureCube(TextureCube&& other)
:   m_textureID (other.m_textureID)
{
    other.m_textureID = 0;
}

TextureCube& TextureCube::operator=(TextureCube&& other)
{
    m_textureID = other.m_textureID;
    other.m_textureID = 0;
}


TextureCube::~TextureCube()
{
    glDeleteTextures(1, &m_textureID);
}

void TextureCube::loadFromFiles(const std::array<std::string, 6>& textureFiles)
{
    glGenTextures(1, &m_textureID);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, m_textureID);

    for (int i = 0; i < 6; i++)
    {
        sf::Image img;
        img.loadFromFile("res/txrs/sky1/" + textureFiles[i] + ".png");

        GLenum param    = GL_TEXTURE_CUBE_MAP_POSITIVE_X + i;
        GLuint width    = img.getSize().x;
        GLuint height   = img.getSize().y;

        glTexImage2D(param, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, img.getPixelsPtr());
    }

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

void TextureCube::bind()
{
    glBindTexture(GL_TEXTURE_CUBE_MAP, m_textureID);
}
