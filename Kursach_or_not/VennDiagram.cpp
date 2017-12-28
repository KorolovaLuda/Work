#include"VennDiagram.h"
#include<GL\glew.h>
#include<GL\freeglut.h>
#include<iostream>

/*void drawVenDiagram()
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
}*/