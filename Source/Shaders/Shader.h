#ifndef SHADER_H_INCLUDED
#define SHADER_H_INCLUDED

#include <string>
#include <GL/glew.h>

#include "../Util/NonCopyable.h"
#include "../Util/NonMoveable.h"

class Shader : public NonCopyable, public NonMovable
{
    public:
        Shader( const std::string& vertexShader,
                const std::string& fragmentShader);
        ~Shader();

        void useProgram() const;

        GLuint getShaderID() const;
        GLuint getUniformLocation(const GLchar* name) const;

    private:
        GLuint m_shaderProgram;
};

#endif // SHADER_H_INCLUDED
