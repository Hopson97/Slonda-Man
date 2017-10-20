#version 330

out vec4 outColour;

in vec2 passTexCoord;

in vec3 passNormalDirection;
in vec3 passToLight;
in vec3 passLightDir;
in float passDistanceToLight;

uniform sampler2D tex;

const int MAX_DISTANCE = 50;

void main()
{
    vec3 nNormal    = normalize(passNormalDirection);
    vec3 nToLight   = normalize(passToLight);

    if (passDistanceToLight >= MAX_DISTANCE)
    {
        outColour = 0.01f * texture(tex, passTexCoord);
    }
    else
    {
        float dist = 1 - (passDistanceToLight / MAX_DISTANCE);// / passDistanceToLight;
        float dir = dot(nNormal, nToLight) * dist;
        float light = max(dir, 0.01);

        outColour = light * texture(tex, passTexCoord);
    }
}
