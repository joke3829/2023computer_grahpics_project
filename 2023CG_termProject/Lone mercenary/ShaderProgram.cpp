#include "ShaderProgram.h"

ShaderProgram* ShaderProgram::pShader = nullptr;

// 디폴트 생성자
ShaderProgram::ShaderProgram()
{
	Initialize();
}

// 파괴자
ShaderProgram::~ShaderProgram()
{
	DeleteShader();
}

// 싱글톤 사용, pShader를 반환하고 없으면 생성한다
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

// 사용이 끝나면 삭제
void ShaderProgram::DeleteShader()
{
	if (nullptr != pShader) {
		delete pShader;
		pShader = nullptr;
	}
}

// 새로 만들었다면 초기화한다(셰이더 생성)
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
		std::cerr << "ERROR: shahderProgram 연결 실패\n" << errorLog << std::endl;
		return;
	}

	glUseProgram(s_program);
}

// 셰이더 읽기 함수
char* ShaderProgram::filetobuf(std::string file)
{
	static std::string buf = "";
	buf = "";
	std::ifstream fin(file);
	if (not fin) {
		std::cout << file << "파일을 찾지 못했습니다. " << std::endl;
		return 0;
	}
	fin >> std::noskipws;
	char a;
	while (fin >> a) {
		buf += a;
	}
	char* c = const_cast<char*>(buf.c_str());
	//std::cout << c << std::endl;
	/*char* c = new char[buf.size() + 1];
	std::copy(buf.begin(), buf.end(), c);
	c[buf.size()] = '\0';
	std::cout << c << std::endl;*/
	return c;
}

// 버텍스 셰이더 생성 함수
bool ShaderProgram::CreateVertexShader()
{
	vertexSource = filetobuf("ShaderFile\\VertexShader.glsl");
	if (!vertexSource)
		std::cout << "꺼지셈 ㅇㅇ" << '\n';
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);

	GLint result;
	GLchar errorLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
	if (not result) {
		glGetShaderInfoLog(vertexShader, 512, NULL, errorLog);
		std::cerr << "ERROR: vertex shader 컴파일 실패\n" << errorLog << std::endl;
		return false;
	}
	return true;
}

// 프레그먼트 셰이더 생성 함수
bool ShaderProgram::CreateFragmentShader()
{
	fragSource = filetobuf("ShaderFile\\FragmentShader.glsl");
	if (!fragSource)
		std::cout << "ee꺼지셈 ㅇㅇ" << '\n';
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragSource, NULL);
	glCompileShader(fragmentShader);

	GLint result;
	GLchar errorLog[512];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);
	if (not result) {
		glGetShaderInfoLog(vertexShader, 512, NULL, errorLog);
		std::cerr << "ERROR: vertex shader 컴파일 실패\n" << errorLog << std::endl;
		return false;
	}
	return true;
}



