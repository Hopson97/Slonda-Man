#version 330

layout (location = 0) in vec3 inVertexCoord;
layout (location = 1) in vec3 inTextureCoords;

out vec3 passTexCoord;

void main()
{
    gl_Position = vec4(inVertexCoord, 1.0f);
    passTexCoord = inTextureCoords;
}