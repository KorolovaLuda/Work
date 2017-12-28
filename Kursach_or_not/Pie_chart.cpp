#include"Pie_chart.h"

pie obj;

pie::pie()
{
		tab = NULL;
		n = 0;
}

void pie::draw()
{
	for (int i = 0; i < n; i++)
	{
		glBegin(GL_POLYGON);
		glColor3f(colors[i][0], colors[i][1], colors[i][2]); glVertex3f(4.5 / 9, 3.7 / 9 - (i + 1)*1. / 9+ 0.02, 0);
		glColor3f(colors[i][0], colors[i][1], colors[i][2]); glVertex3f(4.5 / 9, 3.7 / 9 - i*1. / 9-0.02, 0);
		glColor3f(colors[i][0], colors[i][1], colors[i][2]); glVertex3f(5. / 9, 3.7 / 9 - i*1. / 9 - 0.02, 0);
		glColor3f(colors[i][0], colors[i][1], colors[i][2]); glVertex3f(5. / 9, 3.7 / 9 - (i + 1)*1. / 9 + 0.02, 0);
		glEnd();
	}
	if (n != 0)
	{
		float angle = 0;
		//draw sector
		for (int i = 0; i < n; i++)
		{
			glBegin(GL_POLYGON);
			glColor3f(colors[i][0], colors[i][1], colors[i][2]); glVertex3f(0, 0 - 2.2 / 9, 0);
			for (float j = angle; j <= tab[i]; j += (1/ (32 * pi)))
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

			angle = tab[i];
		}
	}
}
void pie::set(char***mas, int num)
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
		float count = 0;
		for (int i = 0; i < num; i++)
		{
			tab[i] = atof(mas[i][0]);
			count += tab[i];
		}
		n = num;
		for (int i = 0; i < num; i++)
		{
			tab[i] = tab[i] * 2 * pi / count;
			if (i != 0)
				tab[i] += tab[i - 1];
		}
	}
	else
	{
		tab = NULL;
		n = 0;
	}
}

/*pie::~pie() {
	delete[] tab;
}*/