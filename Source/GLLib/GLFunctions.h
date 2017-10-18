#ifndef GLFUNCTIONS_H_INCLUDED
#define GLFUNCTIONS_H_INCLUDED

#include <GL/glew.h>
#include "../Maths/GlmIncludes.h"

namespace GL
{
    void drawElements(GLuint indicesCount);

    GLuint getUniformLocation(GLuint program, const GLchar* name);
    void loadUniform(GLuint location, const glm::mat4& matrix);
}

#endif // GLFUNCTIONS_H_INCLUDED
