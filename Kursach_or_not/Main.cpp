#include"Global_vars.h"
#include"Mouse_keyboard.h"

#include"VennDiagram.h"


using namespace std;

void change(int w, int h);

extern char* buff;				//������ �����
extern int input_mode;			//������, 2, 1 ��� 3 �������
extern float param1, param2;
extern float white[3];
extern float black[3];
extern bool printable;
extern int diag_mode;
extern bool build;				//������ ��� ����������	��������
extern bool confirm;		    //������ ��� ���������� �������
extern char***table;

int main(int argc, char* argv[]) {
	allocate_table();
	strcpy(buff, "");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(900, 500);
	glutCreateWindow("Diagrams");
	glutDisplayFunc(renderScene);
	glutMouseFunc(test);
	glutKeyboardFunc(input1);
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}
	glutMainLoop();
	return 0;
}

void change(int w, int h)
{
	param1 = w;
	param2 = h;
}



