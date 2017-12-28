#include"Class.h"
void Venn::del_first_char(int n)
{
	str += n;
}
Venn::Venn(char*s)
{
	str = new char[100];
	strcpy(str, s);
}
char* Venn::get_str()
{
	return str;
}

bool Venn::small_str_on_first(char* s)
{
	char*temp = new char[100];
	if (strstr(str, s) != nullptr)
	{
		strcpy(temp, strstr(str, s));
		if (strcmp(str, temp) == 0)
			return true;
		else
			return false;
	}
	else return false;
}

void Venn::first_del(int num)
{
	str += num;
}
void Venn::change_sub_str(char*st1,char*st2)
{
	char* temp;
	char*temp2=new char[100];
	int len1;
	int def;
	temp= strstr(str, st1);
	len1 = strlen(st1);
	while (temp != nullptr)
	{
		def =strlen(str)-strlen(temp) ;
		strcpy(temp2, str);
		temp2 += def;	
		strcpy(temp2, "");
		temp2 -= def;
		temp += len1;
		strcat(temp2, st2);
		strcat(temp2, temp);
		strcpy(str, temp2);
		temp = strstr(str, st1);
	}
}

void Venn :: del_char(char c)
{
	int len = strlen(str);
	char*temp = new char[100];
	for(int i =0; i<len;i++)
		if (str[i] == c)
		{
			strcpy(temp, str);
			temp += i+1;
			str += i;
			strcpy(str, "");
			str -= i;
			strcat(str, temp);
			len--;
		}
}

char* Venn::cat_num()
{
	bool is = false;
	int len = strlen(str);
	int count = 0;
	if (isdigit(str[0]) != 0)
		count++;
	for (int i = 1; i < len; i++)
	{
		if (isdigit(str[i]) != 0)
			count++;
		else if (str[i] == '.')
		{
			if (is == false)
			{
				count++;
				is = true;
			}
			else
				break;
		}
		else
			break;
	}
	char*temp = new char[100];
	strcpy(temp, str);
	temp += count;
	strcpy(temp, "");
	temp -= count;
	str += count;
	return temp;
}




