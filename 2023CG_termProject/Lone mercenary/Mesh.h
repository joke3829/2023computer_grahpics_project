//============================================================
// Mesh.h
// �޽� ��� �� ���� ���
// ��� ���� ���� ��ȯ �������
//============================================================
#pragma once
#include "stdafx.h"

class ShaderProgram;
class Mesh {
public:
	Mesh(std::string, std::string, int, int);
	virtual ~Mesh();

	void init_scale(float);							// �ʱ� ������ ����
	void init_position(float, float, float);		// �ʱ� ��ġ ����
	void init_rotate(float, float, float, float);	// �ʱ� ȸ�� ����

	void change_texture(std::string, int, int);

	void setLoc(glm::vec3);							// ��ġ �ٲ��ֱ�
	void setRot(glm::vec2);							// ȸ���� �ٲ��ֱ�

	glm::vec3 getLB();
	glm::vec3 getRT();
	glm::mat4 getModelTrans();

	bool collision_check(const Mesh&);		// �浹üũ�� �Լ�

	void Render() const;

	static bool box_check;

protected:
	GLuint VAO, VBO[3];
	unsigned texture;
	GLuint B_VAO, B_VBO[3], B_EBO;	// �浹üũ�� �ڽ�

	std::vector<glm::vec3> vertexs;			// ����
	std::vector<glm::vec3> texture_coor;	// �ؽ�����ǥ
	std::vector<glm::vec3> vertex_normal;	// �븻


	glm::vec3 LB;			// Left-Bottom
	glm::vec3 RT;			// Right-Top

	// OBB�� �ڽ�
	glm::vec3 OBB_center;
	glm::vec3 axis[3];
	glm::vec3 radius;


	glm::mat4 modelTrans;
	glm::mat4 rotateMatrix;		// �븻 ���͸� ������ ���� ���

	glm::vec3 init_pos;			// �ʱ� ��ġ ����
	glm::vec3 cur_loc;			// ���� ��ġ

	glm::vec3 init_rot;			// �ʱ� ȸ��
	glm::vec2 cur_rot;			// ���� ȸ����


	bool ReadOBJ(std::string);		// OBJ�о����
	void Initialize(std::string);				// �ʱ�ȭ
	void Init_texture(std::string, int, int);
	ShaderProgram* shader;
private:
};