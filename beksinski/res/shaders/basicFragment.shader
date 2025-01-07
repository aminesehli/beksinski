#shader fragment
#version 330 core

layout(location = 0) out vec4 colour;

uniform vec4 u_Color;

void main()
{
colour = u_Color;
};