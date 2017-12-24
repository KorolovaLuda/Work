#include"Input_output.h"

void DrawText(const char *text, int length, int x, int y,float*color)
{
	glMatrixMode(GL_PROJECTION);
	double *matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glColor3f(color[0], color[1], color[2]);//����� ����� ������(�� �����������, ��� ���� ������ ����� ��������)
	glOrtho(0, 900, 0, 500, -5, 5);//����� ������� ���������(�� �� ��������� ����, �����, ������ ����� ��� ������)
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glLoadIdentity();//
	glRasterPos2i(x, y);//��������� ���������� ��������� ������
	for (int i = 0; i<length; i++)//���� ��������� ������
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
}
void Draw_num()
{
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1); glVertex3f(3.9 / 9, 4. / 9, 0);
	glColor3f(1, 1, 1); glVertex3f(3.9 / 9, 5. / 9, 0);
	glColor3f(1, 1, 1); glVertex3f(5.9 / 9, 5. / 9, 0);
	glColor3f(1, 1, 1); glVertex3f(5.9 / 9, 4. / 9, 0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0); glVertex3f(3.9 / 9, 4. / 9, 0);
	glColor3f(0, 0, 0); glVertex3f(3.9 / 9, 5. / 9, 0);
	glColor3f(0, 0, 0); glVertex3f(5.9 / 9, 5. / 9, 0);
	glColor3f(0, 0, 0); glVertex3f(5.9 / 9, 4. / 9, 0);
	glEnd();
	DrawText("Input cuantity of strings:", 27, param1 * 4.05 / 9., param2*6.7 / 9, black);
}
void Drawinput2(int num)
{
	if (num > 0 && num<=11&&confirm==true)
	{
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1); glVertex3f(5.275 / 9, 3.7 / 9 - num*1. / 9, 0);
		glColor3f(1, 1, 1); glVertex3f(5.275 / 9, 3.7 / 9, 0);
		glColor3f(1, 1, 1); glVertex3f(6.625 / 9, 3.7 / 9, 0);
		glColor3f(1, 1, 1); glVertex3f(6.625 / 9, 3.7 / 9 - num*1. / 9, 0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0, 0, 0); glVertex3f(5.275 / 9, 3.7 / 9 - num*1. / 9, 0);
		glColor3f(0, 0, 0); glVertex3f(5.275 / 9, 3.7 / 9, 0);
		glColor3f(0, 0, 0); glVertex3f(6.625 / 9, 3.7 / 9, 0);
		glColor3f(0, 0, 0); glVertex3f(6.625 / 9, 3.7 / 9 - num*1. / 9, 0);
		glEnd();
		DrawText("Input cuantity of strings:", 27, param1 * 4.05 / 9., param2*6.7 / 9, black);
		for (int i = 0; i < num; i++)
		{
			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0); glVertex3f(5.275 / 9, 3.7 / 9 - (i + 1)*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(5.275 / 9, 3.7 / 9 - i*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(6.625 / 9, 3.7 / 9 - i*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(6.625 / 9, 3.7 / 9 - (i + 1)*1. / 9, 0);
			glEnd();
		}
		//confirm = false;
	}
}
void Drawinput3(int num)
{
	if (num > 0&&num<=11&&confirm==true)
	{
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1); glVertex3f(4.6 / 9, 3.7 / 9 - num*1. / 9, 0);
		glColor3f(1, 1, 1); glVertex3f(4.6 / 9, 3.7 / 9, 0);
		glColor3f(1, 1, 1); glVertex3f(7.3 / 9, 3.7 / 9, 0);
		glColor3f(1, 1, 1); glVertex3f(7.3 / 9, 3.7 / 9 - num*1. / 9, 0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0, 0, 0); glVertex3f(4.6 / 9, 3.7 / 9 - num*1. / 9, 0);
		glColor3f(0, 0, 0); glVertex3f(4.6 / 9, 3.7 / 9, 0);
		glColor3f(0, 0, 0); glVertex3f(7.3 / 9, 3.7 / 9, 0);
		glColor3f(0, 0, 0); glVertex3f(7.3 / 9, 3.7 / 9 - num*1. / 9, 0);
		glEnd();
		DrawText("Input cuantity of strings:", 27, param1 * 4.05 / 9., param2*6.7 / 9, black);
		for (int i = 0; i < num; i++)
		{
			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0); glVertex3f(4.6 / 9, 3.7 / 9 - (i + 1)*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(4.6 / 9, 3.7 / 9 - i*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(5.95 / 9, 3.7 / 9 - i*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(5.95 / 9, 3.7 / 9 - (i + 1)*1. / 9, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0); glVertex3f(5.95 / 9, 3.7 / 9 - (i + 1)*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(5.95 / 9, 3.7 / 9 - i*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(7.3 / 9, 3.7 / 9 - i*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(7.3 / 9, 3.7 / 9 - (i + 1)*1. / 9, 0);
			glEnd();
		}
		//confirm = false;
	}
}
void Drawinput4(int num)
{
	if (num > 0 && num<=11&&confirm==true)
	{
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1); glVertex3f(3.9 / 9, 3.7 / 9 - num*1. / 9, 0);
		glColor3f(1, 1, 1); glVertex3f(3.9 / 9, 3.7 / 9, 0);
		glColor3f(1, 1, 1); glVertex3f(8. / 9, 3.7 / 9, 0);
		glColor3f(1, 1, 1); glVertex3f(8. / 9, 3.7 / 9 - num*1. / 9, 0);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(0, 0, 0); glVertex3f(3.9 / 9, 3.7 / 9 - num*1. / 9, 0);
		glColor3f(0, 0, 0); glVertex3f(3.9 / 9, 3.7 / 9, 0);
		glColor3f(0, 0, 0); glVertex3f(8. / 9, 3.7 / 9, 0);
		glColor3f(0, 0, 0); glVertex3f(8. / 9, 3.7 / 9 - num*1. / 9, 0);
		glEnd();
		DrawText("Input cuantity of strings:", 27, param1 * 4.05 / 9., param2*6.7 / 9, black);
		for (int i = 0; i < num; i++)
		{
			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0); glVertex3f(3.9 / 9, 3.7 / 9 - (i+1)*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(3.9 / 9, 3.7 / 9 - i*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(5.25 / 9, 3.7 / 9 - i*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(5.25 / 9, 3.7 / 9 -(i + 1)*1. / 9, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0); glVertex3f(5.25 / 9, 3.7 / 9 - (i + 1)*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(5.25 / 9, 3.7 / 9 - i*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(6.65/9, 3.7 / 9 - i*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(6.65/9, 3.7 / 9 - (i + 1)*1. / 9, 0);
			glEnd();
			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0); glVertex3f(6.65 / 9, 3.7 / 9 - (i + 1)*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(6.65 / 9, 3.7 / 9 - i*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(8. / 9, 3.7 / 9 - i*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(8. / 9, 3.7 / 9 - (i + 1)*1. / 9, 0);
			glEnd();
		}
	//confirm = false;
	}
	
}

