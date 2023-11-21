
#include "ShaderProgram.h"
#include "ProjObj.h"

// ����Ʈ ������
ProjObj::ProjObj() {
	Initialize();
}

// �ʱ�ȭ �Լ�
void ProjObj::Initialize()
{
	shader = ShaderProgram::getShader();
	fovy = 45;
	aspect = 1280.0f / 720.0f;
	n = 0.1;
	f = 200;
	OutToShader();
}

// ���̴��� �����ִ� �Լ�, ���������� ��Ұ� �ٲ�� �ҷ�����
void ProjObj::OutToShader()
{
	ProjMatrix = glm::mat4(1.0f);
	ProjMatrix = glm::perspective(glm::radians(fovy), aspect, n, f);
	int uni = glGetUniformLocation(shader->s_program, "proj");
	if (uni < 0)
		std::cout << "proj�� ã�� �� �����ϴ�" << std::endl;
	glUniformMatrix4fv(uni, 1, GL_FALSE, glm::value_ptr(ProjMatrix));
}