#pragma once
#include"My_list.h"
#include<set>
#include<iterator>
#include<algorithm>
#include"Global_vars.h"

extern float param1, param2;
extern float pi;

using namespace std;

class Venn1
{
	char*sourse;
	bool*result;
	set <int>r_set;
	int n_set;
	//help
	int count_set(char*str);
	bool* choose_set(char*str);
	bool check(char*str);
public:
	Venn1();
	~Venn1();
	void parse();
	void set_set(char*);
	void drawVenDiagram();
};