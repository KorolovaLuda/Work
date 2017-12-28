#include "stakes.h"


void stakes::set(char***mas, int num)
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

stakes::stakes() {
	tab = nullptr;
	n = 0;
}

void stakes::draw() {

}