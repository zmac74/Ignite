#version 330 core

in vec4 color; 
in vec4 vcolor;

out vec4 fragColor;

uniform vec3 c;

void main()
{
	fragColor = mix(color, vcolor, 0.75);
}