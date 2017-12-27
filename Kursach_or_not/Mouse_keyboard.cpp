#include"Mouse_keyboard.h"

void test(int a, int b, int c, int d) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	drawmenu();
	index[0] = -1;
	index[1] = -1;
	if (a == GLUT_LEFT_BUTTON)
	{
		printable = false;
		if (c > 0 && c < param1 / 9.&&d>0 && d < param2 / 6.)
		{
			//график функции
			input_mode = 1; //ввод строки
			diag_mode = 1;
			strcpy(buff, "");
			Drawinput1();
			drow_button1();
			DrawText("Input function:", 15, param1 * 2.55 / 9., param2*6.7 / 9, black);
			clear_table();
		}
		if (c > param1 / 9. && c < param1 * 2 / 9.&&d>0 && d < param2 / 6.)
		{
			//столбики
			input_mode = 3; //ввод 2 столбцов
			diag_mode = 2;
			strcpy(buff, "");
			DrawText("Input cuantity of strings:", 27, param1 * 5.1 / 9., param2*6.7 / 9, black);
			Draw_num();
			void drow_button2();
			clear_table();
		}
		if (c > param1 * 2 / 9. && c < param1 * 3 / 9.&&d>0 && d < param2 / 6.)
		{
			//области
			input_mode = 3; //ввод 2 столбцов
			diag_mode = 3;
			strcpy(buff, "");
			DrawText("Input cuantity of strings:", 27, param1 * 5.1 / 9., param2*6.7 / 9, black);
			Draw_num();
			void drow_button2();
			clear_table();

		}
		if (c > param1 * 3 / 9. && c < param1 * 4 / 9.&&d>0 && d < param2 / 6.)
		{
			//точки
			input_mode = 3; //ввод 2 столбцов
			diag_mode = 4;
			strcpy(buff, "");
			DrawText("Input cuantity of strings:", 27, param1 * 5.1 / 9., param2*6.7 / 9, black);
			Draw_num();
			void drow_button2();
			clear_table();
		}
		if (c > param1 * 4 / 9. && c < param1 * 5 / 9.&&d>0 && d < param2 / 6.)
		{
			//круговая диаграма
			input_mode = 2; //ввод 1 столбца
			diag_mode = 5;
			strcpy(buff, "");
			DrawText("Input cuantity of strings:", 27, param1 * 5.1 / 9., param2*6.7 / 9, black);
			Draw_num();
			void drow_button2();
			clear_table();
		}
		if (c > param1 * 5 / 9. && c < param1 * 6 / 9.&&d>0 && d < param2 / 6.)
		{
			//радиальная диаграма
			input_mode = 3; //ввод 2 столбцов
			strcpy(buff, "");
			diag_mode = 6;
			DrawText("Input cuantity of strings:", 27, param1 * 5.1 / 9., param2*6.7 / 9, black);
			Draw_num();
			void drow_button2();
			clear_table();
		}
		if (c > param1 * 6 / 9. && c < param1 * 7 / 9.&&d>0 && d < param2 / 6.)
		{
			//диаграма Вена
			input_mode = 1; //ввод строки
			diag_mode = 7;
			strcpy(buff, "");
			drawVenDiagram();
			Drawinput1();
			drow_button1();
			DrawText("Input set:", 10, param1 * 3 / 9., param2*6.7 / 9, black);
			clear_table();
		}
		if (c > param1 * 7 / 9. && c < param1 * 8 / 9.&&d>0 && d < param2 / 6.)
		{
			//векторная диаграма
			input_mode = 1; //ввод строки
			diag_mode = 8;
			strcpy(buff, "");
			drow_button1();
			DrawText("Input vector:", 13, param1 * 2.73 / 9., param2*6.7 / 9, black);
			Drawinput1();
			clear_table();
		}
		if (c > param1 * 8 / 9. && c < param1 &&d>0 && d < param2 / 6.)
		{
			//биржевые диаграмы
			input_mode = 4; //ввод 3 столбцов
			diag_mode = 9;
			strcpy(buff, "");
			Draw_num();
			void drow_button2();
			DrawText("Input cuantity of strings:", 27, param1 * 5.1 / 9., param2*6.7 / 9, black);
			clear_table();
		}
		if (diag_mode == 1)
		{
			if (c > param1 *4. / 9 && c<param1 *7. / 9 && d>param2 *2. / 9 && d < param2 *5. / 18)
				printable = true;
			if (c > param1 *15. / 18 && c<param1 *17. / 18 && d>param2 *2. / 9 && d < param2 *5. / 18)
				build = true;
		}
		if (diag_mode == 2)
		{
			if (c > param1 *12.9 / 18 && c<param1 *14.9 / 18 && d>param2 *2. / 9 && d < param2 *5. / 18)
				printable = true;
			if (c > param1 *15. / 18 && c<param1 *17. / 18 && d>param2 *2. / 9 && d < param2 *5. / 18)
			{
				confirm = true;
				Drawinput3(atoi(buff));
				str = atoi(buff);
			}
			if (c > param1*13.6 / 18 && c<param1*14.95 / 18)
				index[1] = 0;
			if (d<param2*6.3 / 18 && d>param2*5.3 / 18 && str >= 1 && str <= 11)
				index[0] = 0;
			if (d<param2*7.3 / 18 && d>param2*6.3 / 18 && str >= 2 && str <= 11)
				index[0] = 1;
			if (d<param2*8.3 / 18 && d>param2*7.3 / 18 && str >= 3 && str <= 11)
				index[0] = 2;
			if (d<param2*9.3 / 18 && d>param2*8.3 / 18 && str >= 4 && str <= 11)
				index[0] = 3;
			if (d<param2*10.3 / 18 && d>param2*9.3 / 18 && str >= 5 && str <= 11)
				index[0] = 4;
			if (d<param2*11.3 / 18 && d>param2*10.3 / 18 && str >= 6 && str <= 11)
				index[0] = 5;
			if (d<param2*12.3 / 18 && d>param2*11.3 / 18 && str >= 7 && str <= 11)
				index[0] = 6;
			if (d<param2*13.3 / 18 && d>param2*12.3 / 18 && str >= 8 && str <= 11)
				index[0] = 7;
			if (d<param2*14.3 / 18 && d>param2*13.3 / 18 && str >= 9 && str <= 11)
				index[0] = 8;
			if (d<param2*15.3 / 18 && d>param2*14.3 / 18 && str >= 10 && str <= 11)
				index[0] = 9;
			if (d<param2*16.3 / 18 && d>param2*15.3 / 18 && str == 11)
				index[0] = 10;
			if (c > param1*14.95 / 18 && c<param1*16.3 / 18)
				index[1] = 1;
			Draw_table3();
			//кнопка построить
			if (c > param1 *5.25 / 18 && c<param1 *7.25 / 18 && d>param2 *2. / 9 && d < param2 *5. / 18)
			{
				///
			}
		}
		if (diag_mode == 3)
		{
			if (c > param1 *12.9 / 18 && c<param1 *14.9 / 18 && d>param2 *2. / 9 && d < param2 *5. / 18)
				printable = true;
			if (c > param1 *15. / 18 && c<param1 *17. / 18 && d>param2 *2. / 9 && d < param2 *5. / 18)
			{
				confirm = true;
				Drawinput3(atoi(buff));
				str = atoi(buff);
			}
			if (c > param1*13.6 / 18 && c<param1*14.95 / 18)
				index[1] = 0;
			if (d<param2*6.3 / 18 && d>param2*5.3 / 18 && str >= 1 && str <= 11)
				index[0] = 0;
			if (d<param2*7.3 / 18 && d>param2*6.3 / 18 && str >= 2 && str <= 11)
				index[0] = 1;
			if (d<param2*8.3 / 18 && d>param2*7.3 / 18 && str >= 3 && str <= 11)
				index[0] = 2;
			if (d<param2*9.3 / 18 && d>param2*8.3 / 18 && str >= 4 && str <= 11)
				index[0] = 3;
			if (d<param2*10.3 / 18 && d>param2*9.3 / 18 && str >= 5 && str <= 11)
				index[0] = 4;
			if (d<param2*11.3 / 18 && d>param2*10.3 / 18 && str >= 6 && str <= 11)
				index[0] = 5;
			if (d<param2*12.3 / 18 && d>param2*11.3 / 18 && str >= 7 && str <= 11)
				index[0] = 6;
			if (d<param2*13.3 / 18 && d>param2*12.3 / 18 && str >= 8 && str <= 11)
				index[0] = 7;
			if (d<param2*14.3 / 18 && d>param2*13.3 / 18 && str >= 9 && str <= 11)
				index[0] = 8;
			if (d<param2*15.3 / 18 && d>param2*14.3 / 18 && str >= 10 && str <= 11)
				index[0] = 9;
			if (d<param2*16.3 / 18 && d>param2*15.3 / 18 && str == 11)
				index[0] = 10;
			if (c > param1*14.95 / 18 && c<param1*16.3 / 18)
					index[1] = 1;
			Draw_table3();
			//кнопка построить
			if (c > param1 *5.25 / 18 && c<param1 *7.25 / 18 && d>param2 *2. / 9 && d < param2 *5. / 18)
			{
				///
			}
		}
		if (diag_mode == 4)
		{
			if (c > param1 *12.9 / 18 && c<param1 *14.9 / 18 && d>param2 *2. / 9 && d < param2 *5. / 18)
				printable = true;
			if (c > param1 *15. / 18 && c<param1 *17. / 18 && d>param2 *2. / 9 && d < param2 *5. / 18)
			{
				confirm = true;
				Drawinput3(atoi(buff));
				str = atoi(buff);
			}
			if (c > param1*13.6/18&&c<param1*14.95/18)
					index[1] = 0;
			if (d<param2*6.3 / 18 && d>param2*5.3 / 18 && str >= 1 && str <= 11)
				index[0] = 0;
			if (d<param2*7.3 / 18 && d>param2*6.3 / 18 && str >= 2 && str <= 11)
				index[0] = 1;
			if (d<param2*8.3 / 18 && d>param2*7.3 / 18 && str >= 3 && str <= 11)
				index[0] = 2;
			if (d<param2*9.3 / 18 && d>param2*8.3 / 18 && str >= 4 && str <= 11)
				index[0] = 3;
			if (d<param2*10.3 / 18 && d>param2*9.3 / 18 && str >= 5 && str <= 11)
				index[0] = 4;
			if (d<param2*11.3 / 18 && d>param2*10.3 / 18 && str >= 6 && str <= 11)
				index[0] = 5;
			if (d<param2*12.3 / 18 && d>param2*11.3 / 18 && str >= 7 && str <= 11)
				index[0] = 6;
			if (d<param2*13.3 / 18 && d>param2*12.3 / 18 && str >= 8 && str <= 11)
				index[0] = 7;
			if (d<param2*14.3 / 18 && d>param2*13.3 / 18 && str >= 9 && str <= 11)
				index[0] = 8;
			if (d<param2*15.3 / 18 && d>param2*14.3 / 18 && str >= 10 && str <= 11)
				index[0] = 9;
			if (d<param2*16.3 / 18 && d>param2*15.3 / 18 && str == 11)
				index[0] = 10;
			if (c > param1*14.95 / 18 && c<param1*16.3 / 18)
					index[1] = 1;
			Draw_table3();
			//кнопка построить
			if (c > param1 *5.25 / 18 && c<param1 *7.25 / 18 && d>param2 *2. / 9 && d < param2 *5. / 18)
			{
				///
			}
		}
		if (diag_mode == 5)
		{
			if (c > param1 *12.9 / 18 && c<param1 *14.9 / 18 && d>param2 *2. / 9 && d < param2 *5. / 18)
				printable = true;
			if (c > param1 *15. / 18 && c<param1 *17. / 18 && d>param2 *2. / 9 && d < param2 *5. / 18)
			{
				confirm = true;
				Drawinput2(atoi(buff));
				str = atoi(buff);
			}
			if (c > param1*14.275 / 18 && c<param1*15.625 / 18)
				index[1] = 0;
			if (c > param1*12.9 / 18 && c<param1*14.25 / 18)
				index[1] = 0;
			if (d<param2*6.3 / 18 && d>param2*5.3 / 18 && str >= 1 && str <= 11)
				index[0] = 0;
			if (d<param2*7.3 / 18 && d>param2*6.3 / 18 && str >= 2 && str <= 11)
				index[0] = 1;
			if (d<param2*8.3 / 18 && d>param2*7.3 / 18 && str >= 3 && str <= 11)
				index[0] = 2;
			if (d<param2*9.3 / 18 && d>param2*8.3 / 18 && str >= 4 && str <= 11)
				index[0] = 3;
			if (d<param2*10.3 / 18 && d>param2*9.3 / 18 && str >= 5 && str <= 11)
				index[0] = 4;
			if (d<param2*11.3 / 18 && d>param2*10.3 / 18 && str >= 6 && str <= 11)
				index[0] = 5;
			if (d<param2*12.3 / 18 && d>param2*11.3 / 18 && str >= 7 && str <= 11)
				index[0] = 6;
			if (d<param2*13.3 / 18 && d>param2*12.3 / 18 && str >= 8 && str <= 11)
				index[0] = 7;
			if (d<param2*14.3 / 18 && d>param2*13.3 / 18 && str >= 9 && str <= 11)
				index[0] = 8;
			if (d<param2*15.3 / 18 && d>param2*14.3 / 18 && str >= 10 && str <= 11)
				index[0] = 9;
			if (d<param2*16.3 / 18 && d>param2*15.3 / 18 && str == 11)
				index[0] = 10;
			Draw_table2();
			//кнопка построить
			if (c > param1 *5.25 / 18 && c<param1 *7.25 / 18 && d>param2 *2. / 9 && d < param2 *5. / 18)
			{
				start = true;
				build = true;
			}
		}
		if (diag_mode == 6)
		{
			if (c > param1 *12.9 / 18 && c<param1 *14.9 / 18 && d>param2 *2. / 9 && d < param2 *5. / 18)
				printable = true;
			if (c > param1 *15. / 18 && c<param1 *17. / 18 && d>param2 *2. / 9 && d < param2 *5. / 18)
			{
				confirm = true;
				Drawinput3(atoi(buff));
				str = atoi(buff);
			}
			if (c > param1*13.6/18&&c<param1*14.95/18)
					index[1] = 0;
			if (d<param2*6.3 / 18 && d>param2*5.3 / 18 && str >= 1 && str <= 11)
				index[0] = 0;
			if (d<param2*7.3 / 18 && d>param2*6.3 / 18 && str >= 2 && str <= 11)
				index[0] = 1;
			if (d<param2*8.3 / 18 && d>param2*7.3 / 18 && str >= 3 && str <= 11)
				index[0] = 2;
			if (d<param2*9.3 / 18 && d>param2*8.3 / 18 && str >= 4 && str <= 11)
				index[0] = 3;
			if (d<param2*10.3 / 18 && d>param2*9.3 / 18 && str >= 5 && str <= 11)
				index[0] = 4;
			if (d<param2*11.3 / 18 && d>param2*10.3 / 18 && str >= 6 && str <= 11)
				index[0] = 5;
			if (d<param2*12.3 / 18 && d>param2*11.3 / 18 && str >= 7 && str <= 11)
				index[0] = 6;
			if (d<param2*13.3 / 18 && d>param2*12.3 / 18 && str >= 8 && str <= 11)
				index[0] = 7;
			if (d<param2*14.3 / 18 && d>param2*13.3 / 18 && str >= 9 && str <= 11)
				index[0] = 8;
			if (d<param2*15.3 / 18 && d>param2*14.3 / 18 && str >= 10 && str <= 11)
				index[0] = 9;
			if (d<param2*16.3 / 18 && d>param2*15.3 / 18 && str == 11)
				index[0] = 10;
			if (c > param1*14.95 / 18 && c<param1*16.3 / 18)
					index[1] = 1;
			Draw_table3();
			//кнопка построить
			if (c > param1 *5.25 / 18 && c<param1 *7.25 / 18 && d>param2 *2. / 9 && d < param2 *5. / 18)
			{
				///
			}
		}
		if (diag_mode == 7)
		{
			if (c > param1 *4. / 9 && c<param1 *7. / 9 && d>param2 *2. / 9 && d < param2 *5. / 18)
				printable = true;
		}
		if (diag_mode == 8)
		{
			if (c > param1 *4. / 9 && c<param1 *7. / 9 && d>param2 *2. / 9 && d < param2 *5. / 18)
				printable = true;
		}
		if (diag_mode == 9)
		{
			if (c > param1 *12.9 / 18 && c<param1 *14.9 / 18 && d>param2 *2. / 9 && d < param2 *5. / 18)
				printable = true;
			if (c > param1 *15. / 18 && c<param1 *17. / 18 && d>param2 *2. / 9 && d < param2 *5. / 18)
			{
				confirm = true;
				Drawinput4(atoi(buff));
				str = atoi(buff);
	
			}

			if (c > param1*12.9 / 18 && c<param1*14.25 / 18)
				index[1] = 0;
			if (d<param2*6.3 / 18 && d>param2*5.3 / 18 && str >= 1&&str<=11)
				index[0] = 0;
			if (d<param2*7.3 / 18 && d>param2*6.3 / 18 && str >= 2 && str <= 11)
				index[0] = 1;
			if (d<param2*8.3 / 18 && d>param2*7.3 / 18 && str >= 3 && str <= 11)
				index[0] = 2;
			if (d<param2*9.3 / 18 && d>param2*8.3 / 18 && str >= 4 && str <= 11)
				index[0] = 3;
			if (d<param2*10.3 / 18 && d>param2*9.3 / 18 && str >= 5 && str <= 11)
				index[0] = 4;
			if (d<param2*11.3 / 18 && d>param2*10.3 / 18 && str >= 6 && str <= 11)
				index[0] = 5;
			if (d<param2*12.3 / 18 && d>param2*11.3 / 18 && str >= 7 && str <= 11)
				index[0] = 6;
			if (d<param2*13.3 / 18 && d>param2*12.3 / 18 && str >= 8 && str <= 11)
				index[0] = 7;
			if (d<param2*14.3 / 18 && d>param2*13.3 / 18 && str >= 9 && str <= 11)
				index[0] = 8;
			if (d<param2*15.3 / 18 && d>param2*14.3 / 18 && str >= 10 && str <= 11)
				index[0] = 9;
			if (d<param2*16.3 / 18 && d>param2*15.3 / 18 && str == 11)
				index[0] = 10;
			if (c > param1*14.25 / 18 && c<param1*15.65 / 18)
					index[1] = 1;
			if (c > param1*15.65 / 18 && c<param1*17. / 18)
					index[1] = 2;
			Draw_table4();
			//кнопка построить
			if (c > param1 *5.25 / 18 && c<param1 *7.25 / 18 && d>param2 *2. / 9 && d < param2 *5. / 18)
			{
				///
			}
		}
	}
	renderScene();
	if (input_mode == 1)
	{
		DrawText(buff, strlen(buff), param1 * 4.1 / 9., param2*6.67 / 9, black);
	}
	if (input_mode == 2)
	{
		DrawText(buff, strlen(buff), param1 * 13. / 18., param2*6.67 / 9, black);
		Drawinput2(atoi(buff));
		Draw_table2();
	}
	if (input_mode == 3)
	{
		DrawText(buff, strlen(buff), param1 * 13. / 18., param2*6.67 / 9, black);
		Drawinput3(atoi(buff));
		Draw_table3();
	}
	if (input_mode == 4)
	{
		DrawText(buff, strlen(buff), param1 * 13. / 18., param2*6.67 / 9, black);
		Drawinput4(atoi(buff));
		Draw_table4();
	}
	glutSwapBuffers();
}

