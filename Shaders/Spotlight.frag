#version 330

out vec4 outColour;

in vec2 passTexCoord;

in vec3 passNormalDirection;    //Normal vector of vertex
in vec3 passVectorToLight;      //Vector which is vertex position - light position
in vec3 passLightDirection;     //Direction of the light source
in float passDistanceToLight;   //Distance from vertex to light source

uniform sampler2D tex;
const int MAX_DISTANCE = 25;

float getLight()
{
    vec3 nNormal        = normalize(passNormalDirection);
    vec3 nVectorToLight = normalize(passVectorToLight);

    float angle = dot(passLightDirection, nVectorToLight);
/*
    if (angle < 0.7)
    {
        return 0.01f;
    }
*/
    float dist = 1 - (passDistanceToLight / MAX_DISTANCE);// / passDistanceToLight;
    float dir = dot(nNormal, nVectorToLight) * dist;

    float light = max(dir, 0.01);

    return light;
}

void main()
{
    outColour = getLight() * texture(tex, passTexCoord);
}













