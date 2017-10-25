#version 330

layout (location = 0) in vec3 inVertexPosition;
layout (location = 1) in vec2 inTextureCoord;
layout (location = 2) in vec3 inNormal;

uniform vec3 lightDirection;
uniform vec3 lightPosition;

uniform mat4 modelMatrix;
uniform mat4 projectionViewMatrix;

out vec2 passTexCoord;
out vec3 passNormalDirection;
out vec3 passVectorToLight;
out vec3 passLightDirection;
out float passDistanceToLight;

out vec3 passLightPos;

void main()
{
    vec4 worldPosition = modelMatrix * vec4(inVertexPosition, 1.0f);
    gl_Position = projectionViewMatrix *  worldPosition;

    passNormalDirection = (modelMatrix * vec4(inNormal, 0.0f)).xyz;
    passVectorToLight   = lightPosition - worldPosition.xyz;

    passTexCoord = inTextureCoord * 128;
    passLightDirection = lightDirection;
    passDistanceToLight = distance(worldPosition.xyz, lightPosition);

    passLightPos = lightPosition;
}
