//===========================================================
// ProjObj.h
// ������ȯ�� �����ϴ� ���
//===========================================================
			   
#include "stdafx.h"
			   
class ShaderProgram;
class ProjObj {
public:
	ProjObj();
	
	// �ʿ��ϸ� ���� �Լ� �߰�

protected:
private:
	ShaderProgram* shader;
	float fovy;
	float aspect;
	float n;
	float f;

	glm::mat4 ProjMatrix;

	void Initialize();
	void OutToShader();
};