float generate(char*str,float num)
{
	strange_stack* nums=NULL, *oper=NULL, *prior=NULL;
	int priority = 0;
	char*buff = new char[100];
	char*temp = new char[100];
	strlwr(str);
	strcpy(temp, str);
	strcpy(buff, str);
	for(int i =0; i<strlen(temp)-1;i++)
		if (temp[i] == '('&&temp[i + 1] == '-')
		{
			temp += i+1;
			strcpy(temp, "");
			temp -= i + 1;
			buff += i+1;
			strcat(temp, "0");
			strcat(temp, buff);
			strcpy(buff, temp);
		}
	//cout << temp << endl;
	Venn obj(temp);
	strcpy(temp, "");
	strcpy(buff, "");
	obj.change_sub_str(" ", "");//убираем пробелы
	gcvt(num, 50, temp);
	obj.change_sub_str("x",temp);//вставляем число
	bool err = false;
	float num1, num2;
	
	if (str[0] == '-')
	{
		nums = new strange_stack("0");
		oper = new strange_stack("-");
		prior = new strange_stack("4");
		obj.first_del(1);
	}
	while ((strcmp(obj.get_str(), "") != 0) && (err == false))
	{
		strcpy(temp, "");
		//put into stacks
		if (obj.small_str_on_first("("))
		{
			priority -= 10;
			obj.first_del(1);
		}
		else if (obj.small_str_on_first(")"))
		{
			priority += 10;
			obj.first_del(1);
		}
		else if (obj.small_str_on_first("sin"))
		{
			itoa(priority + 1, buff, 10);
			if (oper == NULL)
			{
				oper = new strange_stack("sin");
				prior = new strange_stack(buff);
			}
			else
			{
				oper = oper->pop("sin", oper);
				prior = prior->pop(buff, prior);
			}
			obj.first_del(3);
		}
		else if (obj.small_str_on_first("cos"))
		{
			itoa(priority + 1, buff, 10);
			if (oper == NULL)
			{
				oper = new strange_stack("cos");
				prior = new strange_stack(buff);
			}
			else
			{
				oper = oper->pop("cos", oper);
				prior = prior->pop(buff, prior);
			}
			obj.first_del(3);
		}
		else if (obj.small_str_on_first("tg"))
		{
			itoa(priority + 1, buff, 10);
			if (oper == NULL)
			{
				oper = new strange_stack("tg");
				prior = new strange_stack(buff);
			}
			else
			{
				oper = oper->pop("tg", oper);
				prior = prior->pop(buff, prior);
			}
			obj.first_del(2);
		}
		else if (obj.small_str_on_first("ctg"))
		{
			itoa(priority + 1, buff, 10);
			if (oper == NULL)
			{
				oper = new strange_stack("ctg");
				prior = new strange_stack(buff);
			}
			else
			{
				oper = oper->pop("ctg", oper);
				prior = prior->pop(buff, prior);
			}
			obj.first_del(3);
		}
		else if (obj.small_str_on_first("ln"))
		{
			itoa(priority + 1, buff, 10);
			if (oper == NULL)
			{
				oper = new strange_stack("ln");
				prior = new strange_stack(buff);
			}
			else
			{
				oper = oper->pop("ln", oper);
				prior = prior->pop(buff, prior);
			}
			obj.first_del(2);
		}
		else if (obj.small_str_on_first("arctg"))
		{
			itoa(priority + 1, buff, 10);
			if (oper == NULL)
			{
				oper = new strange_stack("arctg");
				prior = new strange_stack(buff);
			}
			else
			{
				oper = oper->pop("arctg", oper);
				prior = prior->pop(buff, prior);
			}
			obj.first_del(5);
		}
		else if (obj.small_str_on_first("arcctg"))
		{
			itoa(priority + 1, buff, 10);
			if (oper == NULL)
			{
				oper = new strange_stack("arcctg");
				prior = new strange_stack(buff);
			}
			else
			{
				oper = oper->pop("arcctg", oper);
				prior = prior->pop(buff, prior);
			}
			obj.first_del(6);
		}
		else if (obj.small_str_on_first("arcsin"))
		{
			itoa(priority + 1, buff, 10);
			if (oper == NULL)
			{
				oper = new strange_stack("arcsin");
				prior = new strange_stack(buff);
			}
			else
			{
				oper = oper->pop("arcsin", oper);
				prior = prior->pop(buff, prior);
			}
			obj.first_del(6);
		}
		else if (obj.small_str_on_first("arccos"))
		{
			itoa(priority + 1, buff, 10);
			if (oper == NULL)
			{
				oper = new strange_stack("arccos");
				prior = new strange_stack(buff);
			}
			else
			{
				oper = oper->pop("arccos", oper);
				prior = prior->pop(buff, prior);
			}
			obj.first_del(6);
		}
		else if (obj.small_str_on_first("^"))
		{
			itoa(priority + 2, buff, 10);
			if (oper == NULL)
			{
				oper = new strange_stack("^");
				prior = new strange_stack(buff);
			}
			else
			{
				oper = oper->pop("^", oper);
				prior = prior->pop(buff, prior);
			}
			obj.first_del(1);
		}
		else if (obj.small_str_on_first("*"))
		{
			itoa(priority + 3, buff, 10);
			if (oper == NULL)
			{
				oper = new strange_stack("*");
				prior = new strange_stack(buff);
			}
			else
			{
				oper = oper->pop("*", oper);
				prior = prior->pop(buff, prior);
			}
			obj.first_del(1);
		}
		else if (obj.small_str_on_first("/"))
		{
			itoa(priority + 3, buff, 10);
			if (oper == NULL)
			{
				oper = new strange_stack("/");
				prior = new strange_stack(buff);
			}
			else
			{
				oper = oper->pop("/", oper);
				prior = prior->pop(buff, prior);
			}
			obj.first_del(1);
		}
		else if (obj.small_str_on_first("+"))
		{
			itoa(priority + 4, buff, 10);
			if (oper == NULL)
			{
				oper = new strange_stack("+");
				prior = new strange_stack(buff);
			}
			else
			{
				oper = oper->pop("+", oper);
				prior = prior->pop(buff, prior);
			}
			obj.first_del(1);
		}
		else if (obj.small_str_on_first("-"))
		{
			itoa(priority + 4, buff, 10);
			if (oper == NULL)
			{
				oper = new strange_stack("-");
				prior = new strange_stack(buff);
			}
			else
			{
				oper = oper->pop("-", oper);
				prior = prior->pop(buff, prior);
			}
			obj.first_del(1);
		}
		else if (obj.small_str_on_first("pi"))
		{
			if (nums == NULL)
				nums = new strange_stack("3.14159265359");
			else
				nums = nums->pop("3.14159265359", nums);
			obj.first_del(2);
		}
		else if (obj.small_str_on_first("e"))
		{
			if (nums == NULL)
				nums = new strange_stack("2.71828182846");
			else
				nums = nums->pop("2.71828182846", nums);
			obj.first_del(1);
		}
		else
		{
			temp = obj.cat_num();
			if (strcmp(temp, "") != 0)
			{
				if (nums == NULL)
					nums = new strange_stack(temp);
				else
					nums = nums->pop(temp, nums);
			}
			else
				err = true;
		}
		if (err == true)
			break;
		//count step or not
		if (prior != nullptr)
		{
			if (prior->next != nullptr)
			{
				while (atoi(prior->data) >= atoi(prior->next->data))
				{
							strcpy(temp, oper->next->data);
							oper->previous_push(oper);
							prior->previous_push(prior);
							if (strcmp(temp, "sin") == 0)
							{
								num1 = sin(atof(nums->data));
								nums = nums->push(nums);
								gcvt(num1, 50, temp);
								nums = nums->pop(temp, nums);
							}
							else if (strcmp(temp, "cos") == 0)
							{
								num1 = cos(atof(nums->data));
								nums = nums->push(nums);
								gcvt(num1, 50, temp);
								nums = nums->pop(temp, nums);
							}
							else if (strcmp(temp, "tg") == 0)
							{
								if (cos(atof(nums->data)) == 0)
									return NULL;
								num1 = tan(atof(nums->data));
								nums = nums->push(nums);
								gcvt(num1, 50, temp);
								nums = nums->pop(temp, nums);
							}
							else if (strcmp(temp, "ctg") == 0)
							{
								if (sin(atof(nums->data)) == 0)
									return NULL;
								num1 = 1. / (tan(atof(nums->data)));
								nums = nums->push(nums);
								gcvt(num1, 50, temp);
								nums = nums->pop(temp, nums);
							}
							else if (strcmp(temp, "ln") == 0)
							{
								if (atof(nums->data) <= 1)
									return NULL;
								num1 = log(atof(nums->data));
								nums = nums->push(nums);
								gcvt(num1, 50, temp);
								nums = nums->pop(temp, nums);
							}
							else if (strcmp(temp, "arccos") == 0)
							{
								if (atof(nums->data) < -1|| atof(nums->data) > 1)
									return NULL;
								num1 = acos(atof(nums->data));
								nums = nums->push(nums);
								gcvt(num1, 50, temp);
								nums = nums->pop(temp, nums);
							}
							else if (strcmp(temp, "arcsin") == 0)
							{
								if (atof(nums->data) < -1 || atof(nums->data) > 1)
									return NULL;
								num1 = asin(atof(nums->data));
								nums = nums->push(nums);
								gcvt(num1, 50, temp);
								nums = nums->pop(temp, nums);
							}
							else if (strcmp(temp, "arctg") == 0)
							{
								num1 = atan(atof(nums->data));
								nums = nums->push(nums);
								gcvt(num1, 50, temp);
								nums = nums->pop(temp, nums);
							}
							else if (strcmp(temp, "arcctg") == 0)
							{
								num1 = sin(atof(nums->data));
								num1 = 3.14159265359 / 2 - num1;
								nums = nums->push(nums);
								gcvt(num1, 50, temp);
								nums = nums->pop(temp, nums);
							}
							else if (strcmp(temp, "^") == 0)
							{
								num1 = atof(nums->data);
								nums = nums->push(nums);
								num2 = atof(nums->data);
								nums = nums->push(nums);
								num1 = pow(num2, num1);
								gcvt(num1, 50, temp);
								nums = nums->pop(temp, nums);
							}
							else if (strcmp(temp, "*") == 0)
							{
								num1 = atof(nums->data);
								nums = nums->push(nums);
								num2 = atof(nums->data);
								nums = nums->push(nums);
								num1 = num2*num1;
								gcvt(num1, 50, temp);
								nums = nums->pop(temp, nums);
							}
							else if (strcmp(temp, "/") == 0)
							{
								num1 = atof(nums->data);
								nums = nums->push(nums);
								num2 = atof(nums->data);
								if (num1 == 0)
									return NULL;
								nums = nums->push(nums);
								num1 = num2 / num1;
								gcvt(num1, 50, temp);
								nums = nums->pop(temp, nums);
							}
							else if (strcmp(temp, "+") == 0)
							{
								num1 = atof(nums->data);
								nums = nums->push(nums);
								num2 = atof(nums->data);
								nums = nums->push(nums);
								num1 = num2 + num1;
								gcvt(num1, 50, temp);
								nums = nums->pop(temp, nums);
							}
							else if (strcmp(temp, "-") == 0)
							{
								num1 = atof(nums->data);
								nums = nums->push(nums);
								num2 = atof(nums->data);
								nums = nums->push(nums);
								num1 = num2 - num1;
								gcvt(num1, 50, temp);
								nums = nums->pop(temp, nums);
							}
								if (prior == nullptr)
									break;
								else if (prior->next == nullptr)
									break;

				}
			}
		}
		/*nums->output(nums);
		cout << "------" << endl;
		oper->output(oper);
		cout << "------" << endl;
		prior->output(prior);*/
	}
	while (oper != NULL)
	{
		strcpy(temp, oper->data);
		oper = oper->push(oper);
		prior = prior->push(prior);
		if (strcmp(temp, "sin") == 0)
		{
			num1 = sin(atof(nums->data));
			nums = nums->push(nums);
			gcvt(num1, 50, temp);
			nums = nums->pop(temp, nums);
		}
		else if (strcmp(temp, "cos") == 0)
		{
			num1 = cos(atof(nums->data));
			nums = nums->push(nums);
			gcvt(num1, 50, temp);
			nums = nums->pop(temp, nums);
		}
		else if (strcmp(temp, "tg") == 0)
		{
			num1 = tan(atof(nums->data));
			nums = nums->push(nums);
			gcvt(num1, 50, temp);
			nums = nums->pop(temp, nums);
		}
		else if (strcmp(temp, "ctg") == 0)
		{
			num1 = 1. / (tan(atof(nums->data)));
			nums = nums->push(nums);
			gcvt(num1, 50, temp);
			nums = nums->pop(temp, nums);
		}
		else if (strcmp(temp, "ln") == 0)
		{
			num1 = log(atof(nums->data));
			nums = nums->push(nums);
			gcvt(num1, 50, temp);
			nums = nums->pop(temp, nums);
		}
		else if (strcmp(temp, "arccos") == 0)
		{
			num1 = acos(atof(nums->data));
			nums = nums->push(nums);
			gcvt(num1, 50, temp);
			nums = nums->pop(temp, nums);
		}
		else if (strcmp(temp, "arcsin") == 0)
		{
			num1 = asin(atof(nums->data));
			nums = nums->push(nums);
			gcvt(num1, 50, temp);
			nums = nums->pop(temp, nums);
		}
		else if (strcmp(temp, "arctg") == 0)
		{
			num1 = atan(atof(nums->data));
			nums = nums->push(nums);
			gcvt(num1, 50, temp);
			nums = nums->pop(temp, nums);
		}
		else if (strcmp(temp, "arcctg") == 0)
		{
			num1 = sin(atof(nums->data));
			num1 = 3.14159265359 / 2 - num1;
			nums = nums->push(nums);
			gcvt(num1, 50, temp);
			nums = nums->pop(temp, nums);
		}
		else if (strcmp(temp, "^") == 0)
		{
			num1 = atof(nums->data);
			nums = nums->push(nums);
			num2 = atof(nums->data);
			nums = nums->push(nums);
			num1 = pow(num2, num1);
			gcvt(num1, 50, temp);
			nums = nums->pop(temp, nums);
		}
		else if (strcmp(temp, "*") == 0)
		{
			num1 = atof(nums->data);
			nums = nums->push(nums);
			num2 = atof(nums->data);
			nums = nums->push(nums);
			num1 = num2*num1;
			gcvt(num1, 50, temp);
			nums = nums->pop(temp, nums);
		}
		else if (strcmp(temp, "/") == 0)
		{
			num1 = atof(nums->data);
			nums = nums->push(nums);
			num2 = atof(nums->data);
			nums = nums->push(nums);
			num1 = num2 / num1;
			gcvt(num1, 50, temp);
			nums = nums->pop(temp, nums);
		}
		else if (strcmp(temp, "+") == 0)
		{
			num1 = atof(nums->data);
			nums = nums->push(nums);
			num2 = atof(nums->data);
			nums = nums->push(nums);
			num1 = num2 + num1;
			gcvt(num1, 50, temp);
			nums = nums->pop(temp, nums);
		}
		else if (strcmp(temp, "-") == 0)
		{
			num1 = atof(nums->data);
			nums = nums->push(nums);
			num2 = atof(nums->data);
			nums = nums->push(nums);
			num1 = num2 - num1;
			gcvt(num1, 50, temp);
			nums = nums->pop(temp, nums);
		}
	}
	if (err == true)
		return NULL;
	return atof(nums->data);
}