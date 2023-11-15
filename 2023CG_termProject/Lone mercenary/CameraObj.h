//===============================================================
// CameraObj.h
// 카메라를 관리하는 헤더
//===============================================================

#include "stdafx.h"

class ShaderProgram;
class CameraObj {
public:
	CameraObj();
	~CameraObj();
	
	// 카메라 조작 함수 추가

protected:
private:
	ShaderProgram* shader;
	glm::vec3 cameraEYE;		// 카메라 위치
	glm::vec3 cameraAT;			// 카메라가 보는 방향 
	glm::vec3 cameraUP;			// 카메라 UP

	glm::mat4 viewMatrix;		// 뷰변환 행렬

	void OutToShader();
	void Initialize();
};