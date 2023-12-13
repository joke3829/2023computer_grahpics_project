

#include "MainApp.h"
#include "Mouse.h"
#pragma comment(lib, "freeglut")
#pragma comment(lib, "glew32")


GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);



int width, height;			// 종횡 크기
double frameTime;			// 출력 시간


void Timer(int);			// 타이머 요소

MainApp* mainApp;			// MainApp 포인터

void main(int argc, char** argv)
{
	width = 1280;
	height = 720;
	frameTime = 1000.0f / 60.0f;			// 1초에 60번 출력
	//윈도우 생성하기
	glutInit(&argc, argv);							// glut 초기화
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);	// 디스플레이 모드 설정
	glutInitWindowPosition(100, 100);				// 윈도우의 위치 지정
	glutInitWindowSize(width, height);					// 윈도우의 크기 지정
	glutCreateWindow("Lone Mercenary");					// 윈도우 생성(윈도우 이름)
	
	//GLEW 초기화하기
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)						//glew 초기화
	{
		std::cerr << "Unable to initialize GLEW" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
		std::cout << "GLEW Initialized\n";

	//============================================================
	mainApp = new MainApp;								// MainApp 생성
	if (not mainApp->Initialize()) {				// MainApp 초기화
		std::cout << "MainApp 초기화 실패!" << std::endl;
		return;
	}
	//============================================================

	glutDisplayFunc(drawScene);						// 출력 함수의 지정
	glutReshapeFunc(Reshape);						// 다시 그리기 함수 지정
	glutKeyboardFunc([](unsigned char key, int x, int y) {
		mainApp->pKeyboard->Keyboard(key, x, y);
	});						// 키 누를 때
	glutKeyboardUpFunc([](unsigned char key, int x, int y) {
		mainApp->pKeyboard->KeyboardUp(key, x, y);
	});					// 키 뗄때

	glutMotionFunc([](int x, int y) {
		mainApp->pMouse->MotionPassive(x, y);
	});
	glutPassiveMotionFunc([](int x,int y) {			// motionPassive
		mainApp->pMouse->MotionPassive(x, y);
	});
	glutMouseFunc([](int button,int state,int x, int y) {
		mainApp->pMouse->Mouse(button,state,x, y);
	});
	glutTimerFunc(frameTime, Timer, 0);
	glutMainLoop();									// 이벤트 처리 시작
}

GLvoid drawScene()									// 콜백 함수: 그리기 콜백 함수
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	mainApp->next_state();
	if (not mainApp->Render())
		return;

	glutSwapBuffers();								// 화면에 출력하기
}

GLvoid Reshape(int w, int h)						// 콜백 함수: 다시 그리기 콜백 함수
{
	glViewport(0, 0, w, h);
}

void Timer(int value)
{
	mainApp->Update_MainApp();
	glutPostRedisplay();
	glutTimerFunc(frameTime, Timer, 0);
}