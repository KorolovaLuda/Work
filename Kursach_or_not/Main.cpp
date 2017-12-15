#include<iostream>
#include<Windows.h>
#include<GL\glew.h>
#include<GL\freeglut.h>
#include"Input_output.h"
#include"Global_vars.h"
#include"VennDiagram.h"

using namespace std;

void renderScene(void);
void test(int a, int b, int c, int d);
void change(int w, int h);
void drawmenu(); 
void drawVenDiagram();

extern char* buff;
extern int input_mode;
extern float param1, param2;
extern float white[3];
extern float black[3];

int main(int argc, char* argv[]) {
	/*param1 = 900;
	param2 = 500;
	buff = new char[100];*/
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


void renderScene(void) {
	drawmenu();
	if(input_mode==1)
		Drawinput1();
	glutSwapBuffers();
	DrawText(buff, strlen(buff), 51. * param1 / 90, 200, white);
}

void test(int a, int b, int c, int d) {
	drawmenu();
	if (a == GLUT_LEFT_BUTTON)
	{
		//glutReshapeFunc(change);
		cout << c << " | " << d << endl;
		if (c > 0 && c < param1 / 9.&&d>0 && d < param2 / 6.)
		{
			//график функции
			input_mode = 1; //ввод строки
			Drawinput1();
		}
		if (c > param1 / 9. && c < param1*2 / 9.&&d>0 && d < param2 / 6.)
		{
			//столбики
			input_mode = 3; //ввод 2 столбцов
		}
		if (c > param1 * 2 / 9. && c < param1 * 3 / 9.&&d>0 && d < param2 / 6.)
		{
			//области
			input_mode = 3; //ввод 2 столбцов
		}
		if (c > param1 * 3 / 9. && c < param1 * 4 / 9.&&d>0 && d < param2 / 6.)
		{
			//точки
			input_mode = 3; //ввод 2 столбцов
		}
		if (c > param1 * 4 / 9. && c < param1 * 5 / 9.&&d>0 && d < param2 / 6.)
		{
			//круговая диаграма
			input_mode = 2; //ввод 1 столбца
		}
		if (c > param1 * 5 / 9. && c < param1 * 6 / 9.&&d>0 && d < param2 / 6.)
		{
			//радиальная диаграма
			input_mode = 3; //ввод 2 столбцов
		}
		if (c > param1 * 6 / 9. && c < param1 * 7 / 9.&&d>0 && d < param2 / 6.)
		{
			//диаграма Вена
			drawVenDiagram();
			input_mode = 1; //ввод строки
			Drawinput1();
			DrawText("Input set:", 10, param1 * 3 / 9., param2*6.7 / 9,white);
		}
		if (c > param1 * 7 / 9. && c < param1 * 8 / 9.&&d>0 && d < param2 / 6.)
		{
			//векторная диаграма
			input_mode = 1; //ввод строки
			Drawinput1();
		}
		if (c > param1 * 8 / 9. && c < param1 &&d>0 && d < param2 / 6.)
		{
			//биржевые диаграмы
			input_mode = 4; //ввод 3 столбцов
		}

	}
	else
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	glutSwapBuffers();
}

void change(int w, int h)
{
	param1 = w;
	param2 = h;
}

void drow_button(float* x, float* y, float* color)
{
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0); glVertex3f(x[0], y[0], 0);
	glColor3f(1, 1, 0); glVertex3f(x[1], y[1], 0);
	glColor3f(1, 1, 0); glVertex3f(x[2], y[2], 0);
	glColor3f(1, 1, 0); glVertex3f(x[3], y[3], 0);
	glEnd();
}

