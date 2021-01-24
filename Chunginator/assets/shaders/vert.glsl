#version 430 core

layout(location = 0) in vec4	a_Position;
layout(location = 1) in vec4 	a_Color;
layout(location = 2) in vec2 	a_TexCoords;
layout(location = 3) in float	a_TexIndex;

out vec4	Color;
out vec2	TexCoords;
out float	TexIndex;

uniform mat4 u_Projection;
uniform mat4 u_View;
uniform mat4 u_Model;

void main()
{
	gl_Position = u_Projection * u_View * u_Model * a_Position;
	Color =	a_Color;
	TexCoords = a_TexCoords;
	TexIndex = a_TexIndex;
}