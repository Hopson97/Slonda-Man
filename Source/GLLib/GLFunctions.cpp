#include "GLFunctions.h"

namespace GL
{
    //
    //TEXTURES
    //
    void textureImage2D(const sf::Image& image, RGBA rbga)
    {
        glTexImage2D(GL_TEXTURE_2D,
                     0,
                     (GLint)rbga,
                     image.getSize().x,
                     image.getSize().y,
                     0,
                     (GLenum)rbga,
                     GL_UNSIGNED_BYTE,
                     image.getPixelsPtr());
    }




    //
    //  DRAWING
    //
    void drawElements(GLuint indicesCount)
    {
        glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_INT, nullptr);
    }

    //
    //  UNIFORMS
    //
    void loadUniform(GLuint location, const glm::mat4& matrix)
    {
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    void loadUniform(GLuint location, const glm::vec3& vector)
    {
        glUniform3fv(location, 1, glm::value_ptr(vector));
    }

    void loadUniform(GLuint location, GLfloat n)
    {
        glUniform1f(location, n);
    }

    //
    //  CAPABILITIES
    //
    void enable(GL::Cap cap)
    {
        glEnable((GLenum)cap);
    }

    void disable(GL::Cap cap)
    {
        glDisable((GLenum)cap);
    }

    //
    //  MISC
    //
    void unbindAll()
    {
        glDisable(GL_DEPTH_TEST);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        glBindTexture(GL_TEXTURE_2D, 0);
        glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
        glUseProgram(0);
        glBindRenderbuffer (GL_RENDERBUFFER, 0);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }
}
