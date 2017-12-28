#include"Venn_diagram.h"

Venn1 ob;

void Venn1::parse()
{
	if (check(sourse) == true)
	{
		//подготавливаем множества
		set<int> a, b;
		set<int>c, u, temp,temp1;
		set<int>*mas = new set<int>[50];
		int*res, r;
		res = &r;
		int count=0;
		int cuan = count_set(sourse);
		n_set = cuan;
		bool* un = choose_set(sourse);
		if (cuan == 1)
		{
			u.insert(0);
			if (un[0] == true)
			{
				u.insert(2); 
				a.insert(2);
			}
			else if (un[1] == true)
			{
				u.insert(3); 
				b.insert(3);
			}
			else if (un[2] == true)
			{
				u.insert(5); 
				c.insert(5);
			}

		}
		else if (cuan == 2)
		{
			u.insert(0);
			if (un[0] == true && un[1] == true)
			{
				u.insert(2); u.insert(3); u.insert(6);
				a.insert(2); a.insert(6);
				b.insert(3); b.insert(6);
			}
			else if (un[1] == true && un[2] == true)
			{
				u.insert(3); u.insert(5); u.insert(15);
				b.insert(3); b.insert(15);
				c.insert(5); c.insert(15);
			}
			else if (un[0] == true && un[2] == true)
			{
				u.insert(2); u.insert(5); u.insert(10);
				a.insert(2); a.insert(10);
				c.insert(5); c.insert(10);
			}
		}
		else if (cuan == 3)
		{
			u.insert(0); u.insert(2); u.insert(3); u.insert(5); u.insert(6); u.insert(10); u.insert(15); u.insert(30);
			a.insert(2); a.insert(6); a.insert(10); a.insert(30);
			b.insert(3); b.insert(6); b.insert(15); b.insert(30);
			c.insert(5); c.insert(10); c.insert(15); c.insert(30);
		}
		//разбор строки
		char*buff = new char[3];
		char curr;
		char* curr1 = &curr;
		int p = 0;
		strange_stack2* set = nullptr;
		strange_stack* oper = nullptr;
		strange_stack* prior = nullptr;
		//заполняем стеки
		for (int i = 0; i < strlen(sourse); i++)
		{
			if (sourse[i] == 'a' || sourse[i] == 'b' || sourse[i] == 'c' || sourse[i] == 'u')
			{
				curr = sourse[i];
				strcpy(buff, curr1);
				buff += 1;
				strcpy(buff, "");
				buff -= 1;
				if (set == nullptr)
				{
					if(sourse[i] == 'a')
					set = new strange_stack2(a);
					if (sourse[i] == 'b')
						set = new strange_stack2(b);
					if (sourse[i] == 'c')
						set = new strange_stack2(c);
				}
				else
				{
					if (sourse[i] == 'a')
					set = set->pop(a, set);
					if (sourse[i] == 'b')
						set = set->pop(b, set);
					if (sourse[i] == 'c')
						set = set->pop(c, set);
				}
			}
			else
			{
				curr = sourse[i];
				if (curr == '+')
				{
					if (prior == nullptr)
					{
						itoa(3 - p, buff, 10);
						prior = new strange_stack(buff);
						oper = new strange_stack("+");
					}
					else
					{
						itoa(3 - p, buff, 10);
						prior = prior->pop(buff, prior);
						oper = oper->pop("+", oper);
					}
				}
				if (curr == '/')
				{
					if (prior == nullptr)
					{
						itoa(3 - p, buff, 10);
						prior = new strange_stack(buff);
						oper = new strange_stack("/");
					}
					else
					{
						itoa(3 - p, buff, 10);
						prior = prior->pop(buff, prior);
						oper = oper->pop("/", oper);
					}
				}
				if (curr == '*')
				{
					if (prior == nullptr)
					{
						itoa(2 - p, buff, 10), prior;
						prior = new strange_stack(buff);
						oper = new strange_stack("*");
					}
					else
					{
						itoa(2 - p, buff, 10), prior;
						prior = prior->pop(buff, prior);
						oper = oper->pop("*", oper);
					}
				}
				if (curr == '^')
				{
					if (prior == nullptr)
					{
						itoa(1 - p, buff, 10);
						prior = new strange_stack(buff);
						oper = new strange_stack("^");
					}
					else
					{
						itoa(1 - p, buff, 10);
						prior = prior->pop(buff, prior);
						oper = oper->pop("^", oper);
					}
				}
				if (curr == '-')
				{
					if (prior == nullptr)
					{
						itoa(0 - p, buff, 10);
						prior = new strange_stack(buff);
						oper = new strange_stack("-");
					}
					else
					{
						itoa(0 - p, buff, 10);
						prior = prior->pop(buff, prior);
						oper = oper->pop("-", oper);
					}
				}
				if (curr == '(')
				{
					p += 5;
				}
				if (curr == ')')
				{
					p -= 5;
				}
			}
			// питаемся уменьшить стеки
			if (oper != nullptr)
				if (oper->next != nullptr)
					if (atoi(prior->next->data) <= atoi(prior->data))
					{
						temp = r_set;
						r_set.clear();
						if (oper->next->data[0] == '-')
						{
							set_difference(u.begin(), u.end(), set->data.begin(), set->data.end(), inserter(r_set, r_set.begin()));
							set = set->push(set);
							set = set->pop(r_set, set);
						}
						if (oper->next->data[0] == '*')
						{
							temp1 = set->data;
							set_intersection(temp1.begin(), temp1.end(), set->next->data.begin(), set->next->data.end(), inserter(r_set, r_set.begin()));
							set = set->push(set);
							set = set->push(set);
							set = set->pop(r_set, set);
						}
						if (oper->next->data[0] == '+')
						{
							temp1 = set->data;
							set_union(temp1.begin(), temp1.end(), set->next->data.begin(), set->next->data.end(), inserter(r_set, r_set.begin()));
							set = set->push(set);
							set = set->push(set);
							set = set->pop(r_set, set);
						}
						if (oper->next->data[0] == '^')
						{
							temp1 = set->data;
							set_symmetric_difference(temp1.begin(), temp1.end(), set->next->data.begin(), set->next->data.end(), inserter(r_set, r_set.begin()));
							set = set->push(set);
							set = set->push(set);
							set = set->pop(r_set, set);
						}
						if (oper->next->data[0] == '/')
						{
							temp1 = set->data;
							set_difference(set->next->data.begin(), set->next->data.end(), temp1.begin(), temp1.end(), inserter(r_set, r_set.begin()));
							set = set->push(set);
							set = set->push(set);
							set = set->pop(r_set, set);
						}
						oper->previous_push(oper);
						prior->previous_push(prior);
					}
		}
		while (oper != nullptr)
		{
			temp = r_set;
			r_set.clear();
			if (oper->data[0] == '-')
			{
				set_difference(u.begin(), u.end(), set->data.begin(), set->data.end(), inserter(r_set, r_set.begin()));
				set = set->push(set);
				set = set->pop(r_set, set);
			}
			if (oper->data[0] == '*')
			{
				temp1 = set->data;
				set_intersection(temp1.begin(), temp1.end(), set->next->data.begin(), set->next->data.end(), inserter(r_set, r_set.begin()));
				set = set->push(set);
				set = set->push(set);
				set = set->pop(r_set, set);
			}
			if (oper->data[0] == '+')
			{
				temp1 = set->data;
				set_union(temp1.begin(), temp1.end(), set->next->data.begin(), set->next->data.end(), inserter(r_set, r_set.begin()));
				set = set->push(set);
				set = set->push(set);
				set = set->pop(r_set, set);
			}
			if (oper->data[0] == '^')
			{
				temp1 = set->data;
				set_symmetric_difference(temp1.begin(), temp1.end(), set->next->data.begin(), set->next->data.end(), inserter(r_set, r_set.begin()));
				set = set->push(set);
				set = set->push(set);
				set = set->pop(r_set, set);
			}
			if (oper->data[0] == '/')
			{
				temp1 = set->data;
				set_difference(set->next->data.begin(), set->next->data.end(), temp1.begin(), temp1.end(), inserter(r_set, r_set.begin()));
				set = set->push(set);
				set = set->push(set);
				set = set->pop(r_set, set);
			}
			oper = oper->push(oper);
			prior = prior->push(prior);
		}
		result = new bool[pow(cuan, 2)];
		for (int i = 0; i < pow(cuan, 2); i++)
				result[i] = false;
		if (cuan == 1)
		{
			for (int i = 0; i < set->data.size(); i++)
			{
				*res = *next(set->data.begin(), i);
				if (*res == 0)
					result[0] = true;
				if (*res == 2 || *res == 3 || *res == 5)
					result[1] = true;
			}
		}
		if (cuan == 2)
		{
			for (int i = 0; i < set->data.size(); i++)
			{
				*res = *next(set->data.begin(), i);
				if (*res == 0)
					result[0] = true;
				if (un[0] == true && un[1] == true)//A B
				{
					if (*res == 2)
						result[1] = true;
					if (*res == 6)
						result[2] = true;
					if (*res == 3)
						result[3] = true;
				}
				else if (un[1] == true && un[2] == true)//B C
				{
					if (*res == 3)
						result[1] = true;
					if (*res == 15)
						result[2] = true;
					if (*res == 5)
						result[3] = true;
				}
				else if (un[0] == true && un[2] == true)//A C
				{
					if (*res == 2)
						result[1] = true;
					if (*res == 10)
						result[2] = true;
					if (*res == 5)
						result[3] = true;
				}
			}
		}
		if (cuan == 3)
		{
			for (int i = 0; i < set->data.size(); i++)
			{
				*res = *next(set->data.begin(), i);
				if (*res == 0)
					result[0] = true;
				if (*res == 2)
					result[1] = true;
				if (*res == 3)
					result[3] = true;
				if (*res == 5)
					result[5] = true;
				if (*res == 6)
					result[2] = true;
				if (*res == 10)
					result[6] = true;
				if (*res == 15)
					result[4] = true;
				if (*res == 30)
					result[7] = true;
			}
		}
	}
}
int Venn1::count_set(char*str)
{
	int len = strlen(str);
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == 'a')
		{
			count++;
			break;
		}
	}
	for (int i = 0; i < len; i++)
	{
		if (str[i] == 'b')
		{
			count++;
			break;
		}
	}
	for (int i = 0; i < len; i++)
	{
		if (str[i] == 'c')
		{
			count++;
			break;
		}
	}
	return count;
}
bool Venn1::check(char*str)
{
	if ((str[0] != '^') || (str[0] != '+') || (str[0] != '/') || (str[0] != '*'))
		return true;
	return false;
}

