#include "TexturedModel.h"

#include "ModelLoader.h"

TexturedModel::TexturedModel(const std::string& modelFileName, const std::string& textureFileName)
:   m_texture   (textureFileName)
{
    auto mesh = loadObjModel(modelFileName);
    m_model.create(mesh);
}

TexturedModel::TexturedModel(TexturedModel&& other)
:   m_model     (std::move(other.m_model))
,   m_texture   (std::move(other.m_texture))
{ }

TexturedModel& TexturedModel::operator=(TexturedModel&& other)
{
    m_model     = std::move(other.m_model);
    m_texture   = std::move(other.m_texture);

    return *this;
}

void TexturedModel::create(const std::string& modelFileName, const std::string& textureFileName)
{
    auto mesh = loadObjModel(modelFileName);
    m_model.create(mesh);
    m_texture.create(textureFileName);
}

void TexturedModel::create(Mesh& mesh, const std::string& textureFileName)
{
    m_model.create(mesh);
    m_texture.create(textureFileName);
}

const Model& TexturedModel::getModel() const
{
    return m_model;
}

const Texture2D& TexturedModel::getTexture() const
{
    return m_texture;
}

