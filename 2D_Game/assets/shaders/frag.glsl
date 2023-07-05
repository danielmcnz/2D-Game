#version 430 core

layout(location = 0) out vec4 outColor;

in vec4 Color;
in vec2 TexCoords;
in float TexIndex;

uniform sampler2D u_Textures[32];

void main()
{
	int index = int(TexIndex);
	outColor = texture(u_Textures[index], TexCoords);
}