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
	void Render() const;
protected:
	unsigned int triangle_num;
	GLuint VAO, VBO[3], EBO;
	// �ؽ��� �߰� ����
	std::vector<glm::vec3> vertexs;			// ����
	std::vector<glm::vec3> colors;			// �÷�(�Ƹ� ���� ����, �ؽ�ó)
	std::vector<glm::vec3> vertex_normal;	// �븻
	std::vector<unsigned int> index;

	glm::mat4 scaleMatrix;					// ������
	glm::mat4 rotateMatrix;					// ����
	glm::mat4 transMatrix;					// �̵�

	bool ReadOBJ(std::string);		// OBJ�о����
	void Initialize(std::string);				// �ʱ�ȭ
	ShaderProgram* shader;
private:
};