//============================================================
// Mesh.h
// �޽� ��� �� ���� ���
// ��� ���� ���� ��ȯ �������
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
	// �ؽ��� �߰� ����
	std::vector<glm::vec3> vertexs;			// ����
	std::vector<glm::vec3> colors;			// �÷�(�Ƹ� ���� ����, �ؽ�ó)
	std::vector<glm::vec3> vertex_normal;	// �븻
	std::vector<unsigned int> index;

	glm::mat4 modelTrans;					// �𵨸� ��ȯ
	// �̺κ� ������ ������� ��
	glm::vec3 init_pos;				// �ʱ� ���� ��ġ
	glm::vec3 cur_loc;				// ���� ��ġ
	glm::vec3 init_rot;				// �ʱ� ȸ��
	glm::vec3 cur_rot;				// ���� ȸ�� ��

	bool ReadOBJ(std::string);		// OBJ�о����
	void Initialize(std::string);				// �ʱ�ȭ
	ShaderProgram* shader;
private:
};