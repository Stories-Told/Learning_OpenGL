#version 330 core
layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 aColor;

out vec4 ourColor;
out vec3 triColor;

void main()
{
	gl_Position = vec4(pos, 1.0);
	ourColor = vec4(0.5, 0.0, 0.0, 1.0);
	triColor = aColor;
}