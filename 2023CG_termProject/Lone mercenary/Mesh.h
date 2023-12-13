//============================================================
// Mesh.h
// 메쉬 출력 맟 관리 헤더
// 상속 시켜 각자 변환 사용하자
//============================================================
#pragma once
#include "stdafx.h"

class ShaderProgram;
class Mesh {
public:
	Mesh(std::string, std::string, int, int);
	virtual ~Mesh();

	void init_scale(float);							// 초기 스케일 조정
	void init_position(float, float, float);		// 초기 위치 설정
	void init_rotate(float, float, float, float);	// 초기 회전 설정

	void change_texture(std::string, int, int);

	void setLoc(glm::vec3);							// 위치 바꿔주기
	void setRot(glm::vec2);							// 회전율 바꿔주기
	void setAmb(float);

	glm::vec3 getLB();
	glm::vec3 getRT();
	glm::mat4 getModelTrans();

	bool collision_check(const Mesh&);		// 충돌체크용 함수

	void Render() const;

	static bool box_check;

protected:
	GLuint VAO, VBO[3];
	unsigned texture;
	GLuint B_VAO, B_VBO[3], B_EBO;	// 충돌체크용 박스

	std::vector<glm::vec3> vertexs;			// 정점
	std::vector<glm::vec3> texture_coor;	// 텍스쳐좌표
	std::vector<glm::vec3> vertex_normal;	// 노말


	glm::vec3 LB;			// Left-Bottom
	glm::vec3 RT;			// Right-Top

	// OBB용 박스
	glm::vec3 OBB_center;
	glm::vec3 axis[3];
	glm::vec3 radius;


	glm::mat4 modelTrans;

	glm::vec3 init_pos;			// 초기 위치 지정
	glm::vec3 cur_loc;			// 현재 위치

	glm::vec3 init_rot;			// 초기 회전
	glm::vec2 cur_rot;			// 현재 회전각

	
	glm::vec3 ambient;			// 엠비언트

	bool ReadOBJ(std::string);		// OBJ읽어오기
	void Initialize(std::string);				// 초기화
	void Init_texture(std::string, int, int);
	ShaderProgram* shader;
private:
};