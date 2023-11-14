//==============================================================
// ShaderProgram.h
// ���̴� ���α׷��� ����, ��ȯ ���ش�.
//==============================================================

#include "stdafx.h"

class ShaderProgram {
public:
	ShaderProgram();
	~ShaderProgram();

	GLuint s_program;					// Ŭ������ ����Ű�� �� ���̴�
	static ShaderProgram* getShader();			// ���̴��� ��ȯ���ش�
	void DeleteShader();				// ����� ������ ��ȯ
	void Initialize();					// ���̴� ����
protected:
private:
	
	char* filetobuf(std::string);
	bool CreateVertexShader();
	bool CreateFragmentShader();
	
	
	static ShaderProgram* pShader;
	GLchar* vertexSource;
	GLchar* fragSource;
	GLuint vertexShader;
	GLuint fragmentShader;
};