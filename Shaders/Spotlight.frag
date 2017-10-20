#version 330

out vec4 outColour;

in vec2 passTexCoord;
in vec3 passNormalDirection;
in vec3 passToLight;

uniform sampler2D tex;

void main()
{
    vec3 nNormal  = normalize(passNormalDirection);
    vec3 nToLight = normalize(passToLight);

    float dir = dot(nNormal, nToLight);
    float light = max(dir, 0.1);

    outColour = light * texture(tex, passTexCoord);
}
