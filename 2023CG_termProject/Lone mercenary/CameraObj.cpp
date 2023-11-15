
#include "ShaderProgram.h"
#include "CameraObj.h"

// 디폴트 생성자
CameraObj::CameraObj() {
	Initialize();
}

// 파괴자
CameraObj::~CameraObj() {};

// 카메라 초기화
void CameraObj::Initialize()
{
	shader = ShaderProgram::getShader();
	cameraEYE = glm::vec3(10, 0, 0);
	cameraAT = glm::vec3(0.0f);
	cameraUP = glm::vec3(0, 1, 0);
	OutToShader();
}

// uniform에 넣어주는 함수, 요소가 바뀌면 꼭 실행해주자
void CameraObj::OutToShader()
{
	viewMatrix = glm::mat4(1.0f);
	viewMatrix = glm::lookAt(cameraEYE, cameraAT, cameraUP);
	// VertexShader의 view 위치를 받아 넣기
	int uni = glGetUniformLocation(shader->s_program, "view");
	if (uni < 0)
		std::cout << "uniform 변수를 찾지 못했습니다!" << std::endl;
	glUniformMatrix4fv(uni, 1, GL_FALSE, &viewMatrix[0][0]);
	// FragmentShader의 카메라 위치 보내주기
	uni = glGetUniformLocation(shader->s_program, "viewPos");
	if (uni < 0)
		std::cout << "uniform 변수를 찾지 못했습니다!" << std::endl;
	glUniform3fv(uni, 1, glm::value_ptr(cameraEYE));		// 확인 필요
}