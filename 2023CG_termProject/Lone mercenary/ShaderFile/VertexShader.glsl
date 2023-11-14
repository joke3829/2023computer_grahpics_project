#version 330 core

in vec3 vPos;
in vec3 vColor;
in vec3 vNormal;

out vec3 PassColor;
out vec3 PassNormal;
out vec3 FragPos;

uniform mat4 transform;
uniform mat4 view;
uniform mat4 proj;

void main()
{
	gl_Position = proj * view * transform * vec4(vPos, 1.0f);
	FragPos = vec3(transform * vec4(vPos, 1.0f));
	PassNormal = vec3(transform * vec4(vNormal, 1.0f));
	//PassNormal = vNormal;
	PassColor = vColor;
}