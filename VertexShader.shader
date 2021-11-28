#version 330 core

layout (location = 0) in vec3 iPosition;
layout (location = 1) in vec2 iTextureCoord;
layout (location = 2) in vec3 iNormal;
layout (location = 3) in vec4 iColor;

out vec4 color;
out vec4 vcolor;

uniform mat4 transform;
uniform mat4 camera;
uniform mat4 projection;

void main()
{
	gl_Position = projection * camera * transform * vec4(iPosition, 1.0);
	color = vec4(iNormal, 1.0);
	vcolor = iColor;
}