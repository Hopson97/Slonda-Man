#version 330

out vec4 outColour;

in vec2 passTexCoord;
in vec3 passNormalDirection;
in vec3 passToLight;
in vec3 passLightDir;

uniform sampler2D tex;

void main()
{
    vec3 nNormal    = normalize(passNormalDirection);
    vec3 nToLight   = normalize(passToLight);
    vec3 nLightDir  = normalize(passLightDir);

    float dir = dot(nNormal, nToLight);
    float light = max(dir, 0.01);

    outColour = light * texture(tex, passTexCoord);
}
