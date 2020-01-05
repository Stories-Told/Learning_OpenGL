#version 330 core

out vec4 threeColors;

in vec3 triColor;

void main()
{
	threeColors = vec4(triColor,1.0f);
}