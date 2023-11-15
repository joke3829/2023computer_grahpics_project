
#include "ShaderProgram.h"
#include "CameraObj.h"

// ����Ʈ ������
CameraObj::CameraObj() {
	Initialize();
}

// �ı���
CameraObj::~CameraObj() {};

// ī�޶� �ʱ�ȭ
void CameraObj::Initialize()
{
	shader = ShaderProgram::getShader();
	cameraEYE = glm::vec3(10, 0, 0);
	cameraAT = glm::vec3(0.0f);
	cameraUP = glm::vec3(0, 1, 0);
	OutToShader();
}

// uniform�� �־��ִ� �Լ�, ��Ұ� �ٲ�� �� ����������
void CameraObj::OutToShader()
{
	viewMatrix = glm::mat4(1.0f);
	viewMatrix = glm::lookAt(cameraEYE, cameraAT, cameraUP);
	// VertexShader�� view ��ġ�� �޾� �ֱ�
	int uni = glGetUniformLocation(shader->s_program, "view");
	if (uni < 0)
		std::cout << "uniform ������ ã�� ���߽��ϴ�!" << std::endl;
	glUniformMatrix4fv(uni, 1, GL_FALSE, &viewMatrix[0][0]);
	// FragmentShader�� ī�޶� ��ġ �����ֱ�
	uni = glGetUniformLocation(shader->s_program, "viewPos");
	if (uni < 0)
		std::cout << "uniform ������ ã�� ���߽��ϴ�!" << std::endl;
	glUniform3fv(uni, 1, glm::value_ptr(cameraEYE));		// Ȯ�� �ʿ�
}