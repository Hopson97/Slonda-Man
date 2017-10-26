#ifndef TEXTUREDMODEL_H_INCLUDED
#define TEXTUREDMODEL_H_INCLUDED

#include "Model.h"
#include "../Texture/Texture2D.h"

class TexturedModel : public NonCopyable
{
    public:
        TexturedModel() = default;
        TexturedModel(const std::string& modelFileName, const std::string& textureFileName);

        TexturedModel               (TexturedModel&& other);
        TexturedModel& operator =   (TexturedModel&& other);

        ~TexturedModel() = default;

        void create(const std::string& modelFileName, const std::string& textureFileName);
        void create(Mesh& mesh, const std::string& textureFileName);

        const Model& getModel() const;
        const Texture2D& getTexture() const;

        int getID();

    private:
        Model      m_model;
        Texture2D  m_texture;
};

#endif // TEXTUREDMODEL_H_INCLUDED
