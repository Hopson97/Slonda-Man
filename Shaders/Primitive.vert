#version 330

layout (location = 0) in vec3 inVertexPosition;

uniform mat4 modelMatrix;
uniform mat4 projectionViewMatrix;

void main()
{
    gl_Position = /*projectionViewMatrix *  modelMatrix **/ vec4(inVertexPosition.xyz, 1.0f);
}
