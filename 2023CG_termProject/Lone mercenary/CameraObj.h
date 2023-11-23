//===============================================================
// CameraObj.h
// ī�޶� �����ϴ� ���
//===============================================================
#pragma once
#include "stdafx.h"

class ShaderProgram;
class CameraObj {
public:
	CameraObj();
	
	// ī�޶� ���� �Լ� �߰�
	void setCameraEYE(glm::vec3);			// player��ġ �޾ƿ���
	void setCameraAngle(glm::vec2);			// ��������, player�� �޾ƿ���
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