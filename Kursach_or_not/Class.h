#pragma once
#include"My_list.h"

float generate(char*str,float num);

class Venn
{
	char *str = new char[100];
public:
	void del_first_char(int n);
	Venn(char*s);
	char* get_str();
	bool small_str_on_first(char*s);
	void del_char(char c);
	void change_sub_str(char*st1,char*st2);
	char* cat_num();
	void first_del(int num);
};
