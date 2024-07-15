#version 410 core

layout (location = 0) in vec3 position;

layout (std140) uniform mvp
{
	mat4 proj;
	mat4 view;
};

uniform mat4 model;


void main()
{
	gl_Position = proj * view * model * vec4(position, 1.0);
}