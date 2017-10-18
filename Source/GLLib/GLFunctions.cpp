#include "GLFunctions.h"

void GL::drawElements(GLuint indicesCount)
{
    glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_INT, nullptr);
}

GLuint GL::getUniformLocation(GLuint program, const GLchar* name)
{
    return glGetUniformLocation(program, name);
}

void GL::loadUniform(GLuint location, const glm::mat4& matrix)
{
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}