bool* Venn1::choose_set(char*str)
{
	int len = strlen(str);
	bool* count = new bool[3];
	for (int i = 0; i < 3; i++)
		count[i] = false;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == 'a')
		{
			count[0] = true;
			break;
		}
	}
	for (int i = 0; i < len; i++)
	{
		if (str[i] == 'b')
		{
			count[1] = true;
			break;
		}
	}
	for (int i = 0; i < len; i++)
	{
		if (str[i] == 'c')
		{
			count[3] = true;
			break;
		}
	}
	return count;
}

Venn1::Venn1() 
{
	sourse = new char[100];
	result = nullptr;
	n_set = 0;
}
Venn1::~Venn1()
{
	delete[] sourse;
	delete[]result;
}
void Venn1::set_set(char*str)
{
	strcpy(sourse,str);
}

void Venn1::drawVenDiagram()
{
	glBegin(GL_POLYGON);
	if (result[0] == true)
	{
		glColor3f(0, 0.58, 0.83); glVertex3f(-3. / 10 + 1. / 4, -1. / 9 + 3. / 10, 0);
		glColor3f(0, 0.58, 0.83); glVertex3f(3. / 10 + 1. / 4, -1. / 9 + 3. / 10, 0);
		glColor3f(0, 0.58, 0.83); glVertex3f(3. / 10 + 1. / 4, -1. / 9 - 5. / 10, 0);
		glColor3f(0, 0.58, 0.83); glVertex3f(-3. / 10 + 1. / 4, -1. / 9 - 5. / 10, 0);
	}
	else
	{
		glColor3f(1, 1, 1); glVertex3f(-3. / 10 + 1. / 4, -1. / 9 + 3. / 10, 0);
		glColor3f(1, 1, 1); glVertex3f(3. / 10 + 1. / 4, -1. / 9 + 3. / 10, 0);
		glColor3f(1, 1, 1); glVertex3f(3. / 10 + 1. / 4, -1. / 9 - 5. / 10, 0);
		glColor3f(1, 1, 1); glVertex3f(-3. / 10 + 1. / 4, -1. / 9 - 5. / 10, 0);
	}
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 0); glVertex3f(-3. / 10 + 1. / 4, -1. / 9 + 3. / 10, 0);
	glColor3f(0, 0, 0); glVertex3f(3. / 10 + 1. / 4, -1. / 9 + 3. / 10, 0);
	glColor3f(0, 0, 0); glVertex3f(3. / 10 + 1. / 4, -1. / 9 - 5. / 10, 0);
	glColor3f(0, 0, 0); glVertex3f(-3. / 10 + 1. / 4, -1. / 9 - 5. / 10, 0);
	glEnd();
	if (n_set == 1)
	{
		glBegin(GL_POLYGON);
		for (int i = 0; i <= 360; i++)
		{
			if (result[1] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5 )*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 2. / 9, 0);
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 )*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 2. / 9, 0);
			}
		}
		glEnd();
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i <= 360; i++)
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 2. / 9, 0);
		}
		glEnd();
	}
	if (n_set == 2)
	{
		glBegin(GL_POLYGON);
		for (int i = -120; i <= 120; i++)
		{
			if(result[1]==true)
			{glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5 + cos(0) / 10)*param2/param1+ 1. / 4, (sin(i*3.14 / 180) / 5)-2./9, 0);}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 + cos(0) / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 2. / 9, 0);
			}
		}
		for (int i = 60; i >= -60; i--)
		{
			if (result[1] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5 + cos((360 / 2)*3.14 / 180) / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 2. / 9, 0);
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 + cos((360 / 2)*3.14 / 180) / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 2. / 9, 0);
			}
		}
		glEnd();
		glBegin(GL_POLYGON);
		for (int i = 240; i >= 120; i--)
		{
			if (result[3] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5 + cos(0) / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 2. / 9, 0);
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 + cos(0) / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 2. / 9, 0);
			}
		}
		for (int i = 60; i <= 300; i++)
		{
			if (result[3] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5 + cos((360 / 2)*3.14 / 180) / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 2. / 9, 0);
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 + cos((360 / 2)*3.14 / 180) / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 2. / 9, 0);
			}
		}
		glEnd();
		glBegin(GL_POLYGON);
		for (int i = -60; i <= 60; i++)
		{
			if (result[2] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5 + cos((360 / 2)*3.14 / 180) / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 2. / 9, 0);
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 + cos((360 / 2)*3.14 / 180) / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 2. / 9, 0);
			}
		}
		for (int i = 120; i <= 240; i++)
		{
			if (result[2] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5 + cos(0) / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 2. / 9, 0);
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 + cos(0) / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 2. / 9, 0);
			}
		}
		glEnd();
		glBegin(GL_LINE_LOOP);
		for (int i = -120; i <= 120; i++)
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 + cos(0) / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 2. / 9, 0);
		}
		for (int i = 60; i >= -60; i--)
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 + cos((360 / 2)*3.14 / 180) / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 2. / 9, 0);
		}
		glEnd();
		glBegin(GL_LINE_LOOP);
		for (int i = 240; i >= 120; i--)
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 + cos(0) / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 2. / 9, 0);
		}
		for (int i = 60; i <= 300; i++)
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 + cos((360 / 2)*3.14 / 180) / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 2. / 9, 0);
		}
		glEnd();
		glBegin(GL_LINE_LOOP);
		for (int i = -60; i <= 60; i++)
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 + cos((360 / 2)*3.14 / 180) / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 2. / 9, 0);
		}
		for (int i = 120; i <= 240; i++)
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 + cos(0) / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 2. / 9, 0);
		}

		glEnd();
	}
	if (n_set == 3)
	{
		glBegin(GL_POLYGON);
		for (float i = 240; i >= 60; i-=0.5)//
		{
			if (result[1] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5 - 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//левый
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 - 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//левый
			}
		}
		for (float i = 120; i <= 180; i+=0.5)//
		{
			if (result[1] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5 + 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//правый
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 + 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//правый
			}
		}
		for (float i = 120; i <= 180; i+=0.5)
		{
			if (result[1] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5 - tan(pi / 3) / 10) - 1. / 9, 0);//низ
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5 - tan(pi / 3) / 10) - 1. / 9, 0);//низ
			}
		}
		glEnd();
		glBegin(GL_POLYGON);
		
		for (float i = 0; i <= 60; i+=0.5)//
		{
			if (result[3] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5 - 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//левый
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 - 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//левый
			}
		}
		for (float i = 120; i >= -60; i -= 0.5)//
		{
			if (result[3] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5 + 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//правый
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 + 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//правый
			}
		}
		for (float i = 0; i <= 60; i += 0.5)
		{
			if (result[3] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5 - tan(pi / 3) / 10) - 1. / 9, 0);//низ
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5 - tan(pi / 3) / 10) - 1. / 9, 0);//низ
			}
		}
		glEnd();
		glBegin(GL_POLYGON);
		for (float i = -120; i <= -60; i += 0.5)//
		{
			if (result[5] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5 - 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//левый
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 - 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//левый
			}
		}
		for (float i = 240; i <= 300; i += 0.5)//
		{
			if (result[5] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5 + 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//правый
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 + 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//правый
			}
		}
		for (float i = 0; i >=-180; i -= 0.5)
		{
			if (result[5] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5 - tan(pi / 3) / 10) - 1. / 9, 0);//низ
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5 - tan(pi / 3) / 10) - 1. / 9, 0);//низ
			}
		}
		glEnd();
		glBegin(GL_POLYGON);
		for (float i = -120; i <= -60; i += 0.5)//
		{
			if (result[6] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5 - 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//левый
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 - 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//левый
			}
		}
		for (float i = 240; i >= 180; i -= 0.5)//
		{
			if (result[6] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5 + 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//правый
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 + 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//правый
			}
		}
		for (float i = 120; i <= 180; i += 0.5)
		{
			if (result[6] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5 - tan(pi / 3) / 10) - 1. / 9, 0);//низ
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5 - tan(pi / 3) / 10) - 1. / 9, 0);//низ
			}
		}
		glEnd();
		glBegin(GL_POLYGON);
		for (float i = 0; i <= 60; i += 0.5)//
		{
			if (result[2] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5 - 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//левый
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 - 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//левый
			}
		}
		for (float i = 120; i <= 180; i += 0.5)//
		{
			if (result[2] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5 + 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//правый
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 + 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//правый
			}
		}
		for (float i = 120; i >= 60; i -= 0.5)
		{
			if (result[2] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5 - tan(pi / 3) / 10) - 1. / 9, 0);//низ
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5 - tan(pi / 3) / 10) - 1. / 9, 0);//низ
			}
		}
		glEnd();
		glBegin(GL_POLYGON);
		for (float i = 0; i >= -60; i -= 0.5)//
		{
			if (result[4] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5 - 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//левый
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 - 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//левый
			}
		}
		for (float i = 240; i <= 300; i += 0.5)//
		{
			if (result[4] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5 + 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//правый
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 + 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//правый
			}
		}
		for (float i = 0; i <= 60; i += 0.5)
		{
			if (result[4] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5 - tan(pi / 3) / 10) - 1. / 9, 0);//низ
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5 - tan(pi / 3) / 10) - 1. / 9, 0);//низ
			}
		}
		glEnd();
		glBegin(GL_POLYGON);
		for (float i = 0; i >= -60; i -= 0.5)//
		{
			if (result[7] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5 - 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//левый
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 - 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//левый
			}
		}
		for (float i = 240; i >= 180; i -= 0.5)//
		{
			if (result[7] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5 + 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//правый
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5 + 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//правый
			}
		}
		for (float i = 120; i >= 60; i -= 0.5)
		{
			if (result[7] == true)
			{
				glColor3f(0, 0.58, 0.83); glVertex3f((cos(i*3.14 / 180) / 5)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5 - tan(pi / 3) / 10) - 1. / 9, 0);//низ
			}
			else
			{
				glColor3f(1, 1, 1); glVertex3f((cos(i*3.14 / 180) / 5)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5 - tan(pi / 3) / 10) - 1. / 9, 0);//низ
			}
		}
		glEnd();

		//контур

		glBegin(GL_LINE_LOOP);
		for (float i = 240; i >= 60; i -= 0.5)//
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 - 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//левый
		}
		for (float i = 120; i <= 180; i += 0.5)//
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 + 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//правый
		}
		for (float i = 120; i <= 180; i += 0.5)
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5 - tan(pi / 3) / 10) - 1. / 9, 0);//низ
		}
		glEnd();
		glBegin(GL_LINE_LOOP);

		for (float i = 0; i <= 60; i += 0.5)//
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 - 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//левый
		}
		for (float i = 120; i >= -60; i -= 0.5)//
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 + 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//правый
		}
		for (float i = 0; i <= 60; i += 0.5)
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5 - tan(pi / 3) / 10) - 1. / 9, 0);//низ
		}
		glEnd();
		glBegin(GL_LINE_LOOP);
		for (float i = -120; i <= -60; i += 0.5)//
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 - 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//левый
		}
		for (float i = 240; i <= 300; i += 0.5)//
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 + 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//правый
		}
		for (float i = 0; i >= -180; i -= 0.5)
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5 - tan(pi / 3) / 10) - 1. / 9, 0);//низ
		}
		glEnd();
		glBegin(GL_LINE_LOOP);
		for (float i = -120; i <= -60; i += 0.5)//
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 - 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//левый
		}
		for (float i = 240; i >= 180; i -= 0.5)//
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 + 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//правый
		}
		for (float i = 120; i <= 180; i += 0.5)
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5 - tan(pi / 3) / 10) - 1. / 9, 0);//низ
		}
		glEnd();
		glBegin(GL_LINE_LOOP);
		for (float i = 0; i <= 60; i += 0.5)//
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 - 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//левый
		}
		for (float i = 120; i <= 180; i += 0.5)//
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 + 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//правый
		}
		for (float i = 120; i >= 60; i -= 0.5)
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5 - tan(pi / 3) / 10) - 1. / 9, 0);//низ
		}
		glEnd();
		glBegin(GL_LINE_LOOP);
		for (float i = 0; i >= -60; i -= 0.5)//
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 - 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//левый
		}
		for (float i = 240; i <= 300; i += 0.5)//
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 + 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//правый
		}
		for (float i = 0; i <= 60; i += 0.5)
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5 - tan(pi / 3) / 10) - 1. / 9, 0);//низ
		}
		glEnd();
		glBegin(GL_LINE_LOOP);
		for (float i = 0; i >= -60; i -= 0.5)//
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 - 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//левый
		}
		for (float i = 240; i >= 180; i -= 0.5)//
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5 + 1. / 10)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5) - 1. / 9, 0);//правый
		}
		for (float i = 120; i >= 60; i -= 0.5)
		{
			glColor3f(0, 0, 0); glVertex3f((cos(i*3.14 / 180) / 5)*param2 / param1 + 1. / 4, (sin(i*3.14 / 180) / 5 - tan(pi / 3) / 10) - 1. / 9, 0);//низ
		}
		glEnd();
	}
	//glutSwapBuffers();
}