#pragma once
//==============================================================
// ShaderProgram.h
// 셰이더 프로그램을 생성, 반환 해준다.
//==============================================================

#include "stdafx.h"

class ShaderProgram {
public:
	ShaderProgram();
	~ShaderProgram();

	GLuint s_program;					// 클래스가 가르키는 실 셰이더
	static ShaderProgram* getShader();			// 셰이더를 반환해준다

protected:
private:
	
	char* filetobuf(std::string);
	bool CreateVertexShader();
	bool CreateFragmentShader();
	void Initialize();					// 셰이더 생성
	void DeleteShader();				// 사용이 끝나면 반환
	
	
	static ShaderProgram* pShader;
	GLchar* vertexSource;
	GLchar* fragSource;
	GLuint vertexShader;
	GLuint fragmentShader;
};