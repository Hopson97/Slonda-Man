#version 330

out vec4 outColour;

in vec2 passTexCoord;

in vec3 passNormalDirection;    //Normal vector of vertex
in vec3 passVectorToLight;      //Vector which is vertex position - light position
in vec3 passLightDirection;     //Direction of the light source
in float passDistanceToLight;   //Distance from vertex to light source

uniform sampler2D tex;
const int MAX_DISTANCE = 10;

float getLight(float minAngle)
{
    vec3 nNormal        = normalize(passNormalDirection);
    vec3 nVectorToLight = normalize(passVectorToLight);

    //"angle" between direction of object to light, and the light's direction
    float angle = dot(passLightDirection, nVectorToLight);

    if (angle < minAngle)
    {
        return 0;
    }

    //apply an attenuation factor
    float dist = 1 - (passDistanceToLight / MAX_DISTANCE);

    //angle of surface normal and direction of object to light
    float light = dot(nNormal, nVectorToLight);

    light *= 1 - (angle - minAngle);

    return light * dist;
}

void main()
{
    if (passDistanceToLight > MAX_DISTANCE * 10)
    {
        outColour = vec4(0, 0, 0, 1);
        return;
    }
    outColour = texture(tex, passTexCoord);
    if (outColour.a < 0.3)
    {
        discard;
    }
    outColour *= max(getLight(0.685), 0.07);
}













