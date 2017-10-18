#version 330

out vec4 outColour;

in vec2 passTexCoord;

uniform sampler2D tex;

void main()
{
    outColour = texture(tex, passTexCoord);
}
