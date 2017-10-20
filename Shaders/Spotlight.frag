#version 330

out vec4 outColour;

in vec2 passTexCoord;
in vec3 passNormalDirection;
in vec3 passVectorToLight;
in vec3 passLightDirection;
in float passDistanceToLight;

uniform sampler2D tex;
const int MAX_DISTANCE = 50;

float getLight()
{
    if (passDistanceToLight >= MAX_DISTANCE)
    {
        return 0.01f;
    }
    else
    {
        vec3 nNormal        = normalize(passNormalDirection);
        vec3 nVectorToLight = normalize(passVectorToLight);

        float angle = dot(passLightDirection, nVectorToLight);
        if (angle < 0.7)
        {
            return 0.01f;
        }
        else
        {
            float dist = 1 - (passDistanceToLight / MAX_DISTANCE);// / passDistanceToLight;
            float dir = dot(nNormal, nVectorToLight) * dist;

            float light = max(dir, 0.01);

            return light;
        }
    }
}

void main()
{
    float light = getLight();

    outColour = light * texture(tex, passTexCoord);
}













