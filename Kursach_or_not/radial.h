#pragma once
#include"oneSell.h"

extern float colors[11][3];
extern float pi;

class radial :public oneSell {
public:
	radial();
	void set(char***mas, int num);
	void draw();
};