void input1(unsigned char key, int x, int y)
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glutSwapBuffers();
	int len;
	int n;
	if (input_mode == 1)
		n = 32;
	else
		n = 10;
	char k = key;
		if (printable == true)
		{
			confirm = false;
			build = false;
			if (k == 8)
			{
				len = strlen(buff);
				buff += len - 1;
				strcpy(buff, "");
				buff -= len - 1;
			}
			else
			{
				char*test = &k;
				if (strlen(buff) < n)
					strcat(buff, test);
			}
			clear_table();
		}
		if (index[0] >= 0 && index[1] >= 0)
		{
			if (k == 8)
			{
				len = strlen(table[index[0]][index[1]]);
				table[index[0]][index[1]] += len - 1;
				strcpy(table[index[0]][index[1]], "");
				table[index[0]][index[1]] -= len - 1;
			}
			else if(k=='0'||k == '1'||k == '2'||k == '3'||k == '4'||k == '5'||k == '6'||k == '7'||k == '8'||k == '9'||k == '-'||k == '.')
			{
				char*test = &k;
				if (strlen(table[index[0]][index[1]]) < 7)
					strcat(table[index[0]][index[1]], test);
			}
		}
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	renderScene();
	if (input_mode == 1)
	{
		DrawText(buff, strlen(buff), param1 * 4.1 / 9., param2*6.67 / 9, black);
	}
	if (input_mode == 2)
	{
		DrawText(buff, strlen(buff), param1 * 13. / 18., param2*6.67 / 9, black);
		Draw_table2();
	}
	if (input_mode == 3)
	{
		DrawText(buff, strlen(buff), param1 * 13. / 18., param2*6.67 / 9, black);
		Draw_table3();
	}
	if (input_mode == 4)
	{
		DrawText(buff, strlen(buff), param1 * 13. / 18., param2*6.67 / 9, black);
		Draw_table4();
	}
	glutSwapBuffers();
}
