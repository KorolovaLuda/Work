#include"Menu.h"
void drawmenu()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.51, 0.77); glVertex3f(-1, 1, 0);
	glColor3f(0.0, 0.51, 0.77); glVertex3f(1, 1, 0);
	glColor3f(0.45, 0.89, 0.94); glVertex3f(1, -1, 0);
	glColor3f(0.45, 0.89, 0.94); glVertex3f(-1, -1, 0);
	glEnd();
	for (int i = 0; i < 9; i++)
	{
		glBegin(GL_POLYGON);
		glColor3f(0, 0.47, 0.68); glVertex3f(-1 + i*2. / 9, 1, 0);
		glColor3f(0.04, 0.19, 0.39); glVertex3f(-7. / 9 + i*2. / 9, 1, 0);
		glColor3f(0.04, 0.19, 0.39); glVertex3f(-7. / 9 + i*2. / 9, 2. / 3, 0);
		glColor3f(0.04, 0.19, 0.39); glVertex3f(-1 + i*2. / 9, 2. / 3, 0);
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
	DrawText(t, strlen(t), param1 / 90, 480, white);
	t = "graph";
	DrawText(t, strlen(t), param1 / 90, 450, white);
	t = "stakes";
	DrawText(t, strlen(t), 11. * param1 / 90, 480, white);
	t = "regions";
	DrawText(t, strlen(t), 21. * param1 / 90, 480, white);
	t = "points";
	DrawText(t, strlen(t), 31. * param1 / 90, 480, white);
	t = "pie";
	DrawText(t, strlen(t), 41. * param1 / 90, 480, white);
	t = "chart";
	DrawText(t, strlen(t), 41. * param1 / 90, 460, white);
	t = "radial";
	DrawText(t, strlen(t), 51. * param1 / 90, 480, white);
	t = "diagram";
	DrawText(t, strlen(t), 51. * param1 / 90, 460, white);
	t = "Venn";
	DrawText(t, strlen(t), 61. * param1 / 90, 480, white);
	t = "diagram";
	DrawText(t, strlen(t), 61. * param1 / 90, 460, white);
	t = "vector";
	DrawText(t, strlen(t), 71. * param1 / 90, 480, white);
	t = "diagram";
	DrawText(t, strlen(t), 71. * param1 / 90, 460, white);
	t = "stock";
	DrawText(t, strlen(t), 81. * param1 / 90, 480, white);
	t = "chart";
	DrawText(t, strlen(t), 81. * param1 / 90, 460, white);
}

void renderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawmenu();
	if (input_mode == 1)
	{
		//	DrawText(buff, strlen(buff), param1 * 4.1 / 9., param2*6.67 / 9, black);
		Drawinput1();
		if (diag_mode == 1)
		{
			DrawText("Input funstion:", 15, param1 * 2.55 / 9., param2*6.7 / 9, black);
			drow_button1();
		}
		if (diag_mode == 7)
		{
			drawVenDiagram();
			DrawText("Input set:", 10, param1 * 3 / 9., param2*6.7 / 9, black);
			drow_button1();
		}
		if (diag_mode == 8)
		{
			DrawText("Input vector:", 13, param1 * 2.73 / 9., param2*6.7 / 9, black);
			drow_button1();
		}
	}
	if (input_mode == 2)
	{
		//	DrawText(buff, strlen(buff), param1 * 13. / 18., param2*6.67 / 9, black);
		Draw_num();
		drow_button2();
		Drawinput2(atoi(buff));
	}
	if (input_mode == 3)
	{
		//	DrawText(buff, strlen(buff), param1 * 13. / 18., param2*6.67 / 9, black);
		Draw_num();
		drow_button2();
		if (strcmp(buff, "") != 0)
		Drawinput3(atoi(buff));
	}
	if (input_mode == 4)
	{
		//	DrawText(buff, strlen(buff), param1 * 13. / 18., param2*6.67 / 9, black);
		Draw_num();
		drow_button2();
		if(strcmp(buff,"")!=0)
		Drawinput4(atoi(buff));
	}
	glutSwapBuffers();
}

void drow_button1()
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.28, 0.48); glVertex3f(6. / 9, 4. / 9, 0);
	glColor3f(0.0, 0.53, 0.86); glVertex3f(6. / 9, 5. / 9, 0);
	glColor3f(0.0, 0.28, 0.48); glVertex3f(8. / 9, 5. / 9, 0);
	glColor3f(0.0, 0.28, 0.48); glVertex3f(8. / 9, 4. / 9, 0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0); glVertex3f(6. / 9, 4. / 9, 0);
	glColor3f(0, 0, 0); glVertex3f(6. / 9, 5. / 9, 0);
	glColor3f(0, 0, 0); glVertex3f(8. / 9, 5. / 9, 0);
	glColor3f(0, 0, 0); glVertex3f(8. / 9, 4. / 9, 0);
	glEnd();
	DrawText("Build", 5, param1 * 15.55 / 18., param2*6.67 / 9, white);
}

void drow_button2()
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.28, 0.48); glVertex3f(6. / 9, 4. / 9, 0);
	glColor3f(0.0, 0.53, 0.86); glVertex3f(6. / 9, 5. / 9, 0);
	glColor3f(0.0, 0.28, 0.48); glVertex3f(8. / 9, 5. / 9, 0);
	glColor3f(0.0, 0.28, 0.48); glVertex3f(8. / 9, 4. / 9, 0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0); glVertex3f(6. / 9, 4. / 9, 0);
	glColor3f(0, 0, 0); glVertex3f(6. / 9, 5. / 9, 0);
	glColor3f(0, 0, 0); glVertex3f(8. / 9, 5. / 9, 0);
	glColor3f(0, 0, 0); glVertex3f(8. / 9, 4. / 9, 0);
	glEnd();
	DrawText("Confirm", 7, param1 * 15.35 / 18., param2*6.67 / 9, white);
}
void drow_button3()
{
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.28, 0.48); glVertex3f(6. / 9, 4. / 9, 0);
	glColor3f(0.0, 0.53, 0.86); glVertex3f(6. / 9, 5. / 9, 0);
	glColor3f(0.0, 0.28, 0.48); glVertex3f(8. / 9, 5. / 9, 0);
	glColor3f(0.0, 0.28, 0.48); glVertex3f(8. / 9, 4. / 9, 0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0); glVertex3f(6. / 9, 4. / 9, 0);
	glColor3f(0, 0, 0); glVertex3f(6. / 9, 5. / 9, 0);
	glColor3f(0, 0, 0); glVertex3f(8. / 9, 5. / 9, 0);
	glColor3f(0, 0, 0); glVertex3f(8. / 9, 4. / 9, 0);
	glEnd();
	DrawText("Confirm", 5, param1 * 15.35 / 18., param2*6.67 / 9, white);
}

