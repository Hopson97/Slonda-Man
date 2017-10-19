#include "TexturedModel.h"

#include "ModelLoader.h"

int TexturedModel::id = 0;

TexturedModel::TexturedModel(const std::string& modelFileName, const std::string& textureFileName)
:   m_texture   (textureFileName)
{
    auto mesh = loadObjModel(modelFileName);
    m_model.create(mesh);
    m_id = id++;
}

const Model& TexturedModel::getModel() const
{
    return m_model;
}

const Texture2D& TexturedModel::getTexture() const
{
    return m_texture;
}

int TexturedModel::getID()
{
    return m_id;
}

