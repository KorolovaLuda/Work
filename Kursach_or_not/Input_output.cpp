#include"Input_output.h"

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
	if (num > 0 && num <= 11 && confirm == true)
	{
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1); glVertex3f(3.25 / 9, 3.7 / 9 - num*1. / 9, 0);
		glColor3f(1, 1, 1); glVertex3f(3.25 / 9, 3.7 / 9, 0);
		glColor3f(1, 1, 1); glVertex3f(8.65 / 9, 3.7 / 9, 0);
		glColor3f(1, 1, 1); glVertex3f(8.65 / 9, 3.7 / 9 - num*1. / 9, 0);
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
			glColor3f(0, 0, 0); glVertex3f(3.25 / 9, 3.7 / 9 - (i + 1)*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(3.25 / 9, 3.7 / 9 - i*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(4.6 / 9, 3.7 / 9 - i*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(4.6 / 9, 3.7 / 9 - (i + 1)*1. / 9, 0);
			glEnd();

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

			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0); glVertex3f(7.3 / 9, 3.7 / 9 - (i + 1)*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(7.3 / 9, 3.7 / 9 - i*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(8.65 / 9, 3.7 / 9 - i*1. / 9, 0);
			glColor3f(0, 0, 0); glVertex3f(8.65 / 9, 3.7 / 9 - (i + 1)*1. / 9, 0);
			glEnd();
		}
		//confirm = false;
	}
}

void Draw_table2()
{
	if(str>0 && str<12)
	for (int i = 0; i < str; i++)
		DrawText(table[i][0], strlen(table[i][0]), param1*14.325 / 18, param2*12.05 / 18-i*param2*1./18, black);
}
void Draw_table3()
{
	if (str > 0&&str<12)
	{
		for (int i = 0; i < str; i++)
			DrawText(table[i][0], strlen(table[i][0]), param1*13.65 / 18, param2*12.05 / 18 - i*param2*1. / 18, black);
		for (int i = 0; i < str; i++)
			DrawText(table[i][1], strlen(table[i][1]), param1*15.0 / 18, param2*12.05 / 18 - i*param2*1. / 18, black);
	}
}
void Draw_table4()
{
	if (str > 0 && str<12)
	{
		for (int i = 0; i < str; i++)
			DrawText(table[i][0], strlen(table[i][0]), param1*12.3 / 18, param2*12.05 / 18 - i*param2*1. / 18, black);
		for (int i = 0; i < str; i++)
			DrawText(table[i][1], strlen(table[i][1]), param1*13.65 / 18, param2*12.05 / 18 - i*param2*1. / 18, black);
		for (int i = 0; i < str; i++)
			DrawText(table[i][2], strlen(table[i][2]), param1*15.0 / 18, param2*12.05 / 18 - i*param2*1. / 18, black);
		for (int i = 0; i < str; i++)
			DrawText(table[i][3], strlen(table[i][3]), param1*16.35 / 18, param2*12.05 / 18 - i*param2*1. / 18, black);
	}
}
