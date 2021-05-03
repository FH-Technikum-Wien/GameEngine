#version 330 core
layout (location = 0) in vec2 aPos;

uniform vec2 position;

void main()
{
    gl_Position = vec4(aPos + position, 0.0, 1.0);
}