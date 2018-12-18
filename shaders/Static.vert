#version 330

layout (location = 0) in vec2 inVertexCoord;

void main() {
    gl_Position = vec4(inVertexCoord.xy, 0.0, 1.0);
}