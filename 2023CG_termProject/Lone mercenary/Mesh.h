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
	void Render() const;
protected:
	unsigned int triangle_num;
	GLuint VAO, VBO[3], EBO;
	// 텍스쳐 추가 예정
	std::vector<glm::vec3> vertexs;			// 정점
	std::vector<glm::vec3> colors;			// 컬러(아마 삭제 예상, 텍스처)
	std::vector<glm::vec3> vertex_normal;	// 노말
	std::vector<unsigned int> index;

	glm::mat4 scaleMatrix;					// 스케일
	glm::mat4 rotateMatrix;					// 자전
	glm::mat4 transMatrix;					// 이동

	bool ReadOBJ(std::string);		// OBJ읽어오기
	void Initialize(std::string);				// 초기화
	ShaderProgram* shader;
private:
};