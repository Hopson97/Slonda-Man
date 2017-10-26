#ifndef TEXTURE2D_H_INCLUDED
#define TEXTURE2D_H_INCLUDED

#include <string>
#include <GL/glew.h>

#include "../Util/NonCopyable.h"
#include "../Util/NonMoveable.h"

class Texture2D : public NonCopyable
{
    public:
        Texture2D() = default;
        Texture2D(const std::string& texName);

        Texture2D& operator =   (Texture2D&& other);
        Texture2D               (Texture2D&& other);

        ~Texture2D();

        void create(const std::string& texName);

        void bind() const;

    private:
        GLuint m_texID;
};

#endif // TEXTURE2D_H_INCLUDED
