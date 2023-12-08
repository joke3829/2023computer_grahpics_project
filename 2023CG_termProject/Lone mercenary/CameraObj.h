//===============================================================
// CameraObj.h
// 카메라를 관리하는 헤더
//===============================================================
#pragma once
#include "stdafx.h"

class ShaderProgram;
class CameraObj {
public:
	CameraObj();
	
	// 카메라 조작 함수 추가
	void setCameraEYE(glm::vec3);			// player위치 받아오자
	void setCameraAngle(glm::vec2);			// 마찬가지, player꺼 받아오자

	glm::vec3 getEYE();
	glm::vec3 getAT();
protected:
private:
	ShaderProgram* shader;
	glm::vec3 cameraEYE;		// 카메라 위치
	glm::vec3 cameraAT;			// 카메라가 보는 방향 
	glm::vec3 cameraUP;			// 카메라 UP

	glm::mat4 viewMatrix;		// 뷰변환 행렬

	glm::vec2 rotation_angle;	// 카메라 회전 각
	float camera_dis;			// EYE - AT의 크기

	void OutToShader();
	void Initialize();
};