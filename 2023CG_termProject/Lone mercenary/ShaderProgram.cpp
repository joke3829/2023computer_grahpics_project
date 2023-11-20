#include "ShaderProgram.h"

ShaderProgram* ShaderProgram::pShader = nullptr;

// ����Ʈ ������
ShaderProgram::ShaderProgram()
{
	Initialize();
}

// �ı���
ShaderProgram::~ShaderProgram()
{
	DeleteShader();
}

// �̱��� ���, pShader�� ��ȯ�ϰ� ������ �����Ѵ�
ShaderProgram* ShaderProgram::getShader()
{
	if (nullptr == pShader) {
		pShader = new ShaderProgram;
		return pShader;
	}
	else {
		return pShader;
	}
}

// ����� ������ ����
void ShaderProgram::DeleteShader()
{
	if (nullptr != pShader) {
		delete pShader;
		pShader = nullptr;
	}
}

// ���� ������ٸ� �ʱ�ȭ�Ѵ�(���̴� ����)
void ShaderProgram::Initialize()
{
	if (not CreateVertexShader())
		return;
	if (not CreateFragmentShader())
		return;
	s_program = glCreateProgram();

	glAttachShader(s_program, vertexShader);
	glAttachShader(s_program, fragmentShader);

	glLinkProgram(s_program);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	GLint result;
	GLchar errorLog[512];
	glGetProgramiv(s_program, GL_LINK_STATUS, &result);
	if (not result) {
		glGetProgramInfoLog(s_program, 512, NULL, errorLog);
		std::cerr << "ERROR: shahderProgram ���� ����\n" << errorLog << std::endl;
		return;
	}

	glUseProgram(s_program);
}

// ���̴� �б� �Լ�
char* ShaderProgram::filetobuf(std::string file)
{
	static std::string buf = "";
	buf = "";
	std::ifstream fin(file);
	if (not fin) {
		std::cout << file << "������ ã�� ���߽��ϴ�. " << std::endl;
		return 0;
	}
	fin >> std::noskipws;
	char a;
	while (fin >> a) {
		buf += a;
	}
	char* c = const_cast<char*>(buf.c_str());
	std::cout << c << std::endl;
	/*char* c = new char[buf.size() + 1];
	std::copy(buf.begin(), buf.end(), c);
	c[buf.size()] = '\0';
	std::cout << c << std::endl;*/
	return c;
}

// ���ؽ� ���̴� ���� �Լ�
bool ShaderProgram::CreateVertexShader()
{
	vertexSource = filetobuf("ShaderFile\\VertexShader.glsl");
	if (!vertexSource)
		std::cout << "������ ����" << '\n';
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	GLint result;
	GLchar errorLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
	if (not result) {
		glGetShaderInfoLog(vertexShader, 512, NULL, errorLog);
		std::cerr << "ERROR: vertex shader ������ ����\n" << errorLog << std::endl;
		return false;
	}
	return true;
}

// �����׸�Ʈ ���̴� ���� �Լ�
bool ShaderProgram::CreateFragmentShader()
{
	fragSource = filetobuf("ShaderFile\\FragmentShader.glsl");
	if (!fragSource)
		std::cout << "ee������ ����" << '\n';
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragSource, NULL);
	glCompileShader(fragmentShader);

	GLint result;
	GLchar errorLog[512];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);
	if (not result) {
		glGetShaderInfoLog(vertexShader, 512, NULL, errorLog);
		std::cerr << "ERROR: vertex shader ������ ����\n" << errorLog << std::endl;
		return false;
	}
	return true;
}



