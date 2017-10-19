#ifndef GLFUNCTIONS_H_INCLUDED
#define GLFUNCTIONS_H_INCLUDED

#include <vector>
#include <GL/glew.h>
#include "../Maths/GlmIncludes.h"
#include "GLEnums.h"

/*
    These functions are here just for a bit of fun.

    Also, it allows me to overload certain GLfunctions. For example, loadUniform.

    Also, they help with not supplying the wrong parameters to OpenGL.
    Every enum in OpenGL is inside of GLEnum, which makes it possible to supply invalid parameters without realising
    which can lead to crashes and that.

    Although you have to be rather silly to do that, like written above, this is mostly for fun :p
*/

namespace GL
{
    void drawElements(GLuint indicesCount);

    void loadUniform(GLuint location, const glm::mat4& matrix);
    void loadUniform(GLuint location, const glm::vec3& vector);
    void loadUniform(GLuint location, GLfloat n);

    void unbindAll();

    void enable(GL::Cap cap);
    void disable(GL::Cap cap);


    template <typename T>
    void bufferData(GL::BufferType buffer, const std::vector<T>& data)
    {
        glBufferData((GLenum)buffer,
                     data.size() * sizeof(T),
                     data.data(),
                     GL_STATIC_DRAW);
    }
}

#endif // GLFUNCTIONS_H_INCLUDED
