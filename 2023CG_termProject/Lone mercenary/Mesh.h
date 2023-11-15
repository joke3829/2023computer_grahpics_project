//============================================================
// Mesh.h
// 메쉬 출력 맟 관리 헤더
// 상속 시켜 각자 변환 사용하자
//============================================================

#include "stdafx.h"

class ShaderProgram;
class Mesh {
public:
	Mesh(std::string);
	virtual ~Mesh();
	void init_scale(float);
	void init_position(float, float, float);
	void init_rotate(float, float, float, float);
	void Render();
protected:
	unsigned int triangle_num;
	GLuint VAO, VBO[3], EBO;
	// 텍스쳐 추가 예정
	std::vector<glm::vec3> vertexs;			// 정점
	std::vector<glm::vec3> colors;			// 컬러(아마 삭제 예상, 텍스처)
	std::vector<glm::vec3> vertex_normal;	// 노말
	std::vector<unsigned int> index;

	glm::mat4 modelTrans;					// 모델링 변환
	// 이부분 나한테 물어봐라 꼭
	glm::vec3 init_pos;				// 초기 지정 위치
	glm::vec3 cur_loc;				// 현재 위치
	glm::vec3 init_rot;				// 초기 회전
	glm::vec3 cur_rot;				// 현재 회전 각

	bool ReadOBJ(std::string);		// OBJ읽어오기
	void Initialize(std::string);				// 초기화
	ShaderProgram* shader;
private:
};