#version 330 core

in vec3 PassColor;
in vec3 PassNormal;
in vec3 FragPos;

out vec4 FragColor;

uniform vec3 veiwPos;
//uniform vec3 lightPos;		// ���� ��ġ
//uniform vec3 lightColor;	// ������ ��

void main()
{
	vec3 lightColor = vec3(1.0, 1.0, 1.0);
	vec3 lightPos = vec3(0.0, 20.0, 0.0);
	vec3 lightPower = lightColor; // (length(lightColor - FragPos)*0.35);
	vec3 ambientLight = vec3(0.3);
	vec3 ambient = ambientLight * lightColor;

	vec3 normalVector = normalize(PassNormal);
	//vec3 lightDir = normalize(lightPos - FragPos);
	vec3 lightDir = normalize(vec3(0, 1, -1));

	float diffuseLight = max(dot(normalVector, lightDir), 0.0);
	vec3 diffuse = diffuseLight * lightPower;

	int sh = 128;
	vec3 viewDir = normalize(veiwPos - FragPos);
	vec3 reflectDir = reflect(lightDir, normalVector);
	float specularLight = max(dot(viewDir, reflectDir), 0.0);
	specularLight = pow(specularLight, sh);
	vec3 specular = specularLight * lightPower;
	
	vec3 result = (diffuse * PassColor) + (specular * PassColor) + (ambient * PassColor);
	
	FragColor = vec4(result, 1.0);
}