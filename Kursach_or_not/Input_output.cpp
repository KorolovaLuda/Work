#include"Input_output.h"

void input1(unsigned char key, int x, int y)
{
	int len;
	char k = key;
	if (k == 8)
	{
	len = strlen(buff);
	buff+= len - 1;
	strcpy(buff, "");
	buff -= len - 1;
	}
	else
	{
		char*test = &k;
		if (strlen(buff) < 98)
			strcat(buff, test);
		cout << buff << endl;
	}
	DrawText(buff, strlen(buff), param1 * 4.1 / 9., param2*6.67 / 9, black);
	glutSwapBuffers();
}

void DrawText(const char *text, int length, int x, int y,float*color)
{
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glColor3f(color[0], color[1], color[2]);//Выбор цвета текста(не обязательно, без этой строки будет работать)
	glOrtho(0, 900, 0, 500, -5, 5);//Выбор системы координат(ты же создавала окна, думаю, знаешь зачем эта строка)
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();//
	glRasterPos2i(x, y);//Установка начального положения текста
	for (int i = 0; i<length; i++)//цикл вырисовки текста
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, (int)text[i]);
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}

void Drawinput1()
{
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1); glVertex3f(-1./9, 4./9, 0);
	glColor3f(1, 1, 1); glVertex3f(-1./9, 5./9, 0);
	glColor3f(1, 1, 1); glVertex3f(5./9, 5./9, 0);
	glColor3f(1, 1, 1); glVertex3f(5./9, 4./9, 0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0); glVertex3f(-1. / 9, 4. / 9, 0);
	glColor3f(0, 0, 0); glVertex3f(-1. / 9, 5. / 9, 0);
	glColor3f(0, 0, 0); glVertex3f(5. / 9, 5. / 9, 0);
	glColor3f(0, 0, 0); glVertex3f(5. / 9, 4. / 9, 0);
	glEnd();
	//glutSwapBuffers();
}
void Drawinput2()
{

}
void Drawinput3()
{

}
void Drawinput4()
{

}