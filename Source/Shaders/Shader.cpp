#include "Shader.h"

#include "ShaderLoader.h"

Shader::Shader(const std::string& vertexShader,
               const std::string& fragmentShader)
:   m_shaderProgram(loadShaders(vertexShader, fragmentShader))
{ }

Shader::~Shader()
{
    glDeleteProgram(m_shaderProgram);
}

void Shader::useProgram() const
{
    glUseProgram(m_shaderProgram);
}

GLuint Shader::getShaderID() const
{
    return m_shaderProgram;
}
