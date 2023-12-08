
#include "ShaderProgram.h"
#include "ProjObj.h"

// 디폴트 생성자
ProjObj::ProjObj() {
	Initialize();
}

// 초기화 함수
void ProjObj::Initialize()
{
	shader = ShaderProgram::getShader();
	fovy = 45;
	aspect = 1280.0f / 720.0f;
	n = 0.1;
	f = 800;
	OutToShader();
}

// 셰이더로 보내주는 함수, 마찬가지로 요소가 바뀌면 불러주자
void ProjObj::OutToShader()
{
	ProjMatrix = glm::mat4(1.0f);
	ProjMatrix = glm::perspective(glm::radians(fovy), aspect, n, f);
	int uni = glGetUniformLocation(shader->s_program, "proj");
	if (uni < 0)
		std::cout << "proj를 찾을 수 없습니다" << std::endl;
	glUniformMatrix4fv(uni, 1, GL_FALSE, glm::value_ptr(ProjMatrix));
}