void drawmenu()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(0.03, 0.21, 0.26); glVertex3f(-param1, param2, 0);
	glColor3f(0.03, 0.21, 0.26); glVertex3f(param1, param2, 0);
	glColor3f(0.03, 0.21, 0.26); glVertex3f(param1, -param2, 0);
	glColor3f(0.03, 0.21, 0.26); glVertex3f(-param1, -param2, 0);
	glEnd();
	for (int i = 0; i < 9; i++)
	{
		glBegin(GL_POLYGON);
		glColor3f(0, 0.21, 0); glVertex3f(-1 + i*2. / 9, 1, 0);
		glColor3f(0, 0.21, 0); glVertex3f(-7. / 9 + i*2. / 9, 1, 0);
		glColor3f(0, 0.21, 0); glVertex3f(-7. / 9 + i*2. / 9, 2. / 3, 0);
		glColor3f(0, 0.21, 0); glVertex3f(-1 + i*2. / 9, 2. / 3, 0);
		glEnd();
	}
	for (int i = 0; i < 9; i++)
	{
		glBegin(GL_LINE_LOOP);
		glColor3f(0, 0, 0); glVertex3f(-1 + i*2. / 9, 1, 0);
		glColor3f(0, 0, 0); glVertex3f(-7. / 9 + i*2. / 9, 1, 0);
		glColor3f(0, 0, 0); glVertex3f(-7. / 9 + i*2. / 9, 2. / 3, 0);
		glColor3f(0, 0, 0); glVertex3f(-1 + i*2. / 9, 2. / 3, 0);
		glEnd();
	}
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1); glVertex3f(-1, -1, 0);
	glColor3f(1, 1, 1); glVertex3f(-1, 2. / 3, 0);
	glColor3f(1, 1, 1); glVertex3f(-2. / 4, 2. / 3, 0);
	glColor3f(1, 1, 1); glVertex3f(-2. / 4, -1, 0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0); glVertex3f(-1, -1, 0);
	glColor3f(0, 0, 0); glVertex3f(-1, 2. / 3, 0);
	glColor3f(0, 0, 0); glVertex3f(-2. / 4, 2. / 3, 0);
	glColor3f(0, 0, 0); glVertex3f(-2. / 4, -1, 0);
	glEnd();
	char*t = "function";
	DrawText(t, strlen(t), param1 / 90, 480,white);
	t = "graph";
	DrawText(t, strlen(t), param1 / 90, 450,white);
	t = "stakes";
	DrawText(t, strlen(t), 11. * param1 / 90, 480,white);
	t = "regions";
	DrawText(t, strlen(t), 21. * param1 / 90, 480,white);
	t = "points";
	DrawText(t, strlen(t), 31. * param1 / 90, 480,white);
	t = "pie";
	DrawText(t, strlen(t), 41. * param1 / 90, 480,white);
	t = "chart";
	DrawText(t, strlen(t), 41. * param1 / 90, 460,white);
	t = "radial";
	DrawText(t, strlen(t), 51. * param1 / 90, 480,white);
	t = "diagram";
	DrawText(t, strlen(t), 51. * param1 / 90, 460,white);
	t = "Venn";
	DrawText(t, strlen(t), 61. * param1 / 90, 480,white);
	t = "diagram";
	DrawText(t, strlen(t), 61. * param1 / 90, 460,white);
	t = "vector";
	DrawText(t, strlen(t), 71. * param1 / 90, 480,white);
	t = "diagram";
	DrawText(t, strlen(t), 71. * param1 / 90, 460,white);
	t = "stock";
	DrawText(t, strlen(t), 81. * param1 / 90, 480,white);
	t = "chart";
	DrawText(t, strlen(t), 81. * param1 / 90, 460,white);
	//DrawText(buff, strlen(buff), 51. * param1 / 90, 200,white);
	//glutSwapBuffers();
}

void drawVenDiagram()
{
	glBegin(GL_POLYGON);
	for (int i = -120; i <= 120; i++)
	{
		glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 + cos(0) / 10), (sin(i*3.14 / 180) / 5), 0);
	}
	for (int i = 60; i >= -60; i--)
	{
		glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 + cos((360 / 2)*3.14 / 180) / 10), (sin(i*3.14 / 180) / 5), 0);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = 240; i >= 120; i--)
	{
		glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 + cos(0) / 10), (sin(i*3.14 / 180) / 5), 0);
	}
	for (int i = 60; i <= 300; i++)
	{
		glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 + cos((360 / 2)*3.14 / 180) / 10), (sin(i*3.14 / 180) / 5), 0);
	}
	glEnd();
	glBegin(GL_POLYGON);
	for (int i = -60; i <= 60; i++)
	{
		glColor3f(1, 0.95, 0); glVertex3f((cos(i*3.14 / 180) / 5 + cos((360 / 2)*3.14 / 180) / 10), (sin(i*3.14 / 180) / 5), 0);
	}
	for (int i = 120; i <= 240; i++)
	{
		glColor3f(1, 0.95, 0); glVertex3f((cos(i*3.14 / 180) / 5 + cos(0) / 10), (sin(i*3.14 / 180) / 5), 0);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (int i = -120; i <= 120; i++)
	{
		glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 + cos(0) / 10), (sin(i*3.14 / 180) / 5), 0);
	}
	for (int i = 60; i >= -60; i--)
	{
		glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 + cos((360 / 2)*3.14 / 180) / 10), (sin(i*3.14 / 180) / 5), 0);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (int i = 240; i >= 120; i--)
	{
		glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 + cos(0) / 10), (sin(i*3.14 / 180) / 5), 0);
	}
	for (int i = 60; i <= 300; i++)
	{
		glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 + cos((360 / 2)*3.14 / 180) / 10), (sin(i*3.14 / 180) / 5), 0);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	for (int i = -60; i <= 60; i++)
	{
		glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 + cos((360 / 2)*3.14 / 180) / 10), (sin(i*3.14 / 180) / 5), 0);
	}
	for (int i = 120; i <= 240; i++)
	{
		glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 + cos(0) / 10), (sin(i*3.14 / 180) / 5), 0);
	}

	glEnd();
	//glutSwapBuffers();
}