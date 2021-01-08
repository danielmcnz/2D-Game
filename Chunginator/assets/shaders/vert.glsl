#version 430 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;
layout(location = 2) in vec2 texCoords;
layout(location = 3) in float texIndex;

out vec4 Color;
out vec2 TexCoords;
out float TexIndex;

uniform mat4 u_Projection;
uniform mat4 u_View;
uniform mat4 u_Model;

void main()
{
	gl_Position = u_Projection * u_View * u_Model * vec4(position, 1.0);
	Color = color;
	TexCoords = texCoords;
	TexIndex = texIndex;
}