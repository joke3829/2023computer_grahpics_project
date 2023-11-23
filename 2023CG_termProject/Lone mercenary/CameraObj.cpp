
#include "ShaderProgram.h"
#include "CameraObj.h"

// ����Ʈ ������
CameraObj::CameraObj() {
	Initialize();
}

// ī�޶� �ʱ�ȭ
void CameraObj::Initialize()
{
	shader = ShaderProgram::getShader();
	camera_dis = 40;				// EYE - AT
	cameraEYE = glm::vec3(-20, 0, 0);
	cameraUP = glm::vec3(0, 1, 0);
	// ========================!�߿�!=====================
	// x�� �����ϸ� AT�� ���� �ٶ󺸴� ���⿡�� ��������
	// x�� �����ϸ� ����
	// y�� �����ϸ� ����
	// y�� �����ϸ� �Ʒ�
	// ���Ҹ��� �𸣰����� �����ش޶� �� �����
	// !�� ����� ������ �ȵ�� ���� �� ����!
	// ====================================================
	rotation_angle = glm::vec2(0, 0);
	OutToShader();
}

// uniform�� �־��ִ� �Լ�, ��Ұ� �ٲ�� �� ����������
void CameraObj::OutToShader()
{
	//ȸ�� ���� AT�� ���� EYE�� ���Ѵ�
	float xz_dis;
	xz_dis = fabs(camera_dis * glm::cos(glm::radians(rotation_angle.y)));

	cameraAT.x = cameraEYE.x + (xz_dis * glm::cos(glm::radians(rotation_angle.x)));
	cameraAT.y = cameraEYE.y + (camera_dis * glm::sin(glm::radians(rotation_angle.y)));
	cameraAT.z = cameraEYE.z + (xz_dis * glm::sin(glm::radians(rotation_angle.x)));

	viewMatrix = glm::mat4(1.0f);
	viewMatrix = glm::lookAt(cameraEYE, cameraAT, cameraUP);
	// VertexShader�� view ��ġ�� �޾� �ֱ�
	int uni = glGetUniformLocation(shader->s_program, "view");
	if (uni < 0)
		std::cout << "uniform ������ ã�� ���߽��ϴ�!" << std::endl;
	glUniformMatrix4fv(uni, 1, GL_FALSE, &viewMatrix[0][0]);
	// FragmentShader�� ī�޶� ��ġ �����ֱ�
	uni = glGetUniformLocation(shader->s_program, "veiwPos");
	if (uni < 0)
		std::cout << "uniform ������ ã�� ���߽��ϴ�!" << std::endl;
	glUniform3fv(uni, 1, glm::value_ptr(cameraEYE));		// Ȯ�� �ʿ�
}

void CameraObj::setCameraEYE(glm::vec3 new_loc)
{
	cameraEYE = new_loc;
	OutToShader();
}

void CameraObj::setCameraAngle(glm::vec2 new_rot)
{
	rotation_angle = new_rot;
	OutToShader();
}