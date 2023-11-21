//===============================================================
// CameraObj.h
// ī�޶� �����ϴ� ���
//===============================================================

#include "stdafx.h"

class ShaderProgram;
class CameraObj {
public:
	CameraObj();
	
	// ī�޶� ���� �Լ� �߰�

protected:
private:
	ShaderProgram* shader;
	glm::vec3 cameraEYE;		// ī�޶� ��ġ
	glm::vec3 cameraAT;			// ī�޶� ���� ���� 
	glm::vec3 cameraUP;			// ī�޶� UP

	glm::mat4 viewMatrix;		// �亯ȯ ���

	glm::vec2 rotation_angle;	// ī�޶� ȸ�� ��
	float camera_dis;			// EYE - AT�� ũ��

	void OutToShader();
	void Initialize();
};