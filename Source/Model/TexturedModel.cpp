#include "TexturedModel.h"

#include "ModelLoader.h"

TexturedModel::TexturedModel(const std::string& modelFileName, const std::string& textureFileName)
:   m_texture   (textureFileName)
{
    auto mesh = loadObjModel(modelFileName);
    m_model.create(mesh);
}

void TexturedModel::create(const std::string& modelFileName, const std::string& textureFileName)
{
    auto mesh = loadObjModel(modelFileName);
    m_model.create(mesh);
}

void TexturedModel::create(Mesh& mesh, const std::string& textureFileName)
{
    m_model.create(mesh);
}

const Model& TexturedModel::getModel() const
{
    return m_model;
}

const Texture2D& TexturedModel::getTexture() const
{
    return m_texture;
}

