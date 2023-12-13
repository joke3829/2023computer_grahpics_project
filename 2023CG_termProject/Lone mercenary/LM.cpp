

#include "MainApp.h"
#include "Mouse.h"
#pragma comment(lib, "freeglut")
#pragma comment(lib, "glew32")
#pragma comment (lib, "fmod_vc.lib")

GLvoid drawScene(GLvoid);
GLvoid Reshape(int w, int h);



int width, height;			// ��Ⱦ ũ��
double frameTime;			// ��� �ð�


void Timer(int);			// Ÿ�̸� ���

MainApp* mainApp;			// MainApp ������

void main(int argc, char** argv)
{
	width = 1280;
	height = 720;
	frameTime = 1000.0f / 60.0f;			// 1�ʿ� 60�� ���
	//������ �����ϱ�
	glutInit(&argc, argv);							// glut �ʱ�ȭ
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);	// ���÷��� ��� ����
	glutInitWindowPosition(100, 100);				// �������� ��ġ ����
	glutInitWindowSize(width, height);					// �������� ũ�� ����
	glutCreateWindow("Lone Mercenary");					// ������ ����(������ �̸�)
	
	//GLEW �ʱ�ȭ�ϱ�
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)						//glew �ʱ�ȭ
	{
		std::cerr << "Unable to initialize GLEW" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
		std::cout << "GLEW Initialized\n";

	//============================================================
	mainApp = new MainApp;								// MainApp ����
	if (not mainApp->Initialize()) {				// MainApp �ʱ�ȭ
		std::cout << "MainApp �ʱ�ȭ ����!" << std::endl;
		return;
	}
	//============================================================

	glutDisplayFunc(drawScene);						// ��� �Լ��� ����
	glutReshapeFunc(Reshape);						// �ٽ� �׸��� �Լ� ����
	glutKeyboardFunc([](unsigned char key, int x, int y) {
		mainApp->pKeyboard->Keyboard(key, x, y);
	});						// Ű ���� ��
	glutKeyboardUpFunc([](unsigned char key, int x, int y) {
		mainApp->pKeyboard->KeyboardUp(key, x, y);
	});					// Ű ����

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
	glutMainLoop();									// �̺�Ʈ ó�� ����
}

GLvoid drawScene()									// �ݹ� �Լ�: �׸��� �ݹ� �Լ�
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	mainApp->next_state();
	if (not mainApp->Render())
		return;

	glutSwapBuffers();								// ȭ�鿡 ����ϱ�
}

GLvoid Reshape(int w, int h)						// �ݹ� �Լ�: �ٽ� �׸��� �ݹ� �Լ�
{
	glViewport(0, 0, w, h);
}

void Timer(int value)
{
	mainApp->Update_MainApp();
	glutPostRedisplay();
	glutTimerFunc(frameTime, Timer, 0);
}