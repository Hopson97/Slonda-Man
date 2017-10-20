#version 330

layout (location = 0) in vec3 inVertexPosition;
layout (location = 1) in vec2 inTextureCoord;
layout (location = 2) in vec3 inNormal;

uniform mat4 modelMatrix;
uniform mat4 projectionViewMatrix;

out vec2 passTexCoord;

void main()
{
    gl_Position = projectionViewMatrix *  modelMatrix * vec4(inVertexPosition, 1.0f);

    passTexCoord = inTextureCoord;
}
