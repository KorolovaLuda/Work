#pragma once
#include"Global_vars.h"

extern float colors[11][3];
extern float pi;
extern float param1, param2;


class pie
{
	int n;
	float*tab;
public:
	pie();
	void set(char***, int num);
	bool num_check(char*);
	bool empty_check(char*);
	void drow();
	~pie();
};