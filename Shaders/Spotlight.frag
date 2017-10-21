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

    //"angle" between direction of object to light, and the light's direction
    float angle = dot(passLightDirection, nVectorToLight);
    /*
    if (angle < 0.7)
    {
        return 0.01f;
    }*/

    //apply an attenuation factor
    float dist = 1 - (passDistanceToLight / MAX_DISTANCE);

    //angle of surface normal and direction of object to light
    float dir = dot(nNormal, nVectorToLight) * dist;

    //apply ambient light
    float light = max(dir, 0.2);

    return light;
}

void main()
{
    outColour = getLight() * texture(tex, passTexCoord);
}













