#pragma once
#include"Global_vars.h"

extern float param1, param2;

class oneSell {
protected:
	int n;
	float*tab;
public:
	oneSell();
	//~oneSell();
	virtual void set(char***, int num) = 0;
	bool num_check(char*);
	bool empty_check(char*);
	virtual void draw() = 0;
};