#pragma once
#include"Global_vars.h"
#include"Input_output.h"
#include"Menu.h"

extern int index[2];
extern char* buff;
extern int input_mode;
extern int diag_mode;
extern float param1, param2;
extern float white[3];
extern float black[3];
extern int str;
extern bool printable;
extern bool confirm, build;
extern int index[2];
extern char*** table;

void test(int a, int b, int c, int d);
void input1(unsigned char key, int x, int y);