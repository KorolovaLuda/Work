#include "radial.h"
radial rad;

void radial::set(char***mas, int num)
{
	n = 0;
	delete[]tab;
	bool creatable = true;
	for (int i = 0; i<num; i++)
		if (num_check(mas[i][0]) == false || empty_check(mas[i][0]) == false)
		{
			creatable = false;
			break;
		}
	if (creatable == true)
	{
		tab = new float[num];
		for (int i = 0; i < num; i++)
		{
			tab[i] = atof(mas[i][0]);
		}
		n = num;
	}
	else
	{
		tab = NULL;
		n = 0;
	}
}

radial::radial() {
	tab = nullptr;
	n = 0;
}

void radial::draw() {
	if (n != 0)
	{
		float angle = 2*pi / n;
		//draw sector
		for (int i = 0; i < n; i++)
		{
			glBegin(GL_POLYGON);
			glColor3f(colors[i][0], colors[i][1], colors[i][2]); glVertex3f(0, 0 - 2.2 / 9, 0);
			for (float j = angle; j <= tab[i]; j += (1 / (32 * pi)))
			{
				glColor3f(colors[i][0], colors[i][1], colors[i][2]); glVertex3f(cos(j) / 3 * param2 / param1, sin(j) / 3 - 2.2 / 9, 0);
			}
			glEnd();


			glBegin(GL_LINE_LOOP);
			glColor3f(0, 0, 0); glVertex3f(0, -2.2 / 9, 0);
			for (float j = angle; j <= tab[i]; j += (1 / (32 * pi)))
			{
				glColor3f(0, 0, 0); glVertex3f(cos(j) / 3 * param2 / param1, sin(j) / 3 - 2.2 / 9, 0);
			}
			glEnd();
		}
	}
}