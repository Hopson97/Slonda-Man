#ifndef TEXTURECUBE_H_INCLUDED
#define TEXTURECUBE_H_INCLUDED

#include "../Glad/glad.h"
#include <array>
#include <string>

#include "../Util/NonCopyable.h"

//right
//left
//top
//bottom
//back
//front

class TextureCube : public NonCopyable
{
    public:
        TextureCube() = default;
        TextureCube(const std::array<std::string, 6>& textureFiles);

        TextureCube             (TextureCube&&);
        TextureCube& operator=  (TextureCube&&);

        ~TextureCube();

        void loadFromFiles(const std::array<std::string, 6>& textureFiles);

        void bind();

    private:
        GLuint m_textureID;


};

#endif // TEXTURECUBE_H_INCLUDED
