#version 330

out vec4 outColour;

in vec2 passTexCoord;

in vec3 passNormalDirection;    //Normal vector of vertex
in vec3 passVectorToLight;      //Vector which is vertex position - light position
in vec3 passLightDirection;     //Direction of the light source
in float passDistanceToLight;   //Distance from vertex to light source

uniform sampler2D tex;
const int MAX_DISTANCE = 45;

in vec3 passLightPos;

struct Light
{
    vec3 position;
    vec3 direction;
    float cutoff;
    float outerCutoff;
};

Light makeLight(float cutoff, float outerCutoff)
{
    Light light;
    light.position      = passLightPos;
    light.direction     = passLightDirection;
    light.cutoff        = cos(radians(cutoff));
    light.outerCutoff   = cos(radians(outerCutoff));
    return light;
}

float getLight()
{
    //return 1;
    Light light = makeLight(12.0, 15.0);

    vec3 nNormal        = normalize(passNormalDirection);
    vec3 nVectorToLight = normalize(passVectorToLight);

    float theta = dot (nVectorToLight, light.direction);
    float epsilon   = light.cutoff - light.outerCutoff;
    float intensity = clamp((theta - light.outerCutoff) / epsilon, 0.0, 1.0);

    float dist = 1 - (passDistanceToLight / MAX_DISTANCE);
    float diffuse = dot(nNormal, nVectorToLight);
    return diffuse * intensity * dist;
}

void main()
{
    outColour = texture(tex, passTexCoord);
    if (outColour.a < 0.2)
    {
        discard;
    }
    outColour *= max(getLight(), 0.1);
}













