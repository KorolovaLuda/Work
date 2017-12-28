#pragma once
#include"oneSell.h"

extern float colors[11][3];
extern float pi;

class pie:public oneSell {
public:
	pie();
	void set(char***, int num);
	void draw();
	//~pie();
};